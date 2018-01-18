#include "calcul.h"

// 0 pour en haut a droite
// 1 pour en haut a gauche 
// 2 pour en bas a gauche 
// 3 pour en bas a droite
char sens_tableau ='1';

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
    default: // ne dois jamais arriver
        return -1;
    }

}
void color_that_case(int ligne, int colonne, int R, int G, int B){
    strip.setPixelColor(calculer(ligne,colonne), R, G, B);

}
