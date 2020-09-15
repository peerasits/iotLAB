#define ANALOG_PIN A0

int analogValue = 0;
void setup() {
  Serial.begin(9600);

}

void loop() {
  //analogValue = map(analogRead(ANALOG_PIN),0,1023,0,255);
  analogValue = analogRead(ANALOG_PIN);
  Serial.print("Analog input0 = ");
  Serial.println(analogValue);
  delay(300);

}
