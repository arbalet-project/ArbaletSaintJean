#include "Adafruit_WS2801.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma


Adafruit_WS2801 strip = Adafruit_WS2801(300);
unsigned long DURATION_ANIMATION_MS = 10000;
int NUM_ANIMATIONS = 2;
unsigned long last_animation_switch = 0;
int current_animation = 0;


/***************************************************************** OUTILS DE CONVERSION *******************************************************/

// Create a 24 bit color value from R,G,B
uint32_t ColorToInt(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}

// Returns R, G, B from Integer
uint8_t IntToColorR(uint32_t color){
  uint8_t red = color >> 16;
  return red;
}

uint8_t IntToColorG(uint32_t color){
  uint8_t green = color >> 8;
  return green;
}

uint8_t IntToColorB(uint32_t color){
  uint8_t blue = color;
  return blue;
}

uint32_t hueToRGB(float h, float s=1.0, float v=1.0) {
  int i = h*6;
  float f = (h*6.0) - i;

  uint8_t p = 255*v*(1.0 - s);
  uint8_t q = 255*v*(1.0 - s*f);
  uint8_t t = 255*v*(1.0 - s*(1.0-f));
  uint8_t w = 255*v;
  i = i%6;

  if(s < 0.001)
    return ColorToInt(w, w, w);

  switch(i) {
  case 0:
    return ColorToInt(w, t, p);
  case 1:
    return ColorToInt(q, w, p);
  case 2:
    return ColorToInt(p, w, t);
  case 3:
    return ColorToInt(p, q, w);
  case 4:
    return ColorToInt(t, p, w);
  case 5:
    return ColorToInt(w, p, q);
  }
  return ColorToInt(0, 0, 0);
}

void fadeOut() {
  Serial.println("Fading out");
  for(int step=100; step>0; --step) {
    for (int i = 0; i < strip.numPixels(); ++i)
    {
      uint32_t color = strip.getPixelColor(i);
      uint8_t red = IntToColorR(color)*step/100.0;
      uint8_t green = IntToColorG(color)*step/100.0;
      uint8_t blue = IntToColorB(color)*step/100.0;
      color = ColorToInt(red, green, blue);    
      strip.setPixelColor(i, color); 
    }
  
    strip.show();
    delay(10);
  }
}

/***************************************************************** ROUE DES COULEURS *******************************************************/

float *hue; 

void fadeInRoueDesCouleurs() {
  for(int value=0; value<100; value++) {
    for (int i = 0; i < strip.numPixels(); i++)
    {
      strip.setPixelColor(i, hueToRGB(hue[i], 1.0, value/100.0)); 
    }
  
    strip.show();
    delay(10);
  }
}

void setupRoueDesCouleurs()  {
    hue = (float*)malloc(300*sizeof(float));
    
    for (int i = 0; i < strip.numPixels(); i++)
      {
        hue[i] = random(0,72)/360.0;
      }
    fadeInRoueDesCouleurs();
}

void loopRoueDesCouleurs()
{
  for (int i = 0; i < strip.numPixels(); i++)
  {
    hue[i] += 0.004;
    if (hue[i] >= 1)
    {
      hue[i] = 0;
    }
  }

  for (int i = 0; i < strip.numPixels(); i++)
  {
    strip.setPixelColor(i, hueToRGB(hue[i])); 
  }

  strip.show();
  delay(100);
}

void destroyRoueDesCouleurs() {
    fadeOut();
    free(hue);
}

/***************************************************************** ENTRY POINT *******************************************************/

void setup() {
  strip.begin();
  strip.show();
  while(!Serial);
  Serial.begin(9600);
  setupAnimation(0);
}

void setupAnimation(int animation) {
  Serial.print("Setting up animation ");
  Serial.println(animation);
  switch(animation) {
    case 0:
      setupRoueDesCouleurs();
      break;
    case 1:
      setupRoueDesCouleurs();
      break;
  }
}

void loopAnimation(int animation) {
  switch(animation) {
    case 0:
      loopRoueDesCouleurs();
      break;
    case 1:
      loopRoueDesCouleurs();
      break;
  }
}

void destroyAnimation(int animation) {
  Serial.print("Destroying animation ");
  Serial.println(animation);
  switch(animation) {
    case 0:
      destroyRoueDesCouleurs();
      break;
    case 1:
      destroyRoueDesCouleurs();
      break;
  }
}

void loop() {
  unsigned long time = millis();
  if(time > last_animation_switch + DURATION_ANIMATION_MS) {
    last_animation_switch = time;
    fadeOut();
    destroyAnimation(current_animation);
    current_animation = (current_animation + 1)%NUM_ANIMATIONS;
    setupAnimation(current_animation);
  }
  loopAnimation(current_animation);
}
