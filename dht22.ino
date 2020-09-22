
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>;
#define OLED_RESET  -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define DHTPIN 12


#define LEDpin D0
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);


Adafruit_SSD1306 OLED(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

void setup() {
   OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);
   
  Serial.begin(115200);
  dht.begin();

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
    OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(15,0);
    OLED.setTextSize(1);
    OLED.print("Humidity : ");
    OLED.println(h);
    OLED.setCursor(15,10);
    OLED.setTextSize(1);
    OLED.print("Temp : ");
    OLED.println(t);
    OLED.display();

}
