#include "FastLED.h"

#define NUM_LEDS 270        // How many leds in your strip?
#define updateLEDS 1        // How many do you want to update every millisecond?
CRGB leds[NUM_LEDS];        // Define the array of leds

#define DATA_PIN 2          // led data transfer

void setup() { 
    Serial.begin(9600);
    FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);

    for(int i = 0; i < NUM_LEDS ; i++) {
      leds[i] = CRGB(0,0,0);
    }
    FastLED.show();
}

void loop() {

  while(!Serial.read() == -1){}

  // Shift all LEDs to the right by updateLEDS number each time
  for(int i = NUM_LEDS - 1; i >= updateLEDS; i--) {
    leds[i] = leds[i - updateLEDS];
  }
  
  int r = Serial.read();
  int g = Serial.read();
  int b = Serial.read();

  int del = Serial.read();

  // Error-check
  if(r > 255) r = 255;
  if(g > 255) g = 255;
  if(b > 255) b = 255;

  if(r < 0) r = 0;
  if(g < 0) g = 0;
  if(b < 0) b = 0;

  if (del < 0 || del > 100)
    del = 25;

  // Set the left most updateLEDs with the new color
  for(int i = 0; i < updateLEDS; i++) {
    leds[i] = CRGB(r, g, b);
  }
  FastLED.show();

  delay(del);
}
