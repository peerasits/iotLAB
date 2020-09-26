#include <ESP8266WiFi.h>
#include <Wire.h>
#include <SPI.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#define OLED_RESET  -1
#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64


const char* ssid = "Lenovo TAB 7";
const char* password = "e38d1c622e7f";

#define LEDpin D0
Adafruit_SSD1306 OLED(SCREEN_WIDTH,SCREEN_HEIGHT,&Wire,-1);

void setup() {
   OLED.begin(SSD1306_SWITCHCAPVCC,0x3C);
   
  Serial.begin(115200);
  Serial.println();
  Serial.println();
  Serial.print("Connecting to");
  Serial.println(ssid);
  pinMode(LEDpin,OUTPUT);
  digitalWrite(LEDpin,0);
  WiFi.begin(ssid,password);
  while(WiFi.status() != WL_CONNECTED){
    delay(500);
    Serial.print(".");
     OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(15,0);
    OLED.setTextSize(1);
    OLED.println("connecting");
    OLED.display();
  }
   Serial.println();
   Serial.println("WiFi connected");
   Serial.println("IP address: ");
   Serial.println(WiFi.localIP());
}

void loop() {

  while(WiFi.status() == WL_CONNECTED){
    
    OLED.clearDisplay();
    OLED.setTextColor(WHITE);
    OLED.setCursor(15,0);
    OLED.setTextSize(1);
    OLED.println("WiFi connected");
    OLED.setCursor(0,30);
    OLED.setTextSize(1);
    OLED.print("IP :");
    OLED.println(WiFi.localIP());
    OLED.display();
    delay(500);
    digitalWrite(LEDpin,1);
    delay(500);
    digitalWrite(LEDpin,0);
  }
   
  

}
