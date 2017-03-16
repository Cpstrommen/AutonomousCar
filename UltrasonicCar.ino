
//including libraries

#include <Adafruit_NeoPixel.h>
#include <Servo.h>

Servo panServo;  // create servo object to control a servo

//---------NEOPIXEL STUFF-----------------

// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            6

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      12

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


//-------------VARIABLES---------------------------------------------------------------------------------------

int pos = 90;
const int trigPin = 2;
const int echoPin = 4;

//VARIABLES FOR OUTBPUT DATA **ALL UNITS ARE CM**

int dis0 = 0;
int dis7 = 0;
int dis14 = 0;

int dis15 = 0;
int dis22 = 0;
int dis29 = 0;

int dis30 = 0;
int dis37 = 0;
int dis44 = 0;

int dis45 = 0;
int dis52 = 0;
int dis59 = 0;

int dis60 = 0;
int dis67 = 0;
int dis74 = 0;

int dis75 = 0;
int dis82 = 0;
int dis89 = 0;

int dis90 = 0;
int dis98 = 0;
int dis104 = 0;

int dis105 = 0;
int dis113 = 0;
int dis119 = 0;

int dis120 = 0;
int dis128 = 0;
int dis134 = 0;

int dis135 = 0;
int dis143 = 0;
int dis149 = 0;

int dis150 = 0;
int dis158 = 0;
int dis164 = 0;

int dis165 = 0;
int dis173 = 0;
int dis180 = 0;

//VARIABLES FOR SECTION AVERAGES (ALL UNITS IN CM)

int sectionadd1 = 0;
int sectionadd2 = 0;
int sectionadd3 = 0;
int sectionadd4 = 0;
int sectionadd5 = 0;
int sectionadd6 = 0;
int sectionadd7 = 0;
int sectionadd8 = 0;
int sectionadd9 = 0;
int sectionadd10 = 0;
int sectionadd11 = 0;
int sectionadd12 = 0;

float section1 = 0;
float section2 = 0;
float section3 = 0;
float section4 = 0;
float section5 = 0;
float section6 = 0;
float section7 = 0;
float section8 = 0;
float section9 = 0;
float section10 = 0;
float section11 = 0;
float section12 = 0;

//NEOPIXEL TUNING VARIABLE (CM)

const int pixelLong = 1000;
const int pixelShort = 200;

//ULTRASONIC SETUP STUFF

long microsecondsToInches(long microseconds)
{
  // According to Parallax's datasheet for the PING))), there are
  // 73.746 microseconds per inch (i.e. sound travels at 1130 feet per
  // second).  This gives the distance travelled by the ping, outbound
  // and return, so we divide by 2 to get the distance of the obstacle.
  // See: http://www.parallax.com/dl/docs/prod/acc/28015-PING-v1.3.pdf
  return microseconds / 74 / 2;
}

long microsecondsToCentimeters(long microseconds)
{
  // The speed of sound is 340 m/s or 29 microseconds per centimeter.
  // The ping travels out and back, so to find the distance of the
  // object we take half of the distance travelled.
  return microseconds / 29 / 2;
}

//-----------------------------------------------------------------------------------------------------------

void setup() {
  
  //SERVO STUFF
  panServo.attach(9);  // attaches the servo on pin 9 to the servo object
  
  //NEOPIXEL STUFF
  pixels.begin(); // This initializes the NeoPixel library.

  //SERIAL MONITOR
  Serial.begin(9600); //serial communication to PC
  
}



void loop() {

  //PAN SERVO CODE START

  //----------FORWARD SWEEP-----------------------------------------------------------------

  for (pos = 0; pos <= 180; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    panServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);    // waits 15ms for the servo to reach the position
    
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
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.println();
  Serial.print("Servo Position:");
  Serial.print(pos);
  Serial.println();

  delay(10);

  //ULTRASONIC CODE END
  
  
  }
  
  //-----------------------REVERSE SWEEP--------------------------------------------------------- 
  
  for (pos = 180; pos >= 0; pos -= 1) { // goes from 180 degrees to 0 degrees
    panServo.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);     // waits 15ms for the servo to reach the position
    
    
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
  inches = microsecondsToInches(duration);
  cm = microsecondsToCentimeters(duration);
  
  Serial.print(inches);
  Serial.print("in, ");
  Serial.print(cm);
  Serial.print("cm");
  Serial.print("Servo Position:");
  Serial.print(pos);
  Serial.println();

  delay(10);

  //ULTRASONIC CODE END
  
  
  }

  //PAN SERVO CODE END

  
  
  //-------------DATA ANALYSIS--------------------------------------------------
  
  if (pos == 0) {
    cm = dis0;
  }
  if (pos == 7) {
    cm = dis7;
  }
  if (pos == 14) {
    cm = dis14;
  }
  if (pos == 15) {
    cm = dis15;
  }
  if (pos == 22) {
    cm = dis22;
  }
  if (pos == 29) {
    cm = dis29;
  }
  if (pos == 30) {
    cm = dis30;
  }
  if (pos == 37) {
    cm = dis37;
  }
  if (pos == 44) {
    cm = dis44;
  }
  if (pos == 45) {
    cm = dis45;
  }
  if (pos == 52) {
    cm = dis52;
  }
  if (pos == 59) {
    cm = dis59;
  }
  if (pos == 60) {
    cm = dis60;
  }
  if (pos == 67) {
    cm = dis67;
  }
  if (pos == 74) {
    cm = dis74;
  }
  if (pos == 75) {
    cm = dis75;
  }
  if (pos == 82) {
    cm = dis82;
  }
  if (pos == 89) {
    cm = dis89;
  }
  if (pos == 90) {
    cm = dis90;
  }
  if (pos == 98) {
    cm = dis98;
  }
  if (pos == 104) {
    cm = dis104;
  }
  if (pos == 105) {
    cm = dis105;
  }
  if (pos == 113) {
    cm = dis113
  }
  if (pos == 119) {
    cm = dis119;
  }
  if (pos == 120) {
    cm = dis120;
  }
  if (pos == 128) {
    cm = dis128;
  }
  if (pos == 134) {
    cm = dis134;
  }
  if (pos == 135) {
    cm = dis135;
  }
  if (pos == 143) {
    cm = dis143;
  }
  if (pos == 149) {
    cm = dis149;
  }
  if (pos == 150) {
    cm = dis150;
  }
  if (pos == 158) {
    cm = dis158;
  }
  if (pos == 164) {
    cm = dis164;
  }
  if (pos == 165) {
    cm = dis165;
  }
  if (pos == 173) {
    cm = dis173;
  }
  if (pos == 180) {
    cm = dis180;
  }
  
  //----------END OF WRITING TO DISTANCE VARIABLES--------------------------------
  
  //----------COLLECTING SECTION DATA---------------------------------------------
  
  sectionadd1 = dis0 + dis7 + dis14; //distances 0-14
  section1 = sectionadd1 / 3;
  
  sectionadd2 = dis15 + dis22 + dis29; //distances 15-29
  section2 = sectionadd2 / 3;
  
  sectionadd3 = dis30 + dis37 + dis44; //distances 30-44
  section3 = sectionadd3 / 3;
  
  sectionadd4 = dis45 + dis52 + dis59; //distances 45-59
  section4 = sectionadd4 / 3;
  
  sectionadd5 = dis60 + dis67 + dis74; //distances 60-74
  section5 = sectionadd5 / 3;
  
  sectionadd6 = dis75 + dis82 + dis89; //distances 75-89
  section6 = sectionadd6 / 3;
  
  sectionadd7 = dis90 + dis98 + dis104; //distances 90-104
  section7 = sectionadd7 / 3;
  
  sectionadd8 = dis105 + dis113 + dis119; //distances 105-119
  section8 = sectionadd8 / 3;
  
  sectionadd9 = dis120 + dis128 + dis134; //distances 120-134
  section9 = sectionadd9 / 3;
  
  sectionadd10 = dis135 + dis143 + dis149; //distances 135-149
  section10 = sectionadd10 / 3;
  
  sectionadd11 = dis150 + dis158 + dis164; //distances 150-164
  section11 = sectionadd11 / 3;
  
  sectionadd12 = dis165 + dis173 + dis180; //distances 165-180
  section12 = sectionadd12 / 3;
  
  //---------WRITING TO THE NEOPIXELS---------------

  if (section1 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(1, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section2 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(2, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section3 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(3, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section4 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(4, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section5 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(5, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section6 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(6, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section7 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(7, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section8 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(8, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section9 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(9, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section10 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(10, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section11 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(11, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  if (section12 <= pixelShort) {
     // pixels.Color takes RGB values, from 0,0,0 up to 255,255,255
    pixels.setPixelColor(12, pixels.Color(255,0,0)); 
    pixels.show(); 
  }
  


  

}


