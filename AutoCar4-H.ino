
#include <Servo.h> 
 
Servo steeringServo;
Servo Esc;
 
int pos = 0;    
int escVal = 0;


void setup() 
{ 
  steeringServo.attach(2); 
   Esc.attach(9);
   Serial.begin(9600);
} 
 
 
void loop() 
{ 
  Esc.write(100);
  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
  {                                  // in steps of 1 degree 
    steeringServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
  {                                
    steeringServo.write(pos);              // tell servo to go to position in variable 'pos' 
    delay(15);                       // waits 15ms for the servo to reach the position 
  } 
}
