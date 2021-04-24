#include <Servo.h>
#include <NewPing.h>   
const char in1 = 8;
const char in2 = 9;
const char in3 = 10;
const char in4 = 11;
#define trig_pin A0 //analog input 1
#define echo_pin A1 //analog input 2

#define maximum_distance 200
boolean goesForward = false;
int distance = 100;
NewPing sonar(trig_pin, echo_pin, maximum_distance); //sensor function
Servo myservo;  // create servo object to control a servo
// twelve servo objects can be created on most boards
int pos = 0;
void setup() {
   myservo.attach(5);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  pinMode(in3, OUTPUT);
  pinMode(in4, OUTPUT);
  myservo.write(115);
  delay(2000);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
  distance = readPing();
  delay(100);
}

void loop() {
  int distanceRight = 0;
  int distanceLeft = 0;
  delay(50);

  if (distance <= 20){
    arret();
    delay(300);
    arriere();
    delay(400);
    arret();
    delay(300);
    distanceRight = lookRight();
    delay(300);
    distanceLeft = lookLeft();
    delay(300);

    if (distance >= distanceLeft){
      droite();
      arret();
    }
    else{
      gauche();
      arret();
    }
  }
  else{
    avant(); 
  }
    distance = readPing();
    }   

int lookRight(){  
  myservo.write(50);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
}

int lookLeft(){
  myservo.write(170);
  delay(500);
  int distance = readPing();
  delay(100);
  myservo.write(115);
  return distance;
  delay(100);
}

int readPing(){
  delay(70);
  int cm = sonar.ping_cm();
  if (cm==0){
    cm=250;
  }
  return cm;
}
    
void arriere()
{
  if(!goesForward){

    goesForward=true;
    digitalWrite(in1,LOW); 
    digitalWrite(in2, HIGH);
    digitalWrite(in3,LOW); 
    digitalWrite(in4, HIGH);  }
}
void avant()
{
  goesForward=false;
  digitalWrite(in1,HIGH); 
  digitalWrite(in2, LOW);
  digitalWrite(in3,HIGH); 
  digitalWrite(in4, LOW);
}
void gauche()
{
  digitalWrite(in1,LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3,LOW); 
  digitalWrite(in4, LOW);  
  delay(500);
  digitalWrite(in1,LOW); 
  digitalWrite(in2, HIGH);
  digitalWrite(in3,LOW); 
  digitalWrite(in4, LOW); 
}
void droite()
{
  digitalWrite(in1,LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3,LOW); 
  digitalWrite(in4, HIGH);
  delay(500);
  digitalWrite(in1,LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3,LOW); 
  digitalWrite(in4, HIGH);
}
void arret()
{
  digitalWrite(in1,LOW); 
  digitalWrite(in2, LOW);
  digitalWrite(in3,LOW); 
  digitalWrite(in4, LOW);  
}
