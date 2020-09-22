
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <DHT.h>;
#include <BH1750FVI.h>
#define OLED_RESET  -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define DHTPIN 12

#define LEDpin D0
#define DHTTYPE DHT22   
DHT dht(DHTPIN, DHTTYPE);


Adafruit_SSD1306 OLED(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);
BH1750FVI LightSensor(BH1750FVI::k_DevModeContLowRes);

void setup() {
   OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);
   LightSensor.begin();
  Serial.begin(115200);
  dht.begin();

}

void loop() {
  float h = dht.readHumidity();
  float t = dht.readTemperature();
  uint16_t lux = LightSensor.GetLightIntensity();
    OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(0,0);
    OLED.setTextSize(1);
    OLED.print("H:");
    OLED.println(String(h,0)+" %");
    OLED.setCursor(0,5);
    OLED.print("T:");
    OLED.print(String(t,0)+" ");
    OLED.write(247);
    OLED.println("C");
     Serial.print("Humidity: ");
    Serial.print(h);
    Serial.println("%");
  Serial.print("Temperature: ");
    Serial.print(t);
    Serial.println(" *C");
    delay(1000);
    
OLED.setCursor(0,10);
    OLED.print("L:");
  OLED.print(lux);
  OLED.print(" lx");
  
    OLED.display();


}
