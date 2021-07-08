// C++ code
//
#include <Servo.h> 
#define tr 8//trigger 
#define ech 9  //echo 
#define led 10 
#define max_dis 50 // you can add more distance 
int distance=0;
int t=0;
Servo motor1 ;
Servo motor2 ;
Servo motor3 ;
Servo motor4 ;
Servo motor5 ;
Servo motor6 ;

void setup()
{
Serial.begin(9600);
delay(50);
pinMode(tr,OUTPUT);
pinMode(ech,INPUT);
pinMode(10,OUTPUT);
motor1.attach(5);
motor2.attach(6);
motor3.attach(7);
motor4.attach(11);
motor5.attach(12);
motor6.attach(13);

motor1.write(0);
motor2.write(0);
motor3.write(90);
motor4.write(0);
motor5.write(0);
motor6.write(90); // initial point for every servo
  
}

void loop()
{
  digitalWrite(tr,LOW); //for sonar 
  delayMicroseconds(5);
  digitalWrite(tr,HIGH);
  delayMicroseconds(10);
  digitalWrite(tr,LOW);
  t=pulseIn(ech,HIGH);
  distance=t/57;
  if(distance < 10 && distance > 0 ) {
    delay(3000);} //WAIT FOR 3 SECONDS FOR THE PERSON IF HE IS STILL IN FRONT OF THE ROBOT
  if(distance < 10 && distance > 0 )  //IF DISTANCE LESS THAN 10 cm FOR 3 SECONDS THEN THE VEDIO WILL PLAY AND THE ARM WILL MOVE
  {

   motor1.write(90);
   motor2.write(90);
   motor3.write(90);
   motor4.write(0);
   motor5.write(90);
   motor6.write(0);
   digitalWrite(10,HIGH);
  }
  else
  digitalWrite(10,LOW);    
  motor1.write(0);
   motor2.write(0);
   motor3.write(90);
   motor4.write(0);
   motor5.write(0);
   motor6.write(90);
}
