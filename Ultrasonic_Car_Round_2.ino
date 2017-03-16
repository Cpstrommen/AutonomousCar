
//including libraries

#include <Servo.h>

Servo panServo;  // create servo object to control a servo

//---------NEOPIXEL STUFF-----------------


//-------------VARIABLES---------------------------------------------------------------------------------------

int pos = 90;
const int trigPin = 2;
const int echoPin = 4;

const int panSpeed = 1;
const int extraDelay = 10;


//ULTRASONIC SETUP STUFF

long microsecondsToInches(long microseconds)
{
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  return microseconds / 29 / 2;
}

//-----------------------------------------------------------------------------------------------------------

void setup() {
  
  //SERVO STUFF
  panServo.attach(9);  // attaches the servo on pin 9 to the servo object

  //SERIAL MONITOR
  Serial.begin(9600); //serial communication to PC
  
}



void loop() {

   
  //PAN SERVO CODE START

  //----------FORWARD SWEEP-----------------------------------------------------------------

  for (pos = 0; pos <= 180; pos += panSpeed) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    panServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(extraDelay);    // waits 15ms for the servo to reach the position
    
    //ULTRASONIC CODE START

   // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance
  cm = microsecondsToCentimeters(duration);
  Serial.print(pos);
  Serial.print(",");
  Serial.print(cm);
  Serial.print(".");


  //ULTRASONIC CODE END
  
  
  }
  
  //-----------------------REVERSE SWEEP--------------------------------------------------------- 
  
  for (pos = 180; pos >= 0; pos -= panSpeed) { // goes from 180 degrees to 0 degrees
    panServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(extraDelay);     // waits 15ms for the servo to reach the position
    
    
    //ULTRASONIC CODE START

   // establish variables for duration of the ping, 
  // and the distance result in inches and centimeters:
  long duration, inches, cm;

  // The sensor is triggered by a HIGH pulse of 10 or more microseconds.
  // Give a short LOW pulse beforehand to ensure a clean HIGH pulse:
  pinMode(trigPin, OUTPUT);
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  // Read the signal from the sensor: a HIGH pulse whose
  // duration is the time (in microseconds) from the sending
  // of the ping to the reception of its echo off of an object.
  pinMode(echoPin, INPUT);
  duration = pulseIn(echoPin, HIGH);

  // convert the time into a distance

  cm = microsecondsToCentimeters(duration);
  

  Serial.print(pos);
  Serial.print(",");
  Serial.print(cm);
  Serial.print(".");


 
  
  }



  
  
  
}


