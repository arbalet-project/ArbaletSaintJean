#include <StandardCplusplus.h>
#include <vector>
//#include <stdlib.h>
//#include <iostream>
#include "SPI.h"
#include <Adafruit_WS2801.h>
#include "calcul.h"

#include "position.h"

int direction;
std::vector<Position*> snake;
Position* fruit;
boolean enCours;
Adafruit_WS2801 *strip;

boolean estDansSerpent(Position* position){
    for(unsigned int i = 0; i < snake.size(); i++)
        if(snake[i]->equals(position))
            return true;
    return false;
}

void nouveauFruit(){
    do{
        fruit = new Position(rand()%LARGEUR, rand()%HAUTEUR);
    }while(estDansSerpent(fruit));
    
    
}


void verifAjouter(){
    if(snake[0]->equals(fruit)){
        // Rajouter une case quelconque (rÃ©Ã©crite par decaler())
        snake.push_back(new Position(0, 0));
        nouveauFruit();
    }
}

// Tout dÃ©caler vers la droite
void decaler(){
    for(int i = snake.size()-2; i >= 0; i--){
        snake[i+1] = snake[i];
    }
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



void setup(){
  
    strip = new Adafruit_WS2801(300);
    strip->begin();
      for (int i=0;i<300;i++)
    {
    strip->setPixelColor(i,0,0,0);
    }
    strip->show();
    
    enCours = true;
   // nouveauFruit();
    direction = 8;

    snake.push_back(new Position(LARGEUR/2-2, HAUTEUR/2));
    snake.push_back(new Position(LARGEUR/2-1, HAUTEUR/2));
    snake.push_back(new Position(LARGEUR/2,   HAUTEUR/2));
}

void destruct(){
    for(unsigned int i = 0; i < snake.size(); i++){
        free(snake[i]);
    }
}

void loop(){
    // TODO: gestion des Ã©vÃ©nements : assigner direction
    //strip->setPixelColor(0,0,255,0);
    
    //seDeplacer(direction);
    for(unsigned int i = 0; i < snake.size(); i++){
        snake[i]->draw();
        strip->show();
        delay(500);
    }
}
