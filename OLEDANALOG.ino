#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET  -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

Adafruit_SSD1306 OLED(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);

}

void loop() {
  OLED.clearDisplay();
  OLED.setTextColor(WHITE);
  OLED.setCursor(15,0);
  OLED.setTextSize(2);
  OLED.println("Read ADC");
  OLED.setCursor(15,35);
  OLED.setTextSize(2);
  OLED.println("A0=" +String(analogRead(A0)));
  OLED.display();
}
