#define ANALOG_PIN A0

int analogValue = 0;
void setup() {
  Serial.begin(115200);

}

void loop() {
  char str[5];
  int temp;
  analogValue = analogRead(ANALOG_PIN);
  temp = analogValue * 3.3 / 1023*1000;
  sprintf(str,"%4d",temp);
  Serial.print("Analog input0 = ");
  Serial.print(str[0]);
  Serial.print(".");
  if(str[1] == ' ')Serial.print("0");
  else Serial.print(str[1]);
  if(str[2] = ' ')Serial.print("0");
  else Serial.print(str[2]);
  Serial.print(str[3]);
  Serial.println(" Volt");
  delay(200);

}
