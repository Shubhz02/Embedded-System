int LED = D4;
intPIR_Input = D1;

void setup(){
 pinMode(PIR_Input,INPUT);
 pinMode(LED,OUTPUT);
}

void loop() {
 digitalWrite(LED, digitalRead(PIR_Input));
 delay(10);
}