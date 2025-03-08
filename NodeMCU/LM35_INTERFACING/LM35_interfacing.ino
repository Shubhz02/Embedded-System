float vref = 3.3;
float resolution = vref/1023;

void setup() {
 Serial.begin(9600);  /* Define baud rate for serial communication */
}

void loop() {
 float temperature = analogRead(A0);
 temperature = (temperature*resolution);
 temperature = temperature*100;
 Serial.println(temperature);
 delay(1000);
}