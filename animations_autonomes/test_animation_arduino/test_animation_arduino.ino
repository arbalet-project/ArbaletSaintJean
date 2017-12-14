#include "SPI.h"
#include <Adafruit_WS2801.h>

// Set the first variable to the NUMBER of pixels in a row and
// the second value to number of pixels in a column.
Adafruit_WS2801 strip = Adafruit_WS2801(300);

boolean sens[300]; 
unsigned long debut;

// PARAMETRES
int vitesseVariations = 2500;
int proportionCouleur = 5;
int multiplicateur = 2;

void setup(){
  strip.begin();
  randomSeed(analogRead(0));
  for(int i = 0; i < 300; ++i){
    uint8_t t = random(0, 256);
    strip.setPixelColor(i, t, t, 255);
    sens[i] = random(0, 2) == 0;
  }
  strip.show();
  debut = millis();
}

void loop(){
  int temps = sin((millis() - debut)/float(vitesseVariations)) * multiplicateur + multiplicateur+10;
  for(int i = 0; i < 300; ++i){
    uint32_t color = strip.getPixelColor(i) >> 16;
    uint32_t c = color + (sens[i] ? 1 : -1) * random(0, color/proportionCouleur+temps);
    if(c > 250){
      sens[i] = false;
      c = 250;
    }else if(c < 10){
      sens[i] = true;
      c = 10;
    }
    strip.setPixelColor(i, c, c, c+100 < 255 ? c+100 : 255);
  }
  strip.show();
}

// Create a 24 bit color value from R,G,B
uint32_t rgb(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

uint8_t* rgb(uint32_t n){
  uint8_t rgb[3];
  uint32_t color = strip.getPixelColor(n);
  rgb[0] = color >> 16;
  rgb[1] = color >> 8;
  rgb[2] = color;
  return rgb;
}

//Input a value 0 to 255 to get a color value.
//The colours are a transition r - g -b - back to r
uint32_t wheel(byte WheelPos)
{
  if (WheelPos < 85) {
   return rgb(WheelPos * 3, 255 - WheelPos * 3, 0);
  } else if (WheelPos < 170) {
   WheelPos -= 85;
   return rgb(255 - WheelPos * 3, 0, WheelPos * 3);
  } else {
   WheelPos -= 170; 
   return rgb(0, WheelPos * 3, 255 - WheelPos * 3);
  }
}
