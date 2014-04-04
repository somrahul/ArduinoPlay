/* change the direction of the servo motor with input from distance sensor */
#include <Servo.h> 
 
Servo myservo;  // create servo object to control a servo 

int trigPin=11; 
int echoPin=10;
int outputValue = 0;
int pos = 0;

void setup(){
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  myservo.attach(9);
}

void loop(){
  int time;
  int distance;
  digitalWrite(trigPin,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin,LOW);
  time=pulseIn(echoPin,HIGH);
  distance=0.0340*(time/2);
  
  if(distance>=200||distance<=0){
    Serial.println("Out of range yo!");
  }
  else{
    Serial.print("\ncm");
    Serial.print(distance);
    //Serial.println(time);
  
  
  outputValue = map(distance, 0, 80, 0, 3);
  
  Serial.print("\nnewdistance");
  Serial.print(outputValue);
  
//  for(pos = 0; pos < 180; pos += 1)  // goes from 0 degrees to 180 degrees 
//  {                                  // in steps of 1 degree 
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 
//  for(pos = 180; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
//  {                                
//    myservo.write(pos);              // tell servo to go to position in variable 'pos' 
//    delay(15);                       // waits 15ms for the servo to reach the position 
//  } 
  
  switch(outputValue) {
    case 0:
      pos = 0;
      for(pos = 0; pos < 150; pos += 1)  // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
      } 
      for(pos = 150; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
      }       // waits 15ms for the servo to reach the position
      break;
    case 1:
      for(pos = 0; pos < 100; pos += 1)  // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
      } 
      for(pos = 100; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(15);                       // waits 15ms for the servo to reach the position 
      }       // 
      break;
    case 2:
      for(pos = 0; pos < 60; pos += 1)  // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(30);                       // waits 15ms for the servo to reach the position 
      } 
      for(pos = 60; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(30);                       // waits 15ms for the servo to reach the position 
      }       // 
      break;    
    case 3:
      for(pos = 0; pos < 30; pos += 1)  // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(50);                       // waits 15ms for the servo to reach the position 
      } 
      for(pos = 30; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(50);                       // waits 15ms for the servo to reach the position 
      }       //
      break;
    case 4:
      for(pos = 0; pos < 10; pos += 1)  // goes from 0 degrees to 180 degrees 
      {                                  // in steps of 1 degree 
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(100);                       // waits 15ms for the servo to reach the position 
      } 
      for(pos = 10; pos>=1; pos-=1)     // goes from 180 degrees to 0 degrees 
      {                                
        myservo.write(pos);              // tell servo to go to position in variable 'pos' 
        delay(100);                       // waits 15ms for the servo to reach the position 
      }       //
      break;
  } 
  delay(1000);
 } 
  
  //delay(500);
}

