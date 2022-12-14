import serial.tools.list_ports
import serial
import pandas as pd
import csv

import mysql.connector




from datetime import datetime
fileName="gps_data.csv"

ports = serial.tools.list_ports.comports()
serialInst = serial.Serial()

print("Created file")

portsList = []

for onePort in ports:
    portsList.append(str(onePort))
    print(str(onePort))

val = input("Select Port: COM")

for x in range(0,len(portsList)):
    if portsList[x].startswith("COM" + str(val)):
        portVar = "COM" + str(val)
        print(portVar)

serialInst.baudrate = 9600
serialInst.port = portVar
serialInst.open()

conn = mysql.connector.connect(
            host="34.90.53.188", port="3306",
            user="admin", password="sensor",
            database="sensor"
            )
mycursor = conn.cursor()
"""while True:
	if serialInst.in_waiting:
		packet = serialInst.readline()
		print(packet.decode('utf').rstrip('\n'))"""

file = open(fileName, "a")
while True:

    getData=serialInst.readline()
    dataString = getData.decode('utf-8')
    print(dataString)
    file.write(f"{datetime.now().strftime('%Y-%m-%d:%H-%M-%S')}:{dataString}\n")



    latitude, longitude,satellite, gps_hour, gps_min, gps_sec, gps_year, gps_month, gps_day = dataString.split(sep=":")
    query = (
        f"INSERT INTO gps (date, time, latitude, longitude,sat_num, gps_hour, gps_min, gps_sec, gps_year, gps_month, gps_day) "
        f"VALUES (CURRENT_DATE(), CURRENT_TIME(), {latitude}, {longitude},{satellite},{gps_hour}, {gps_min}, {gps_sec}, {gps_year}, {gps_month}, {gps_day});")
    query = mycursor.execute(query)
    conn.commit()
file.close()

df = pd.read_csv("gps_data.csv")
print(df)



