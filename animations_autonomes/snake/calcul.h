#ifndef DEF_CALCUL
#define DEF_CALCUL

#include <Adafruit_WS2801.h>

extern Adafruit_WS2801 strip;

int calculer(int ligne, int colonne);

void color_that_case(int ligne, int colonne, int R, int G, int B);

#endif
