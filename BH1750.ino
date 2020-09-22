#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET  -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64

//3.3v

Adafruit_SSD1306 OLED(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

int BH1750address = 0x23;
byte buff[2];

void setup() {
  OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);

}

void loop() {
  uint16_t val = 0;
 BHT1750_Init(BH1750address);
  delay(200);
  if( 2 == BH1750_Read(BH1750address)){
    val = ((buff[0] << 8 | buff[1] ) / 1.2) ;
  OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(0,0);
    OLED.setTextSize(3);
    OLED.println("BH1750");
    OLED.setCursor(0,35);
    OLED.println(String(val) + " lx");
    OLED.display();
  }
  delay(150);
}

int BH1750_Read(int address){
  int i = 0;
  Wire.beginTransmission(address);
  Wire.requestFrom(address,2);
  while(Wire.available()){
    buff[i] = Wire.read();
    i++;
    }
   Wire.endTransmission();
   return i;
}

void BHT1750_Init(int address){
  Wire.beginTransmission(address);
  Wire.write(0x10);
  Wire.endTransmission();
}
