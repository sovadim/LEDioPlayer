#include "FastLED.h"

// Maximum namber of LEDs in a strip
// Change it if your strip contatin 
// more then 500 LEDs.
// Then, change maximum value of
// LEDs amount slider in the app.

//#define MAX_LEDS 500
#define updateLEDS 1 // Number of LEDS to update every millisecond 

#define NUM_LEDS 200 // Number of LEDS in a strip with default value

CRGB leds[/*MAX_LEDS*/ NUM_LEDS];

// Number of control pin on Arduino
#define DATA_PIN 13

void setup() { 
    Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, /*MAX_LEDS*/ NUM_LEDS);

    for(int i = 0; i < /*MAX_LEDS*/ NUM_LEDS ; i++) {
      leds[i] = CRGB(0,0,0);
    }
    FastLED.show();
}

void loop() {

  // Error input checking
  while(!Serial.read() == -1){}

  // Shift all LEDs to the right by updateLEDS number each time
  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--) {
    leds[i] = leds[i - updateLEDS];
  }

  // 0
  /*for(int i = MAX_LEDS - 1; i >= NUM_LEDS; i--) {
    leds[i] = CRGB(0,0,0);
  }*/

  // Reading info from Serial port
  //[r, g, b, delay, number of LEDs]
  int r = Serial.read();
  int g = Serial.read();
  int b = Serial.read();

  int del = Serial.read();

  //NUM_LEDS = Serial.read();

  // Error-check
  if(r > 255) r = 255;
  if(g > 255) g = 255;
  if(b > 255) b = 255;

  if(r < 0) r = 0;
  if(g < 0) g = 0;
  if(b < 0) b = 0;

  //if (del < 0 || del > 100)
  //  del = 25;

  //if (NUM_LEDS < 0 || NUM_LEDS > MAX_LEDS)
  //  NUM_LEDS = 250;

  // Set the left most updateLEDs with the new color
  for(int i = 0; i < updateLEDS; i++) {
    leds[i] = CRGB(r, g, b);
  }
  FastLED.show();

  //delay(del);
  delay(20);
}
