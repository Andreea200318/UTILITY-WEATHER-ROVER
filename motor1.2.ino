#include <AFMotor.h>
#include <NewPing.h>
#include <Servo.h>

#define TRIG_PIN A0 
#define ECHO_PIN A1 


NewPing sonar(TRIG_PIN, ECHO_PIN, MAX_DISTANCE); 

AF_DCMotor motor1(1, MOTOR12_1KHZ); 
AF_DCMotor motor2(2, MOTOR12_1KHZ);
AF_DCMotor motor3(3, MOTOR34_1KHZ);
AF_DCMotor motor4(4, MOTOR34_1KHZ);
Servo myservo;   



int distance = 100;
int speedSet = 0;
int incomingByte;
char val;

void setup() {

  Serial.begin(9600);
  myservo.attach(10);  
  myservo.write(115); 
  
}

void loop() {
  if (Serial.available() > 0) {
    incomingByte = Serial.read();
   if (incomingByte == 'W' || incomingByte == 'w')
{
   
    motor1.run(FORWARD);      
    motor2.run(FORWARD);
    motor3.run(FORWARD);
    motor4.run(FORWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}
if (incomingByte == 'X' || incomingByte == 'x')
{
  motor1.run(RELEASE); 
  motor2.run(RELEASE);
  motor3.run(RELEASE);
  motor4.run(RELEASE);
}


if (incomingByte == 'A' || incomingByte == 'a') {
  motor1.run(BACKWARD);     
  motor2.run(BACKWARD);  
  motor3.run(FORWARD);
  motor4.run(FORWARD);   
  delay(500);
  
}

if (incomingByte == 'D' || incomingByte == 'd')
{
  motor1.run(FORWARD);
  motor2.run(FORWARD);
  motor3.run(BACKWARD);
  motor4.run(BACKWARD);     
  delay(500);
}

if (incomingByte == 'S' || incomingByte == 's')
{
   
    motor1.run(BACKWARD);      
    motor2.run(BACKWARD);
    motor3.run(BACKWARD);
    motor4.run(BACKWARD);  
  for (speedSet = 0; speedSet < MAX_SPEED; speedSet +=2) 
  {
    motor1.setSpeed(speedSet);
    motor2.setSpeed(speedSet);
    motor3.setSpeed(speedSet);
    motor4.setSpeed(speedSet);
    delay(5);
  }
}

  }
  }
  



  
