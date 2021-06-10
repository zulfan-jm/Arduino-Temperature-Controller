/* ARDUINO TEMPERATURE CONTROLLER
     github: zulfan-jm
   Temperature control system using the LM35 temperature sensor 
   based on the Arduino is a monitoring system and automatic control 
   of room temperature. 
   The system consists of:
   - Arduino Uno
   - LM35 sensor
   - LCD 16x2
   - I2C module
   - Relay 5V
   - Fan 12V
   - Servo SG90.
    
   When the system is turned on, LM35 sensor will detect the temperature. 
   Then Arduino will compare the room temperature detected by the LM35 
   to the reference temperature that has been set. 
   If the detected room temperature is greater than the reference temperature value, 
   the Arduino will instruct the relay to turn on the servo and fan. 
   The servo and fan will turn off if the room temperature is below 
   the desired reference temperature. */

#include <LiquidCrystal_I2C.h>  // LCD library
#include <Wire.h>               // I2C library
#include <Servo.h>              // Servo library

Servo myservo;

const int sensorPin = A0; // LM35 sensor pin
int fanPin = 2;           // fan pin

float tempC = 0;  // Temperature value in Celcius
int temp = 0;     // Temperature value from LM35
int tempRef = 30; // Temperature reference value
int pos = 0;      // Servo rotation degree

LiquidCrystal_I2C lcd(0x27, 16, 2);

void setup() {
  Serial.begin(9600);
  Wire.begin();
  lcd.begin(16, 2);
  lcd.init();
  lcd.backlight();

  myservo.attach(9);
  pinMode(sensorPin, INPUT);
  pinMode(fanPin, OUTPUT);

  lcd.setCursor(0, 0);
  lcd.print("Temperature");
  lcd.setCursor(0, 1);
  lcd.print("Controller");
  delay(2000);
  lcd.clear();
}

void loop() {
  temp = analogRead(sensorPin);
  tempC = (temp) * (0.4848);    // Convert LM35 data to Celsius
  lcd.setCursor(0, 0);
  lcd.print("Temp: ");
  lcd.print(tempC);
  lcd.print(" C");
  Serial.print("Temp: ");
  Serial.print(tempC);
  Serial.print(" C\r");

  if (tempC >= tempRef) {
    digitalWrite(fanPin, HIGH);           // Fan turned on
    for (pos = 0; pos <= 60; pos += 1) {  // Servo rotates 60 degrees
      myservo.write(pos);
      delay(1);
    }
  } else if (tempC < tempRef) {
    digitalWrite(fanPin, LOW);            // Fan turned off
    for (pos = 60; pos >= 0; pos -= 1) {  // Servo rotates to 0 degrees again
      myservo.write(pos);
      delay(1);
    }
  }
}
