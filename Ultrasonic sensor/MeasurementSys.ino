// void setup -> for the intialization 
// void loop -> for the usage 

//this task is for measuring the distance for an obj and if the obj is in a specific range a LED will be turned on

//defineing pinnumbers 
int trig = 9;
int echo = 10; 

//defining the needed variables 
long duration;
int distance ;

void setup()
{
 pinMode(9, OUTPUT);
 pinMode(10, INPUT);
  //for the led 
 pinMode(2, OUTPUT);
  Serial.begin(9600);
}
void loop()
{
 digitalWrite(trig,LOW);//clear the trig pin first 
  delayMicroseconds(2);
  
  //step 2 : sending 10 micro second pulse
  //means turn on for 10 sec then off 
  digitalWrite(trig,HIGH);//high = 1 (send)
  delayMicroseconds(10);
  digitalWrite(trig ,LOW);
  
  //step3 calculating the duration
  // measure if there is a pulse or not and if there calclulate the duration
  duration = pulseIn(echo,HIGH, 30000); //NOTEEE ! set the time out 
 // Serial.println("Duration : "+String(duration));
  
  distance = 0.034*duration/2;
  
  //Printing to the serial mintor
  Serial.println("here is the distance : "+ String(distance));
  //delay(500); to make the led response immediatly 
 
  if(distance >= 40){
    digitalWrite(2 ,HIGH);
    Serial.println("LED IS ON");
    //delay(1000);
   // why commenting(delay) as i want the led to be on whenever the distance >= 40 
    //so there is no a specific duration and the loop will handle this also the(else) statement
  }
  else {
    digitalWrite(2 ,LOW);
    Serial.println("LED IS OFF");
    //delay(1000);
  }
  
}
