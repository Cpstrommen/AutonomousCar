/** Code By Christian Strommen
 *  
 *  Pin Connections:
 *  Pan servo signal wire: digital port 9
 *  Ultrasonic sensor trig wire: digital port 2
 *  Ultrasonic sensor echo pin: digital port 4
 *  Steering servo signal wire: digital port 10
 *  
 */

#include <Servo.h>

Servo panServo; 
Servo steeringServo;

//variables

int pos = 90;
const int trigPin = 2;
const int echoPin = 4;
long duration, cm;
int dis0, dis45, dis90, dis135, dis180;

//adjustable variables

const int panDelay = 10;
int turnDis = 150; //cm
int steeringPos = 45;
int steeringSpeed = 2;
const int steeringDelay = 5;
const int steeringCenter = 45;

//ultrasonic conversions

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}
long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}


void setup() {
  panServo.attach(9);
  steeringServo.attach(10);
  Serial.begin(9600); //serial communication to PC
}


void loop() {

  panServo.write(90);

  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);
  dis90 = microsecondsToCentimeters(duration);
  Serial.print(pos);
  Serial.print(",");
  Serial.print(dis90);
  Serial.println();

    if (dis90 <= turnDis) {
  
      panServo.write(0); //checking to the right
  
      pinMode(trigPin, OUTPUT);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
      dis0 = microsecondsToCentimeters(duration);
      Serial.print(pos);
      Serial.print(",");
      Serial.print(dis0);
      Serial.println();
  
      panServo.write(180); //checking to the left
  
      pinMode(trigPin, OUTPUT);
      digitalWrite(trigPin, LOW);
      delayMicroseconds(2);
      digitalWrite(trigPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trigPin, LOW);
      pinMode(echoPin, INPUT);
      duration = pulseIn(echoPin, HIGH);
      dis180 = microsecondsToCentimeters(duration);
      Serial.print(pos);
      Serial.print(",");
      Serial.print(dis180);
      Serial.println();
  
      if (dis0 >= dis180) {
        for (steeringPos = 45; steeringPos <=90; steeringPos += steeringSpeed) {
          steeringServo.write(steeringPos);
          delay(steeringDelay);
        }
        for (steeringPos = 90; steeringPos >=45; steeringPos -= steeringSpeed){
          steeringServo.write(90);
          delay(steeringDelay);
        }
      }
      if (dis0 < dis180) {
         for (steeringPos = 45; steeringPos >=0; steeringPos -= steeringSpeed) {
          steeringServo.write(steeringPos);
          delay(steeringDelay);
        }
        for (steeringPos = 0; steeringPos <=45; steeringPos += steeringSpeed){
          steeringServo.write(steeringPos);
          delay(steeringDelay);
        }
      } 
   }
   if (dis90 > turnDis) {
    steeringServo.write(steeringCenter);
   }
}  
