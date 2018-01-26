//**********************************************
// Module bluetooth HC06  envoi de commandes AT
// et affichage de la réponse du module
// D'après http://nicolasz68.blogspot.fr/2012/09/module-bluetooth-jy-mcu-v104-pour.html
//Pin 18 pour RX
//Pin 19 pour TX
//***********************************************/*  



#include "SPI.h"
#include <Adafruit_WS2801.h>
#include <StandardCplusplus.h>
char sens_tableau = '0';//0 pour en haut a droite
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

const int TAILLE_LIST = 10;
char recvChar;
String mot;
boolean motcomplet = false;
int place_mot;
int x = 4;
int y = 4;
String list[TAILLE_LIST];
const int TAILLE_MAX_COMMANDE = 10;
void setup()  
{  
  strip.begin(); 
  list[0] = "Right_u";
  list[1] = "Left_u";
  list[2] = "Up_u";
  list[3] = "Down_u";
  list[4] = "Btn1_u";
  list[5] = "Btn2_u";
  list[6] = "Btn3_u";
  list[7] = "Btn4_u";
  list[8] = "Select_u";
  list[9] = "Start_u";
  color_that_case(x,y,250,0,0);
  Serial.begin(9600);    //115200 si on veut
  delay(500);  
  Serial.println("Starting Bluetooth on Serial1...");  
  // Configuration du bluetooth  
 
  Serial1.begin(9600);  //57600
  delay(500);  
  Serial1.print("AT+NAMEArbalet_St_Jean");
  delay(500);  
  Serial.println("Bluetooth is up!");  
}  
int trouver(String list[]){
  boolean trouver = false;
  int i = 0;
  while(!trouver && i<TAILLE_LIST){
    if(list[i] == mot){
      trouver = true;
    }
    else i++;
  }
  if(trouver == true)
    return i;
  else return -1;
  
}
void loop()  
{  
  
  
   
  //On lit caractere par caractere sur le Serial1 et on affiche sur le Terminal Serie 
  if (Serial1.available() == 0 ){
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
      color_that_case(x,y,0,0,0);
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
      color_that_case(x,y,250,0,0);
    }
    if(mot.length() > TAILLE_MAX_COMMANDE){
    Serial.println("je passe la");
    mot = "";
  }
    
   Serial1.flush();       
  }
strip.show();  
}  


