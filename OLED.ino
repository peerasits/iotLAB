
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_NeoPixel.h>
#include "DHT.h"
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET  -1
#define NUMSLEDs 2
#define PINSLEDs 10

DHT dht;

Adafruit_SSD1306 display(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
Adafruit_NeoPixel SLEDs = Adafruit_NeoPixel(NUMSLEDs,PINSLEDs,NEO_GRB+NEO_KHZ800);
void setup() {
  Serial.begin(115200);
  pinMode(PINSLEDs,OUTPUT);
  SLEDs.begin();
  SLEDs.show();
  if(!display.begin(SSD1306_SWITCHCAPVCC,0x3C)){
    Serial.println(F("SSD 1306 allocation failed"));
    for(;;){}
  }
  display.clearDisplay();
  display.setTextColor(WHITE);
  dht.setup(12);
}

void loop() {
  display.clearDisplay();
  int val = map(analogRead(A0),0,1023,0,255);
  SLEDs.setPixelColor(0,SLEDs.Color(val,val,0));
  SLEDs.setPixelColor(1,SLEDs.Color(0,0,val));
  SLEDs.show();
  float temperature = dht.getTemperature();
  display.setTextSize(1);
  display.setCursor(0,0);

  display.print("Hello : ");
  display.println(temperature);
  display.setTextSize(3);
  display.println(val);
  display.display();
  
}
