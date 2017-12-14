#include "SPI.h"
#include <Adafruit_WS2801.h>

// Set the first variable to the NUMBER of pixels in a row and
// the second value to number of pixels in a column.
Adafruit_WS2801 strip = Adafruit_WS2801(300);

byte game[15][20]; 
byte next[15][20];

// PARAMETRES


void setup(){
  Serial.begin(9600);
  strip.begin();
  randomSeed(analogRead(0));
  initi();
}

int r, g, b;
void initi(){
  delay(2000);
  r = random(0, 255);
  g = random(0, 255);
  b = random(0, 255);
  int i;
  for(int x = 0; x < 15; ++x){
    for(int y = 0; y < 20; ++y){
      game[x][y] = random(0, 2);
      next[x][y] = game[x][y];
      color(x, y);
    }
  }
  strip.show();
  delay(2000);
}

void loop(){
  for(int x = 0; x < 15; ++x){
    for(int y = 0; y < 20; ++y){
      int voisins = compter(x, y);
      if(game[x][y]){
        next[x][y] = voisins == 2 || voisins == 3;
      }else{
        next[x][y] = voisins == 3;
      }
    }
  }
  boolean difference = false;
  int i;
  for(float i = 0; i < 1.0; i+=0.01){
    for(int x = 0; x < 15; ++x){
      for(int y = 0; y < 20; ++y){
        if(game[x][y] != next[x][y]){
          difference = true;
        }
        game[x][y] = next[x][y];
        color(x, y, i, next[x][y], game[x][y]);
      }
    }
    strip.show();
    delay(100);
  }
  for(int x = 0; x < 15; ++x){
    for(int y = 0; y < 20; ++y){
      if(game[x][y] != next[x][y]){
        difference = true;
      }
      game[x][y] = next[x][y];
      color(x, y);
    }
  }
  if(!difference)
    initi();
  strip.show();
  delay(500);
}

int compter(int x, int y){
  int n = 0;
  for(int i = x-1; i <= x+1; ++i)
    for(int j = y-1; j <= y+1; ++j)
      if(i >= 0 && i < 15 && j >= 0 && j < 20 && i!=x && j!=y)
        if(game[i][j])
          ++n;
  return n;
}

void color(int x, int y, float c, boolean debut, boolean fin){
  int i = x%2 == 0 ?
        20*x + y - 1 :
        20*x + (20-y);
  Serial.print(debut);
  Serial.write(" ");
  Serial.print(fin);
  Serial.write(" ");
  float coef = c*debut + (1-c)*fin;
  coef /= 2.0;
  Serial.println(coef);
  delay(100);
  strip.setPixelColor(i, coef*r, coef*g, coef*b);
}

void color(int x, int y){
  int i = x%2 == 0 ?
        20*x + y - 1 :
        20*x + (20-y);
  strip.setPixelColor(i, game[x][y]*r, game[x][y]*g, game[x][y]*b);
}
