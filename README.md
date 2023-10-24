# Sensor_network
This project aims to get the gps location of flee trucks and send it to the respective phone number and also store it as database using mysql in PHP myadmin 
# GPS Data Logging and MySQL Integration

This project involves logging GPS data from a connected device using Python, and then integrating this data with a MySQL database for storage and analysis.

## Project Overview

This Python script reads GPS data from a connected device, formats it, and logs it to a CSV file. Additionally, the data is parsed and integrated with a MySQL database for further processing.

## Requirements

- Python 3.x
- `pandas` library for data handling
- `serial` library for serial communication
- `mysql-connector-python` for MySQL integration

## Setup

1. Ensure you have the necessary Python packages installed:

```bash
pip install pandas
pip install pyserial
pip install mysql-connector-python
```

2. Connect your GPS device via a serial port to your computer.

3. Modify the following variables in the script:

   - `fileName`: The name of the CSV file to log GPS data.
   - `host`: MySQL host address.
   - `port`: MySQL port (usually 3306).
   - `user`: MySQL username.
   - `password`: MySQL password.
   - `database`: Name of the MySQL database.

## Running the Script

1. Run the Python script:

```bash
python gps_data_logger.py
```

2. Select the COM port where your GPS device is connected.

## Notes

- Ensure that your MySQL server is running and accessible.
- The script will continuously read GPS data and log it to both the CSV file and the MySQL database.

## CSV Data

The CSV file (`gps_data.csv`) contains the following columns:

- `Timestamp`: Date and time of the GPS data.
- `Latitude`: Latitude coordinates.
- `Longitude`: Longitude coordinates.
- `Satellite Number`: Number of satellites.
- `GPS Hour`, `GPS Minute`, `GPS Second`: Time from GPS data.
- `GPS Year`, `GPS Month`, `GPS Day`: Date from GPS data.

## MySQL Database

The MySQL table `gps` stores the following information:

- `date`: Current date.
- `time`: Current time.
- `latitude`: Latitude coordinates.
- `longitude`: Longitude coordinates.
- `sat_num`: Number of satellites.
- `gps_hour`, `gps_min`, `gps_sec`: Time from GPS data.
- `gps_year`, `gps_month`, `gps_day`: Date from GPS data.

Feel free to reach out if you have any questions or need further assistance with this project. Happy coding!
