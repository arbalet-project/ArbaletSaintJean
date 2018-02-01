#include <StandardCplusplus.h>
#include <list>
//#include <stdlib.h>
//#include <iostream>
#include "SPI.h"
#include <Adafruit_WS2801.h>
#include "calcul.h"

#include "position.h"

int direction;
std::list <Position*> snakeStockage;
std::list <Position*> snakeUtil;
Position* fruit;
boolean enCours;
Adafruit_WS2801 *strip;

boolean estDansSerpent(Position* pos){
    Position * elem;
      int i =0;
      boolean dedans =false;
    while(i<snakeStockage.size() && dedans == false)
    {
     elem = snakeStockage.back();
     snakeStockage.pop_back();
     snakeUtil.push_front(elem);
     if(elem == pos)
        dedans=true;
            i++;
    }
    
    i=0;
    for (i;i<snakeUtil.size();i++)
    {
     elem = snakeUtil.front();
     snakeUtil.pop_front();
     snakeStockage.push_back(elem);
    }
    
   return dedans;
}

void nouveauFruit(){

    do{
      free(fruit);
      fruit = new Position(random(LARGEUR), random(HAUTEUR));
    }while(estDansSerpent(fruit));
    fruit->drawFruit();
    
    
}


void verifAjouter(){
    if(snakeUtil.front() == fruit){
        // Rajouter une case quelconque (rÃ©Ã©crite par decaler())
        snakeUtil.push_back(new Position(0, 0));
        nouveauFruit();
    }
    
}

// Tout dÃ©caler vers la droite
void decaler(){
  
  //switch(dir){  
  //snake.push_back(new Position());
  /*for(int i=snake.size()-2;i>=0;i--){
    snake[i+1]=snake[i];
  }
  
  //Position* queue = snake[snake.size()-2];
  //queue->eteindreCase();
  
  //TODO Aymeric décaler en fonction de la direction
   
   Position* queue = snakeUtil.back();
   snakeUtil.pop_front();
   queue->eteindreCase();
   free(queue);
   strip->show();
     
   snake.push_back(new Position(snake[0]->getX()-1,snake[0]->getY()));
    

  //free(queue);
  //snake.erase(snake.size()-1);*/
}


void seDeplacer(int dir){
    verifAjouter();
    decaler();
    /*Position* head = snake[1]->head(dir);
    if(estDansSerpent(head))
        while(true);
    if(head->getX() < 0)
        head->setX(LARGEUR-1);
    if(head->getX() >= LARGEUR)
        head->setX(0);
    if(head->getY() < 0)
        head->setY(HAUTEUR-1);
    if(head->getY() >= TAILLE)
        head->setY(0);*/


    //snake[0] = snake[1]->head(dir);

    
    /*free(snake.end());
    snake.erase(snake.end());*/
}



void setup(){
    randomSeed(analogRead(A0));
    strip = new Adafruit_WS2801(300);
    strip->begin();
      for (int i=0;i<300;i++)
    {
    strip->setPixelColor(i,0,0,0);
    }
    strip->show();
    
    enCours = true;
    nouveauFruit();
    direction = 2;

    snakeUtil.push_back(new Position(LARGEUR/2,   HAUTEUR/2));
    snakeUtil.push_back(new Position(LARGEUR/2-1, HAUTEUR/2));
    snakeUtil.push_back(new Position(LARGEUR/2-2, HAUTEUR/2));
}

void destruct(){
    for(unsigned int i = 0; i < snakeUtil.size(); i++){
        free(snakeUtil.front());
        snakeUtil.pop_front();
    }
}

void loop(){
    // TODO: gestion des Ã©vÃ©nements : assigner direction
    //strip->setPixelColor(0,0,255,0);
    
    //TODO(paspiquant) Allumer 
    /*for(unsigned int i = 0; i < snakeUtil.size(); i++){
        snakeUtil.front()->draw();
        strip->show();
        delay(500);
    }*/
    seDeplacer(direction);
}
