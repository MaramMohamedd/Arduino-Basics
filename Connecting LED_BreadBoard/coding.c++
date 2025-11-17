// void setup -> for the intialization 
// void loop -> for the usage 

void setup()
{
  pinMode(13 , OUTPUT); //for choosing
  //1- which pin
  //2- used for sending a signal (OUTPUT)
  // or rececving a signal (INPUT)
  //HERE i want to send a singal to the LED -> OUTPUT

}
void loop()
{
  digitalWrite(13 , HIGH);
  //write -> sending output and the 
  delay(3000);// wait for 3 sec before moving to the second line/command  
  digitalWrite(13 , LOW);
  delay(3000); // if i didn't make this delay the led will be turned off
  //for less than 1 sec or even less and the second command which is turning on 
  //will immediatly be excuted as iam in an infinite loop so i will not notice 
  //that the led will be turned of as a human but it is actually turned off
  //NOTEE (the loop() function = infinity loop)
}
