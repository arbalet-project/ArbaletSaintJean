
#include <StandardCplusplus.h>
#include <vector>

#define TAILLE 300
#define LARGEUR 20
#define HAUTEUR 15
#define T_HAUT 8
#define T_BAS 2
#define T_GAUCHE 4
#define T_DROITE 6

#include "position.h"

#include "SPI.h"
#include <Adafruit_WS2801.h>

// Set the first variable to the NUMBER of pixels in a row and
// the second value to number of pixels in a column.
Adafruit_WS2801 strip = Adafruit_WS2801(300);
int reverseTab[15][20];
std::vector<Position*> snake;
Position* fruit = new Position(0,0);
bool enCours;

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



void verifAjouter(){
    if(snake[0]->equals(fruit)){
        // Rajouter une case quelconque (réécrite par decaler())
        snake.push_back(new Position(0, 0));
        nouveauFruit();
    }
}

void nouveauFruit(){
    do{
        fruit = new Position(random(LARGEUR), random(HAUTEUR));
    }while(!estDansSerpent(fruit));
}

bool estDansSerpent(Position* position){
    for(int i = 0; i < snake.size(); i++)
        if(position->equals(fruit))
            return true;
    return false;
}

void seDeplacer(int dir){
    verifAjouter();
    decaler();
    Position* head = snake[1]->head(dir);
    if(estDansSerpent(head))
        while(true);
    if(head->getX() < 0)
        head->setX(LARGEUR-1);
    if(head->getX() >= LARGEUR)
        head->setX(0);
    if(head->getY() < 0)
        head->setY(HAUTEUR-1);
    if(head->getY() >= TAILLE)
        head->setY(0);
    snake[0] = snake[1]->head(dir);
}

// Tout décaler vers la droite
void decaler(){
    for(int i = snake.size()-2; i >= 0; i--){
        snake[i+1] = snake[i];
    }
}

void setup(){
    initialiser_revser_tab_coin_haut_gauche();

    enCours = true;
    fruit = new Position(random(LARGEUR), random(HAUTEUR));
    int direction = 8;

    snake.push_back(new Position(LARGEUR/2-2, HAUTEUR/2));
    snake.push_back(new Position(LARGEUR/2-1, HAUTEUR/2));
    snake.push_back(new Position(LARGEUR/2,   HAUTEUR/2));
}

void destruct(){
    for(int i = 0; i < snake.size(); i++){
        free(snake[i]);
    }
}

void loop(){
    // TODO: gestion des événements : assigner direction
    seDeplacer(direction);
    for(int i = 0; i < snake.size(); i++){
        snake[i]->draw();
    }
}
