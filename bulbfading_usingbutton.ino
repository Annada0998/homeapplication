#include <Blynk.h>
#define BLYNK_PRINT Serial    // Comment this out to disable prints and save space


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
int flag=0;


void setup() {
  // put your setup code here, to run once:
Serial.begin(9600);
pinMode(9,OUTPUT);
Blynk.begin(auth,ssid,pass);
}

BLYNK_WRITE(V1)
{
  int i;
  i=param.asInt();
  if(i==1)
  flag=1;
}

BLYNK_WRITE(V0)
{
  
  int i;
  i= param.asInt();
  if(flag==1)  
  analogWrite(9,i);
  else
  analogWrite(9,LOW);
  Serial.print(i);
  Serial.println();
}


void loop() {
  // put your main code here, to run repeatedly:
Blynk.run();
  
}
