#include <Blynk.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space
#include "RTClib.h"
RTC_Millis RTC;

#include <SPI.h>
#include <WiFi.h>
//#include <BlynkSimpleTI_CC3200_LaunchXL.h>
#include <BlynkSimpleEnergiaWiFi.h>" 
#include <Wire.h>


// You should get Auth Token in the Blynk App.
// Go to the Project Settings (nut icon).
char auth[] = "52e2738c640845599b70a6b304f8aa69";


// Your WiFi credentials
char ssid[] = "Lenovo K6 POWER";
char pass[] = "f731570ec78b";        //
int i=30;
int j=0;
DateTime now;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9,OUTPUT);
Blynk.begin(auth,ssid,pass);
RTC.begin(DateTime(__DATE__, __TIME__));
}

BLYNK_WRITE(V1)
{
  j=param.asInt();
  Serial.print("Value of j is");
    Serial.print(j);
    Serial.println();
}


BLYNK_WRITE(V0)
{
  
i=param.asInt();
Serial.print(i);
    Serial.println();
 }

void light()
{
 if(j==1)
  {
    analogWrite(9,i);
    Serial.print(i);
    Serial.println();
  }
  else
  analogWrite(9,LOW);
}

void time_display()
{
  now = RTC.now();
Serial.print(now.year(), DEC);
Serial.print('/');
Serial.print(now.month(), DEC);
Serial.print('/');
Serial.print(now.day(), DEC);
Serial.print(' ');
Serial.print(now.hour(), DEC);
Serial.print(':');
Serial.print(now.minute(), DEC);
Serial.print(':');
Serial.print(now.second(), DEC);
Serial.println();
delay(1000);
}
void loop() {
  // put your main code here, to run repeatedly:
if(now.hour()==10 && now.minute()>=44 && now.minute()<=45)
{
  do{
analogWrite(9,LOW);
Blynk.virtualWrite(V1,LOW);
}while(j!=1);
}
else
{
Blynk.run();
light();
Serial.print("Blynk is working.");
}
time_display();
}

