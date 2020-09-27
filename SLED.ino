#include <Adafruit_NeoPixel.h>
#define NUMSLEDs  8
#define PINSLEDs  6
Adafruit_NeoPixel SLEDs = Adafruit_NeoPixel(NUMSLEDs,PINSLEDs, NEO_GRB + NEO_KHZ800);
void setup() {
  SLEDs.begin(); // This initializes the NeoPixel library.
  SLEDs.show(); // Initialize all SLEDs to 'off'
}

void display(int index){
  SLEDs.clear();
  SLEDs.setPixelColor(index, SLEDs.Color(128, 128, 0));
  SLEDs.show();
  delay(100);
}
void loop() {
  int val = 128;
  int x[] = {0,1,2,3,4,5,6,7};
  for(int i = 0;i<8;i++){
    display(x[i]);
  }
  
}
