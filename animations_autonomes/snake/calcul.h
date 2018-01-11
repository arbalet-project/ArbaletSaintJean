#ifndef DEF_CALCUL
#define DEF_CALCUL

//#include "SPI.h"
//#include <Adafruit_WS2801.h>

Adafruit_WS2801 strip;

// 0 pour en haut a droite
// 1 pour en haut a gauche 
// 2 pour en bas a gauche 
// 3 pour en bas a droite
char sens_tableau = '1';

int calculer(int ligne, int colonne);

void color_that_case(int ligne, int colonne, int R, int G, int B);

#endif
