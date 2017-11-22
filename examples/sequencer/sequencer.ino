/** Exemple de séquenceur pour Arbalet Saint Jean 

    A améliorer par l'équipe des architectes logiciel pour courir tous les besoins des étudiants **/


/* On inclue l'interface des animations, celle-ci décrit uniquement les
   méthodes obligatoires des animations, elle ne contient pas de code. 
   Toutes les animations (classes filles) vont hériter de cette classe mère. */ 
#include <Animation.h>


/* Pour faire simple on inclue tous les ficheirs de code (directement les .cpp) des animations ici */
#include <animations/animation_vide/animation_vide.cpp>
#include <animations/animation_laguerre/animation_laguerre.cpp>



/************* Variables globales 
  Attention, ces variables sont globales à tout le microcontrôleur, si les noms sont triviaux il
  pourrait y avoir des conflits (convention : variables globales en majuscules)
**************/
uint8_t WIDTH=20;   // Largeur en nombre de pixels
uint8_t HEIGHT=15;  // Hauteur en nombre de pixels
uint8_t*** PIXELS;    // Les couleurs RGB ou HSV de chaque pixel (attention : mémoire à allouer au démarrage)

Animation *Animations[12];

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
    AnimationVide *animation_vide = new AnimationVide();   // Déclaration de l'animation et allocation de la mémoire avec le mot-clé "new" (allocation obligatoire avec un pointeur)
    for(int i = 0; i < 1; i++){
      Animations[i] -> setup(15,20,100);
    }
}


void loop() {
    // C'est le loop() du séquenceur, aucun code d'animation ne va ici
    // TODO : appeler le loop de l'animation courante, ou bien changer d'animation
    for( int i = 0; i < 1; i++){
      Animations[i]->loop();
    }
}
