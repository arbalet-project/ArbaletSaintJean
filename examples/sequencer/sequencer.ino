/** Exemple de séquenceur pour Arbalet Saint Jean 

    A améliorer par l'équipe des architectes logiciel pour courir tous les besoins des étudiants **/


/* On inclue l'interface des animations, celle-ci décrit uniquement les
   méthodes obligatoires des animations, elle ne contient pas de code. 
   Toutes les animations (classes filles) vont hériter de cette classe mère. */ 
#include <Animation.h>

#include "Adafruit_WS2801.h"
#include "SPI.h" // Comment out this line if using Trinket or Gemma
#ifdef __AVR_ATtiny85__
#include <avr/power.h>
#endif

/* Pour faire simple on inclue tous les ficheirs de code (directement les .cpp) des animations ici */
#include <animations/animation_vide/animation_vide.cpp>
#include <animations/animation_vide/animation_bands.cpp>
#include <animations/animation_laguerre/animation_laguerre.cpp>

uint8_t dataPin  = 2;    // Yellow wire on Adafruit Pixels
uint8_t clockPin = 3;    // Green wire on Adafruit Pixels

Adafruit_WS2801 strip = Adafruit_WS2801(20, dataPin, clockPin);

/************* Variables globales 
  Attention, ces variables sont globales à tout le microcontrôleur, si les noms sont triviaux il
  pourrait y avoir des conflits (convention : variables globales en majuscules)
**************/
uint8_t WIDTH=20;   // Largeur en nombre de pixels
uint8_t HEIGHT=15;  // Hauteur en nombre de pixels
uint8_t NBAPP = 0;
uint8_t*** PIXELS;    // Les couleurs RGB ou HSV de chaque pixel (attention : mémoire à allouer au démarrage)

const int NBRE_ANIMATIONS = 2;

Animation *Animations[NBRE_ANIMATIONS];
int courrante;
int tours;

void reset(uint8_t*** tab){
  for(int i = 0; i < WIDTH; i++){
    for(int j = 0; j < HEIGHT; j++){
      for(int c = 0; c < 3; c++){
        tab[i][j][c] = 255;
      }
    }
  }
}

/*************
    Point d'entrée du séquenceur
    Aucun code d'animation ici, jsute le séquenceur
**************/
void setup() {
    // C'est le setup() du séquenceur, aucun code d'animation ne va ici
    // TODO : allouer la mémoire des pixels, instancier la bilbiothèque Adafruit, déclarer les animations, appeler leur setup ...
    
    // Aide à la prise en main des pointeurs ci-dessous, code à supprimer, mettre dans un tableau de pointeurs sur des animations, etc
    PIXELS = (uint8_t***)malloc(20*15*3);
    reset(PIXELS);
    AnimationBands *animation_bands =  new AnimationBands();
    Animations[NBAPP++] = animation_bands;
    AnimationLaguerre *animation_laguerre = new AnimationLaguerre();
    Animations[NBAPP++] = animation_laguerre;
    courrante = 0;
    tours = Animations[0]->setup(15,20,100);
    strip.begin();
}


void loop() {
    if(tours < 0){ // Donner le tour à la prochaine animation
        reset(PIXELS);
        ++courrante;
        if(courrante >= NBRE_ANIMATIONS){
            courrante = 0;
        }
        tours = Animations[courrante]->setup(15,20,100);
    }

    // C'est le loop() du séquenceur, aucun code d'animation ne va ici
    // TODO : appeler le loop de l'animation courante, ou bien changer d'animation
    Animation[courrante]->loop();
    --tours;
    
    int i;
    for(int x = 0; x < 15; ++x){
        for(int y = 0; y < 20; ++y){
            i = x * 15 + y;
            strip.setPixelColor(i, Color((byte)PIXELS[x][y][0], (byte)PIXELS[x][y][1], (byte)PIXELS[x][y][2]));
        }
    }
    strip.show();
    delay(100);
}

// Create a 24 bit color value from R,G,B
uint32_t Color(byte r, byte g, byte b)
{
  uint32_t c;
  c = r;
  c <<= 8;
  c |= g;
  c <<= 8;
  c |= b;
  return c;
}
