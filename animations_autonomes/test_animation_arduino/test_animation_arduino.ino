
#include "SPI.h"
#include <Adafruit_WS2801.h>
char sens_tableau = '1';//0 pour en haut a droite
// 1 pour en haut a gauche 
// 2 pour en bas a gauche 
// 3 pour en bas a droite 
// Set the first variable to the NUMBER of pixels in a row and
// the second value to number of pixels in a column.
Adafruit_WS2801 strip = Adafruit_WS2801(300);
int calculer(int ligne, int colonne){
    switch(sens_tableau){
    case '0' :
        if(ligne % 2 == 0){
            return ligne * 20 + (19 - colonne);
        } else{
            return ligne * 20 + colonne;
        }
        break;
    case '1' :
        if(ligne % 2 == 0){
            return ligne * 20 + colonne;
        } else{
            return ligne * 20 + (19 - colonne);
        }
        break;
    case '2' :
        if(ligne % 2 == 0){
            return (14 - ligne) * 20 +  colonne;
        } else{
            return (14 - ligne) * 20 + (19 - colonne);
        }
        break;
    case '3' :
        if(ligne % 2 == 0){
            return (14 - ligne) * 20 + (19 - colonne);
        } else{
            return (14 -ligne) * 20 + colonne;
        }
        break;

    }

}
void color_that_case(int ligne, int colonne, int R, int G, int B){
    strip.setPixelColor(calculer(ligne,colonne), R, G,B);
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
  color_that_case(0,0,0,0,150);
  color_that_case(0,1,0,0,150);
  color_that_case(0,2,0,0,150);
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
