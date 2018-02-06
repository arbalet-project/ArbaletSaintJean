//**********************************************/
// Module bluetooth HC06  envoi de commandes AT
// et affichage de la réponse du module
// D'après http://nicolasz68.blogspot.fr/2012/09/module-bluetooth-jy-mcu-v104-pour.html
//Pin 18 pour RX
//Pin 19 pour TX
//***********************************************/  



#include "SPI.h"
#include <Adafruit_WS2801.h>
#include <StandardCplusplus.h>.
#include <list>

#include "position.h"
#include "calcul.h" 

Adafruit_WS2801* strip;

/*String mot;
boolean motcomplet = false;
int place_mot;
String list[LISTE];
const int TAILLE_MAX_COMMANDE = 10;*/

// 2 pour le haut
// 1 vers la droite
// 0 vers la gauche

int directionSnake;

std::list <Position*> snakeStockage;
std::list <Position*> snakeUtil;
Position* fruit;

boolean estDansSerpent(Position* pos){
    Position* elem;
    int i =0;
    boolean dedans =false;
    while(i<snakeUtil.size() && dedans == false)
    {
     elem = snakeUtil.back();
     snakeUtil.pop_back();
     snakeStockage.push_front(elem);
     if(elem->equals(pos))
        dedans=true;
     i++;
    
  }
    
    i=0;
    for (i;i<snakeStockage.size();i++)
    {
     elem = snakeStockage.back();
     snakeStockage.pop_back();
     snakeUtil.push_back(elem);
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

void decaler(int directionSnake){
  //switch(dir){  
  //snake.push_back(new Position());
  int x_front = snakeUtil.front()->getX();
  int y_front = snakeUtil.front()->getY();
  int x_back =  snakeUtil.back()->getX();
  int y_back = snakeUtil.back()->getY();
  
  color_that_case(snakeUtil.front()->getX(),snakeUtil.front()->getY(),255,0,0);// front ne doit renvoyer qu'une seul case non ?
  //color_that_case(snakeUtil.front()->getX()-1,snakeUtil.front()->getY()-1,0,255,0);
  color_that_case(x_back,y_back,0,0,0);
  snakeUtil.pop_back();
  
  
  switch(directionSnake){
        case 0://TODO encore beuguer
          if((y_front+1) <= LARGEUR){
            snakeUtil.push_front(new Position(x_front,y_front+1));
          }
          else{
            snakeUtil.push_front(new Position(x_front,0));
          }
          break;
        case 1: //TODO meme beug décalage de une case vers le bas  
        if((y_front+1) > 0){
            snakeUtil.push_front(new Position(x_front,y_front-1));
          }
          else{
            snakeUtil.push_front(new Position(x_front,LARGEUR));
          }
          break;
        case 2:
        if((x_front+1 <= LARGEUR)){
            snakeUtil.push_front(new Position(x_front+1,y_front));
          }
          else{
            snakeUtil.push_front(new Position(0,y_front));
          }
          x_front++;
          break;
        case 3:
        if((x_front+1) > 0){
            snakeUtil.push_front(new Position(x_front-1,y_front));
          }
          else{
            snakeUtil.push_front(new Position(HAUTEUR,y_front));
          }
          break;
      }
      
    color_that_case(snakeUtil.front()->getX(),snakeUtil.front()->getY(),255,255,255);
    delay(500);
  //free(queue);
  //snake.erase(snake.size()-1);*/
}

void deplacer()
{
  decaler(directionSnake);
  if (estDansSerpent(fruit)){
    snakeUtil.push_front(new Position(snakeUtil.front()->getY(),snakeUtil.front()->getX()-snakeUtil.size()+1));//Beug téléportation après avoir mangé un fruit en (2,7)
    
    nouveauFruit();
  }
  
}


void setup()  
{  
    randomSeed(analogRead(A0));
    strip = new Adafruit_WS2801(300);
    strip->begin();
    
  for (int i=0;i<300;i++)
  {
    strip->setPixelColor(i,0,0,0);
  }
  
  directionSnake = 0;
  
  snakeUtil.push_front(new Position(HAUTEUR/2-2,LARGEUR/2));
  snakeUtil.front()->draw();
    snakeUtil.push_front(new Position(HAUTEUR/2-1,LARGEUR/2));
  snakeUtil.front()->draw();
    snakeUtil.push_front(new Position(HAUTEUR/2,LARGEUR/2));
  snakeUtil.front()->draw();
  
  fruit = new Position(HAUTEUR/2,0);
  
  
  /*list[0] = "Right_u";
  list[1] = "Left_u";
  list[2] = "Up_u";
  list[3] = "Down_u";
  list[4] = "Btn1_u";
  list[5] = "Btn2_u";
  list[6] = "Btn3_u";
  list[7] = "Btn4_u";
  list[8] = "Select_u";
  list[9] = "Start_u";
  list[7] = "Btn4_u";
  list[8] = "Select_u";
  list[9] = "Start_u";
  color_that_case(x,y,250,0,0);
  Serial.begin(9600);    
  list[7] = "Btn4_u";
  list[8] = "Select_u";
  list[9] = "Start_u";
  color_that_case(x,y,250,0,0);
  Serial.begin(9600);    
  color_that_case(x,y,250,0,0);
  Serial.begin(9600);    //115200 si on veut
  delay(500);  
  Serial.println("Starting Bluetooth on Serial1...");  
  // Configuration du bluetooth  
 
  Serial1.begin(9600);  //57600
  delay(500);  
  Serial1.print("AT+NAMEArbalet_St_Jean");
  delay(500);  
  Serial.println("Bluetooth is up!");  */
}  

/*int trouver(String list[]){
  boolean trouver = false;
  int i = 0;
  while(!trouver && i<LISTE){
    if(list[i] == mot){
      trouver = true;
    }
    else i++;
  }
  if(trouver == true)
    return i;
  else return -1;
  
}*/


void loop()  
{  
  
  //On lit caractere par caractere sur le Serial1 et on affiche sur le Terminal Serie 
  /*if (Serial1.available() == 0 ){
    motcomplet = false;
  }
  if (Serial1.available() != 0 ) {
    
    char alire = (char)Serial1.read();
    Serial.println("Je suis le mo");
    if(motcomplet ==  false){
      mot += alire;
      place_mot = trouver(list);
    }
    Serial.println(mot.length());
    
    if(place_mot != -1){
      motcomplet = true;
      Serial1.flush();
      
      switch(place_mot){
        case 0:
          y++;
          place_mot=-1;
          mot="";
          Serial.println("droite");
   
          break;
        case 1:
          y--;
          place_mot=-1;
          Serial.println("gauche");
          mot="";
          break;
        case 2:
          x++;
          Serial.println("Haut");
          place_mot=-1;
          mot="";
          break;
        case 3:
          x--;
          mot="";
          place_mot=-1;
          Serial.println("Bas");
          break;
      }
      
    }
    if(mot.length() > TAILLE_MAX_COMMANDE){
    Serial.println("je passe la");
    mot = "";
  }
    
   Serial1.flush();       
  }*/
  fruit->drawFruit();
   
  deplacer();
  strip->show();  
}  
/*
    Position elem;
    list<Position> snakeUtil;
    char positionspossibles[300];
    int compteur = 0;
    // dans le setup il faut tout initialisr à 0
    
     * for(int i; i < positionspossibles.lenght(); i++){
     *      positionspossibles[i] = 0;
     *
     * 
     * dans le setup on met les cases allumées en char dans le tableaux 
     * ensuite dans la fonction deplacer grace a la fonction calculer 
     * des que on allume une case on change son char dans le tableaux et idem quand on éteint
     * pour séléectionner un nouveaux fruit on fait un 
     * while(nontrouver et pas la bonne position)
     * enfin il faudra pensé à cloisonner le random du fruit à 300 - taille du serpent 
     * 
     * 
     * 
     * 
     * 
     * 
     * }*/
