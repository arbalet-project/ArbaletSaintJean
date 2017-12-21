
#include "SPI.h"
#include <Adafruit_WS2801.h>

// Set the first variable to the NUMBER of pixels in a row and
// the second value to number of pixels in a column.
Adafruit_WS2801 strip = Adafruit_WS2801(300);
int reverseTab[15][20];

void initialiser_revser_tab_coin_bas_droit(){ // fonctionne
    for(int i = 14; i > -1; i--){
        for(int j = 19; j > -1; j--){
            if(i % 2 == 0){
                reverseTab[i][j] = (14 - i) * 20 + (19 - j);
            }else{
                reverseTab[i][j] = (14 -i) * 20 + j;
            }
        }
    }
}
void initialiser_revser_tab_coin_bas_gauche(){   // fonctionne
    for(int i = 14; i > -1; i--){
        for(int j = 19; j > -1; j--){
            if(i % 2 == 0){
                reverseTab[i][j] = (14 - i) * 20 +  j;
            }else{
                reverseTab[i][j] = (14 - i) * 20 + (19 - j);
            }
        }
    }
}
void initialiser_revser_tab_coin_haut_gauche(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 20; j++)
            if(i % 2 == 0){
                reverseTab[i][j] = i * 20 + j;
            }else{
                reverseTab[i][j] = i * 20 + (19 - j);
            }
    }
}
void initialiser_revser_tab_coin_haut_droit(){
    for(int i = 0; i < 15; i++){
        for(int j = 0; j < 20; j++)
            if(i % 2 == 0){
                reverseTab[i][j] = i * 20 + (19 - j);
            }else{
                reverseTab[i][j] = i * 20 + j;
            }
    }
}
void color_that_case(int ligne, int colonne, int R, int G, int B){
    strip.setPixelColor(reverseTab[ligne][colonne], R, G,B);
  }
boolean sens[300]; 
unsigned long debut;

// PARAMETRES
int vitesseVariations = 2500;
int proportionCouleur = 5;
int multiplicateur = 10;
int translateur = 30;

void setup(){
  strip.begin();
  /*randomSeed(analogRead(0));
  for(int i = 0; i < 300; ++i){
    uint8_t t = random(0, 256);
    strip.setPixelColor(i, t, t, 255);
    sens[i] = random(0, 2) == 0;
  }*/
  initialiser_revser_tab_coin_haut_gauche();
  strip.show();
  debut = millis();
}

void loop(){
  /*int temps = sin((millis() - debut)/float(vitesseVariations)) * multiplicateur + translateur;
  for(int i = 0; i < 300; ++i){
    uint32_t color = strip.getPixelColor(i) >> 16;
    uint32_t c = color + (sens[i] ? 1 : -1) * random(0, color/proportionCouleur+temps);
    if(c > 240){
      sens[i] = false;
      c = 240;
    }else if(c < 20){
      sens[i] = true;
      c = 20;
    }
    strip.setPixelColor(i, c, c, c+80 < 255 ? c+80 : 255);
  }*/
  color_that_case(4,10,0,0,150);
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
