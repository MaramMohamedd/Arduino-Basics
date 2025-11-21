# Coding tips 
we have a Two main important functions setup() , loop() .

# 1- void setup()
used for intialization , ex) intializing the job of each pin (INPUT , OUTPUT..etc)
runs only once when the Arduino starts or is reset .

### ex)pinMode(number , OUTPUT)
```
int ledpin = 2;
void setup () {
pinMode(ledpin , OUTPUT) ; //means iam telling the Arduino that pin 2 -> ledpin and its job (output) means in the loop you will give an order to the led (high = turn on , low = turn of)
}
```

### ex) pinMode(number , INPUT)
```
ultrasonic_sensor_echo_pin = 9;
void setup () {
pinMode(ledpin , INPUT) ;//means iam telling the Arduino that pin 9 -> echo pin and its job (INPUT) means receives the signal this pin takes an input and returns the duration through pulseIn() 
}
```

# Serial Monitor
it is like the terminal in VS code , it starts communication between Arduino and your computer
### Most common usage 
```
Serial.begin(9600);
Serial.println(""); //Send message to computer with new line 
Serial.print("");//Send message to computer witout a new line
```
```
void setup() {
Serial.begin(9600); //9600 is the speed of the communication
Serial.println("HELLO FROM SETUP FUNCTION");
} 
```

# 2- void loop() 
infinite loop runs forever without stopping it has the logic , conditions , orders that i give to the pins ..etc
### Some importantttt functions 
### digitalWrite();
it is used for DIGITAL OUTPUTS means turn on , turn off 
ex) turn on , off ->  the led , buzzer , trig pin to send a signal 
```
void loop()
{
digitalWrtie(LED_PIN , HIGH); // means turn on the led 
digitalWrtie(LED_PIN, LOW); // turn off the led 
}
```
#### Problem about this code ?
The sequence happens too fast:
1, Turn ON LED
2. Turn OFF LED (instantly)
3. Repeat forever
what actually we see in the real life that the led  will always be turned on remeber that the loop will be repeated infinitly 

#### why ?
we didn't specify how long each command should execute. The OFF command happens immediately after ON (in microseconds)

### Solution ?
## delay() ; Function 
```delay()``` tells Arduino how long to wait before executing the next command. Time is in milliseconds (1 sec = 1000 ms).
, so delay(1000); means make the command lasts for 1 sec then go to the next one

ex) 
```
digitalWrite(led_pin , HIGH);
delay(3000); // means turn on the led for 3 seconds then go to the next command
digitalWrite(led_pin , LOW);
delay(2000); // means turn on the led for 2 seconds then go to the next command which is "turning on the led" as iam in a loop() 
}
```
### Tinker example 
https://www.tinkercad.com/things/fsgDCvlROLu/editel?returnTo=%2Fdashboard%2Fdesigns%2Fall&sharecode=mkY8ZeWEmpBkE5SJPmASi7C48AwFpXEG-0Puop6m-PU

try it yourself try to comment the delay function and see the difference 

### when to remove it ?
when you need immediate response to changing conditions.
means if i want somehting to be excuted as long as another something happens , (i don't know for how long this action will last)

ex) make the led on whenever the manual mode is on 
```
if (manual_mode == true){
digitalWrite(led_pin , HIGH);
}
else {
digitalWrite(led_pin , LOW);
}// here : the else part will be nesseccary as i want the led to be on onlyyyy when the manual mode is on else make it off
// if i didn't write "else" the once the "digitalWrite(led_pin , HIGH);" is excuted , it will last forever because of the infinite loop effect 
```
# digitalRead();
it reads if a digital pin is HIGH or LOW , like you're taking an input from the user , environment ...etc
ex) a pushbotton reading the state is on or off ?
```
int buttonState = digitalRead(3);  // read pin 3
if (digitalRead(3) == HIGH) {
  Serial.println("Button is pressed!");
} else {
  Serial.println("Button is not pressed");
}
```

# analogWrite();
creates PWM (Pulse Width Modulation) to simulate analog output 
```
analogWrite(pin, value);  // value: 0-255
```
ex) 
```
analogWrite(3, 255);  // Full brightness/speed (100%)
analogWrite(3, 127);  // Half brightness/speed (50%)
analogWrite(3, 0);    // Off (0%)
analogWrite(3, 64);   // 25% brightness
```
used for : 
1. LED brightness control
2. Motor speed control
3. Speaker tones (with passive buzzer)


# analogRead();
used for reading voltage from analog pins (0-5V) and returns 0-1023

ex) 
```
int sensorValue = analogRead(A0);  // read analog pin A0

Serial.print("Sensor value: ");
Serial.println(sensorValue);  // will be 0-1023

// Convert to voltage (0-5V)
float voltage = sensorValue * (5.0 / 1023.0);
```
used for :
1. Potentiometers (knobs)
2. Light sensors, temperature sensors
3. Any sensor with varying voltage



