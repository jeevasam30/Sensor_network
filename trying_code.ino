#include <TinyGPS++.h>
#include <SoftwareSerial.h>

TinyGPSPlus gps;
SoftwareSerial sgps(3,4);
SoftwareSerial gsm(7,8);                      // rx,tx The serial connection to the GPS device
float latitude , longitude;
int year , month , date, hour , minute , second;
String date_str , time_str , lat_str , lng_str;
int pm;


void setup()
{
  Serial.begin(9600);
  sgps.begin(9600);
  gsm.begin(9600);
  gsm.println("AT");//Handshaking with SIM900
  gsm.println("AT+CMGF=1"); // Configuring TEXT mode
  //Serial.println(sgps.available());
  
}

void loop()

{ 
  sgps.listen();
  //Serial.println(sgps.available());
  while(sgps.available() > 0)
  
    if (gps.encode(sgps.read()))
    {
      if (gps.location.isValid())
      //{
        latitude = gps.location.lat();
        lat_str = String(latitude , 6);
        longitude = gps.location.lng();
        lng_str = String(longitude , 6);
        Serial.print(lat_str);
       
        Serial.print(':');
        
        Serial.print(lng_str);
        Serial.print(':');
    
      //}
      /*
      else {
        Serial.print('x');
       
        Serial.print(':');
        
        Serial.print('x');
         Serial.print(':');
      }*/
   
      //Serial.println(lng_str);Serial.println(lat_str);
      Serial.print(gps.satellites.value());
      Serial.print(':');
       //if(gps.time.isUpdated()) 
  //{
    //Serial.println("Time has been updated");
    //Serial.print("Satellites: ");
    
   
    //Serial.print("Time now [GMT]:  ");
    Serial.print(gps.time.hour());
    Serial.print(":");
    Serial.print(gps.time.minute());
    Serial.print(":");
    Serial.print(gps.time.second());
    Serial.print(':');
  //}
  /*
  else {
    
    //Serial.print("Time now [GMT]:  ");
    Serial.print('x');
    Serial.print(":");
    Serial.print('x');
    Serial.print(":");
    Serial.print('x');
    Serial.print(':');
  }*/
    

    //if (gps.date.isValid())
    //{
      //Serial.print("  Date:  ");
      Serial.print(gps.date.year());
      Serial.print(":");
      //Serial.print("/");
      Serial.print(gps.date.month());
      Serial.print(":");
      //Serial.print("/");
      Serial.print(gps.date.day());
      //Serial.print(":");
    //}
    /*
    else {
      Serial.print('x');
      Serial.print(":");
      //Serial.print("/");
      Serial.print('x');
      Serial.print(":");
      //Serial.print("/");
      Serial.print('x');
      Serial.print(":");
    }*/
    Serial.print('\n');
      

      
     // Serial.println("Initializing..."); 
     
      
      
       //Handshaking with SIM900
      
     //updateSerial();
     
    
 
      //gsm.println("AT+CMGF=1"); // Configuring TEXT mode
      //updateSerial();
      gsm.println("AT+CMGS=\"+4915223803671\"");//change ZZ with country code and xxxxxxxxxxx with phone number to sms
      updateSerial();
      gsm.print("latitude :" + lat_str+ ","+ "longitude :" + lng_str); //text content
      //Serial.println("latitude :" + lat_str+ ","+ "longitude :" + lng_str);
       gsm.print("https://www.google.com/maps/@");
       gsm.print(lat_str);
       //gsm.println("53.46");
       gsm.print(',');
       gsm.print(lng_str);
       //gsm.println("8.67");
       gsm.print(",20z");
      updateSerial();
      gsm.write(26);
      }
  
  delay(1000);
}
void updateSerial()
{
  delay(500);
  while (Serial.available()) 
  {
    gsm.write(Serial.read());//Forward what Serial received to Software Serial Port
  }
  while(gsm.available()) 
  {
    Serial.write(gsm.read());//Forward what Software Serial received to Serial Port
  }
}
