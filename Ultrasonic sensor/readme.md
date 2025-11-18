# What is the ```pulseIn()``` function ?
it measures the duration of the echo pulse that returns to the sensor.
It does this by waiting for the sensor's echo pin to go from LOW to HIGH, starting a timer, and then stopping the timer when the pin goes back from HIGH to LOW.
The function returns the length of this HIGH pulse in microseconds, which is then used to calculate the distance to an object. 
<img width="1576" height="722" alt="Screenshot 2025-11-18 143704" src="https://github.com/user-attachments/assets/a296b2c0-7568-45c0-b4ed-b38a1092b201" />

# How does the Ultra sonic sensor work ?
it contains a 4 pins
1. vcc -> the positive pin and responsible for the voltage
2. trig -> responsible for  ```Sending``` the Pulse (means OUTPUT pin , digitalWrite)
3. echo -> responsible for receiving the signal and it returns the duration (means pinMode -> INPUT) in microseconds 
4. GND -> GND 🤷‍♂️

# How does it calculate the distance ?
1. speed = Distance / time
2. speed of the sound is constant = 343 meter/second
3. i have the time = duration (got from ```pulseIn()``` function) in microseconds 
4. So Distance = speed * duration
5. The max distance the ultrasonic sensor can measure is 400cm , and the min is about 2cm
6. so  i have to convert from meter -> cm (*100) and from second -> microsecond (*10^6)
7. means  speed * (10^2)/(10^6) = speed * (10^-4)
8. FINALLY , ```Distance  = 0.0340 * duration```


