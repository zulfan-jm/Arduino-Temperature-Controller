# ARDUINO TEMPERATURE CONTROLLER
    github: zulfan-jm
Temperature control system using the LM35 temperature sensor based on the Arduino is a monitoring system and automatic control of room temperature. 

# COMPONENTS
The system consists of:
   - Arduino Uno
   - LM35 sensor
   - LCD 16x2
   - I2C module
   - Relay 5V
   - Fan 12V
   - Servo SG90.

# HOW THE SYSTEM WORKS
When the system is turned on, LM35 sensor will detect the temperature. Then Arduino will compare the room temperature detected by the LM35 to the reference temperature that has been set. If the detected room temperature is greater than the reference temperature value, the Arduino will instruct the relay to turn on the servo and fan. The servo and fan will turn off if the room temperature is below the desired reference temperature.
