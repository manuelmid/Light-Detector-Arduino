#include <Servo.h>

Servo servo;
int ledGreen = 12;
int ledRed = 13;
int pinLDR = 0;
int valorLDR = 0;

bool servoAbajo = true;

void setup()
{
  Serial.begin(9600);
  
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT); 
  
  servo.attach(9);
  servo.write(0);
}

void loop()
{
  valorLDR = analogRead(pinLDR);
  
  Serial.println(valorLDR);
  digitalWrite(ledRed, HIGH);

  if (valorLDR > 300) {

    digitalWrite(ledRed, LOW);

    if (servoAbajo) {
      servo.write(90);
      servoAbajo = false;
      digitalWrite(ledGreen, HIGH);
    } 

  } else {

    servoAbajo = true;
  	servo.write(0);
    digitalWrite(ledGreen, LOW);
    
  }
  
  delay(500);
}