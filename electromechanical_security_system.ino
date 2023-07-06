#include <SoftwareSerial.h>
#include<XBee.h>
SoftwareSerial XBee (0,1);
char A[] = {'O','N'};
int ran;
char temp;
int ledPin = 4;                // Pin LED is connected to
int piezoBuzzerPin = 3;     // Pin Piezo Buzzer is connected to
int pirSensorPin = 2;               // PIN PIR Sensor is connected to
int motionDetected = LOW;             // Start MotionDetected as low (No motion detected)

void setup() 
{
  pinMode(ledPin, OUTPUT);      // declare LED as output
  pinMode(pirSensorPin, INPUT);     // declare the PIR sensor as input
  pinMode(piezoBuzzerPin, OUTPUT); //declare buzzer as output
  XBee.begin(9600);
  Serial.begin(9600); //Set serial out if we want debugging
  Serial.println("Starting system process....");
  delay(10000); //Allow time for the PIR Sensor to calibrate
}

void loop()
{
  motionDetected = digitalRead(pirSensorPin);  // Read the PIR sensor
  if(motionDetected == HIGH) //If motion detected
  {           
    digitalWrite(ledPin, HIGH);
    analogWrite(piezoBuzzerPin, 200);
    delay(100);
    digitalWrite(ledPin, LOW);
    analogWrite(piezoBuzzerPin, 25);
    delay(100);
    ran = random(0,1);
    temp = A[ran];
    if(Serial.available())
    {
      Serial.write(temp);
      delay(1000);
    }
  }
  else
  {
  digitalWrite(ledPin, LOW);
  analogWrite(piezoBuzzerPin,LOW);
  }
}

