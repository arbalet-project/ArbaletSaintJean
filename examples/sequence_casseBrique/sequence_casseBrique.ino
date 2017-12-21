#include <avr/wdt.h>
#include "Adafruit_WS2801.h"
#include "SPI.h"

#define DEBUG_SERIAL 1

Adafruit_WS2801 strip = Adafruit_WS2801(20,15);
unsigned long DURATION_ANIMATION_MS = 30000;
int NUM_ANIMATIONS = 1;
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
#if DEBUG_SERIAL
  Serial.println("Fading out");
#endif
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

/***************************************************************** Lineaire *******************************************************/
/*
int *value;
int *sens;
float *hue_expos;

float hue1, hue2;

void setupLineaire(){
  value = (int*)malloc(300*sizeof(int));
  sens = (int*)malloc(300*sizeof(int));
  hue_expos = (float*)malloc(300*sizeof(float));
  
  hue1 = random(0, 10)/10.0;
  hue2 = random(0, 10)/10.0;
  
  for(int i = 0; i < strip.numPixels(); ++i){
      value[i] = random(0, 256);
      sens[i] = random(0, 2) == 0 ? 1 : -1;
      hue_expos[i] = random(0, 2) == 0? hue1 : hue2;
      strip.setPixelColor(i, hueToRGB(hue_expos[i], 1.0, value[i]));
  }
  fadeInLineaire();
}

void fadeInLineaire() {
  for(int step = 0; step<100; ++step) {
    for(int i = 0; i < strip.numPixels(); ++i){
      int fade_value = value[i]*step/100;
      strip.setPixelColor(i, hueToRGB(hue_expos[i], 1.0, fade_value/255.0));
    }
    strip.show();
    delay(20);
  }
}

void loopLineaire(){
  for(int i = 0; i < strip.numPixels(); ++i){
    value[i] = min(255, max(0, value[i] + sens[i]));
    if(value[i] == 0) {
        sens[i] = 1;
        hue_expos[i] = random(0, 2) == 0? hue1 : hue2;
    }
    else if(value[i] == 255) {
      sens[i] = -1;
    }
    strip.setPixelColor(i, hueToRGB(hue_expos[i], 1.0, value[i]/255.0));
  }
  strip.show();
  delay(20);
}

void destroyLineaire() {
  free(value); 
  free(sens);
  free(hue_expos);
}

/***************************************************************** CASSE BRIQUES *****************************************************/
int xRaq;
int xLong = 4;
int yRaq =14; 
float xBalle;
float vitX;
float vitY;
float yBalle;
// int briques[5][16][3];

void setupCasseBriques(){
strip.show();

xRaq = 4;
  int couleur = 1;
  for (int i = 1; i <= 6; i++ )
  {
    for (int j = 2; j < 17; j = j + 2)
    {
      couleur = couleur * -1;
      if (i%2 == 0)
      {
        if (couleur < 0)
      {
        strip.setPixelColor(j,i, hueToRGB(0));
        strip.setPixelColor(j+1,i, hueToRGB(0));
      } else
      {
        strip.setPixelColor(j,i, hueToRGB(240/360.0));
        strip.setPixelColor(j+1,i, hueToRGB(240/360.0));
      }
      } else
      {
        if (couleur > 0)
      {
        strip.setPixelColor(j,i, hueToRGB(0));
        strip.setPixelColor(j+1,i, hueToRGB(0));
      } else
      {
        strip.setPixelColor(j,i, hueToRGB(240/360.0));
        strip.setPixelColor(j+1,i, hueToRGB(240/360.0));
      }
      }
      
      
    }
    
  }
  for (int i = xRaq; i < xRaq + xLong; i++)
  {
    strip.setPixelColor(i,yRaq, 255,255,255); 
  }
  yBalle = yRaq-1;
  xBalle = xRaq +1;
  vitX = -0.5;
  vitY = -1;
  strip.setPixelColor((int) xBalle,(int) yBalle,200,200,200);
  strip.show();
  
}


void loopCasseBriques(){
  delay(100);
  strip.setPixelColor(xBalle,yBalle,0,0,0);
  strip.show();
  delay(100);
  xBalle += vitX;
  yBalle += vitY;  
  strip.setPixelColor(xBalle,yBalle,200,200,200);
  if(xBalle == 0 || xBalle == 19 )
  {
    vitX = -vitX;
  }
  if (yBalle == 0 || yBalle == 14)
  {
    vitY = -vitY;
  }
  strip.show();
  delay(100);
  
}

void destroyCasseBriques(){

}


/***************************************************************** ENTRY POINT *******************************************************/

void setup() {
  strip.begin();
  strip.show();
  randomSeed(analogRead(0));

#if DEBUG_SERIAL
  while(!Serial);
  Serial.begin(9600);
  Serial.println("Booting");
#endif

  setupAnimation(0);
}

void setupAnimation(int animation) {
#if DEBUG_SERIAL
  Serial.print("Setting up animation ");
  Serial.println(animation);
  Serial.print("Walltime = ");
  Serial.println(millis());
#endif
  switch(animation) {
     case 0:
     setupCasseBriques();
     break;
  }
}

void loopAnimation(int animation) {
  switch(animation) {
      case 0:
      loopCasseBriques(); //tous le mur dans une meme couleur puis chaque led au hasard change de couleur
      break;
      
  }
}

void destroyAnimation(int animation) {
#if DEBUG_SERIAL
  Serial.print("Destroying animation ");
  Serial.println(animation);
#endif
  switch(animation) {
      case 0:
      destroyCasseBriques(); //tous le mur dans une meme couleur puis chaque led au hasard change de couleur
      break;
  }
}

void loop() {
  unsigned long time = millis();
  
  if(time > 4300000) {
    // Gérer le cas improbable où l'exécution dure plus de 50 jours
    // Overflow de millis()
    // Rebooter par déclenchement du chien de garde
    fadeOut();
    wdt_enable(WDTO_15MS);
    while(1);
  }
  
  if(time > last_animation_switch + DURATION_ANIMATION_MS) {
    last_animation_switch = time;
    fadeOut();
    destroyAnimation(current_animation);
    current_animation = (current_animation + 1)%NUM_ANIMATIONS;
    setupAnimation(current_animation);
  }
  loopAnimation(current_animation);
}
