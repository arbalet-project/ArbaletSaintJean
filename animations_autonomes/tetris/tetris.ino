#include "SPI.h"
#include "Adafruit_WS2801.h"

char sens_tableau = '3';
Adafruit_WS2801 strip = Adafruit_WS2801(300);






/************************* Bluetooth ************************************/
String list[10];

boolean commands[10] = {false, false, false, false, false, false, false, false, false, false};

void setupBluetooth() {
  Serial.begin(9600);
  Serial1.begin(9600);
  Serial1.setTimeout(10);
  
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
}

void resetBluetoothCommands() {
   for(int i=0; i<10; ++i) {
      commands[i] = false;
  } 
}

void updateBluetoothCommands() {
  String s = Serial1.readString();
  if(s.length() > 0) {
    //s[s.length()-1] = 0;  // delete \r
    //s[s.length()-2] = 0;  // delete \n

    for(int i=0; i<10; ++i) {
      if(s.startsWith(list[i])) {
        commands[i] = true;
        return;
      }
    }
  } 
}



//  Matrix Definition
#define cols         20
#define rows        15
#define leftLimit    0
#define rightLimit   7
#define topLimit     0
#define bottomLimit 14

int currentMatrix[rows][cols];

#define G  { \
    {  0,   0, 129, 129, 129,   0}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0,   0}, \
    {  0, 129,   0, 129, 129, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0,   0, 129, 129, 129,   0}, \
}

#define A  { \
    {  0,   0,   0, 129,   0,   0}, \
    {  0,   0, 129,   0, 129,   0}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129, 129, 129, 129, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
}

#define M  { \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129, 129,   0, 129, 129}, \
    {  0, 129,   0, 129,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
}

#define E  { \
    {  0, 129, 129, 129, 129, 129}, \
    {  0, 129,   0,   0,   0,   0}, \
    {  0, 129, 129, 129, 129,   0}, \
    {  0, 129,   0,   0,   0,   0}, \
    {  0, 129,   0,   0,   0,   0}, \
    {  0, 129, 129, 129, 129, 129}, \
}

#define O  { \
    {  0,   0, 129, 129, 129,   0}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0,   0, 129, 129, 129,   0}, \
}

#define V  { \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0,   0, 129,   0, 129,   0}, \
    {  0,   0,   0, 129,   0,   0}, \
}

#define R  { \
    {  0, 129, 129, 129, 129,   0}, \
    {  0, 129,   0,   0,   0, 129}, \
    {  0, 129, 129, 129, 129,   0}, \
    {  0, 129,   0, 129,   0,   0}, \
    {  0, 129,   0,   0, 129,   0}, \
    {  0, 129,   0,   0,   0, 129}, \
}

#define blank  { \
    {0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0}, \
    {0, 0, 0, 0, 0, 0}, \
}

//Tetris pieces: these piece matrices are represented by their corresponding colors (1-7)
#define Z1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {1, 1, 0, 0}, \
    {0, 1, 1, 0}, \
}
#define Z2 { \
    {0, 0, 0, 0}, \
    {0, 1, 0, 0}, \
    {1, 1, 0, 0}, \
    {1, 0, 0, 0}, \
}
#define S1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {0, 2, 2, 0}, \
    {2, 2, 0, 0}, \
}
#define S2 { \
    {0, 0, 0, 0}, \
    {2, 0, 0, 0}, \
    {2, 2, 0, 0}, \
    {0, 2, 0, 0}, \
}
#define J1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 3, 0}, \
}
#define J2 { \
    {0, 0, 0, 0}, \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
    {3, 3, 0, 0}, \
}
#define J3 { \
    {0, 0, 0, 0}, \
    {3, 0, 0, 0}, \
    {3, 3, 3, 0}, \
    {0, 0, 0, 0}, \
}
#define J4 { \
    {0, 0, 0, 0}, \
    {0, 3, 3, 0}, \
    {0, 3, 0, 0}, \
    {0, 3, 0, 0}, \
}
#define L1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {4, 4, 4, 0}, \
    {4, 0, 0, 0}, \
}
#define L2 { \
    {0, 0, 0, 0}, \
    {4, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
}
#define L3 { \
    {0, 0, 0, 0}, \
    {0, 0, 4, 0}, \
    {4, 4, 4, 0}, \
    {0, 0, 0, 0}, \
}
#define L4 { \
    {0, 0, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 0, 0}, \
    {0, 4, 4, 0}, \
}
#define T1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {6, 6, 6, 0}, \
    {0, 6, 0, 0}, \
}
#define T2 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {6, 6, 0, 0}, \
    {0, 6, 0, 0}, \
}
#define T3 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {6, 6, 6, 0}, \
    {0, 0, 0, 0}, \
}
#define T4 { \
    {0, 0, 0, 0}, \
    {0, 6, 0, 0}, \
    {0, 6, 6, 0}, \
    {0, 6, 0, 0}, \
}
#define I1 { \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {5, 5, 5, 5}, \
    {0, 0, 0, 0}, \
}
#define I2 { \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
    {0, 5, 0, 0}, \
}
#define O1 {  \
    {0, 0, 0, 0}, \
    {0, 0, 0, 0}, \
    {0, 7, 7, 0}, \
    {0, 7, 7, 0}, \
}


int calculer(int ligne, int colonne) {
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


const byte gameOverLength = 9;
byte gameOverLetters[gameOverLength][6][6]={G,A,M,E,O,V,E,R,blank};

//                      0,  1, 2,  3, 4,  5, 6,  7, 8, 9,10, 11,12,13,14, 15,16,17,18
byte pieces[19][4][4]={O1, Z1,Z2, S1,S2, I1,I2, J1,J2,J3,J4, L1,L2,L3,L4, T1,T2,T3,T4};
//                              0,  1,  2,  3,  4,  5,  6
byte piecesGenerated[7][4][4]={O1, Z1, S1, I1, J1, L1, T1};

byte currentPieceIndex;        // stores current piece index: from 0 to 18
byte currentPieceRotatedIndex; // stores the index of the rotated version of the current piece
byte currentPiece[4][4];       // stores the current piece matrix

//the top left corner of the current piece is tracked
int currentPieceRow;           // stores the row position of currentPiece[0][0]
int currentPieceCol;           // stores the col position of currentPiece[0][0]
int currentPieceMovedRow;      // stores the row position of currentPiece[0][0] after a certain move
int currentPieceMovedCol;      // stores the col position of currentPiece[0][0] after a certain move

byte numberOfLinesCleared;
boolean disableMove;
boolean pieceDropping;
byte textColor;
boolean gameRunning;
boolean gameOver;
boolean fastDrop;


void clearTrace() {
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      if ((currentPieceRow+j>-1 && currentPieceRow+j<rows) && (currentPieceCol+i>-1 && currentPieceCol+i<cols)) {
        if (currentMatrix[currentPieceRow+j][currentPieceCol+i]>0) currentMatrix[currentPieceRow+j][currentPieceCol+i]=0;
      }
    }
  }
}

void updateCurrentMatrix() {
  for (int i=0;i<4;i++) {
    for (int j=0;j<4;j++) {
      if ((currentPieceRow+j>-1 && currentPieceRow+j<rows) && (currentPieceCol+i>-1 && currentPieceCol+i<cols)) {
        if (currentPiece[j][i]!=0) currentMatrix[currentPieceRow+j][currentPieceCol+i]=currentPiece[j][i];
      }
    }
  }
}

void move(int moveDirection) {  //updates: currentPieceRow, currentPieceCol, currentMatrix
  // moveDirection: 2-down; 3-left; 4-right
  if (moveDirection==2) {
    currentPieceMovedRow=currentPieceRow+1;
    currentPieceMovedCol=currentPieceCol;
  }
  else if (moveDirection==3) {
    currentPieceMovedRow=currentPieceRow;
    currentPieceMovedCol=currentPieceCol-1;
  }
  else if (moveDirection==4) {
    currentPieceMovedRow=currentPieceRow;
    currentPieceMovedCol=currentPieceCol+1;
  }
  // check if move is valid
  if (!checkOverlapAndOutOfBoundary(currentPieceIndex)) {
    clearTrace();
    currentPieceRow=currentPieceMovedRow;
    currentPieceCol=currentPieceMovedCol;
    updateCurrentMatrix();
  }
}

boolean checkOverlapAndOutOfBoundary(byte pieceIndex) {
  int row=currentPieceMovedRow;
  int col=currentPieceMovedCol;
  for (int i=0;i<4;i++) {
    for (int j=0; j<4;j++) {
      if (pieces[pieceIndex][j][i]>0) {   // (row+j>-1 && row+j<rows)
        if (!( row+j<rows && (col+i>-1 && col+i<cols))) return true;  // checks out of boundary
        else if (currentMatrix[row+j][col+i]<0) return true;  // checks overlap
      }
    }
  }
  return false;
}

void rotate() {  // updates: currentPieceRotatedIndex, currentPieceIndex, currentPiece, and currentMatrix
  // obtain the currentPieceRotatedIndex
  if (currentPieceIndex==0) return;
  else if (currentPieceIndex<3) currentPieceRotatedIndex=3-currentPieceIndex;
  else if (currentPieceIndex<5) currentPieceRotatedIndex=7-currentPieceIndex;
  else if (currentPieceIndex<7) currentPieceRotatedIndex=11-currentPieceIndex;
  else if ((currentPieceIndex % 4)==2) currentPieceRotatedIndex=currentPieceIndex-3;
  else currentPieceRotatedIndex=currentPieceIndex+1;
  
  currentPieceMovedRow=currentPieceRow;
  currentPieceMovedCol=currentPieceCol;
    
  // check if the rotation is valid 
  if (!checkOverlapAndOutOfBoundary(currentPieceRotatedIndex)) {
    clearTrace();
    currentPieceIndex=currentPieceRotatedIndex;
    for (int i=0;i<4;i++) {
      for (int j=0;j<4;j++) {
        currentPiece[j][i]=pieces[currentPieceRotatedIndex][j][i];
      }
    }
    updateCurrentMatrix();
  }
}

boolean checkIfLanded() {
  for (int i=0;i<4;i++) {
    for (int j=0; j<4;j++) {
      if ((currentPieceRow+j>-1 && currentPieceRow+j<rows) && (currentPieceCol+i>-1 && currentPieceCol+i<cols)) {
        if (currentMatrix[currentPieceRow+j][currentPieceCol+i]>0) {
          if (currentPieceRow+j==bottomLimit) return true;            // if the piece has dropped on the bottom
          else if (currentMatrix[currentPieceRow+j+1][currentPieceCol+i]<0) return true;  //if there is any deadblock just below the piece
        }
      }
    }
  }
  return false;
}

boolean generatePiece() {  //updates: currentPiece, currentMatrix, currentPieceRow, currentPieceCol, currentPieceIndex
  byte pieceIndex=random(7);
  for (int i=0; i<4; i++) {
    for (int j=0; j<4; j++) {
      currentPiece[j][i]=piecesGenerated[pieceIndex][j][i];
    }
  }
  for (int i=0; i<4; i++) {
    for (int j=0; j<2; j++) {
      if (piecesGenerated[pieceIndex][j+2][i]>0) {
        if (currentMatrix[j][i+2]<0) return false;
      }
    }
  }
  for (int i=0; i<4; i++) {
    for (int j=0; j<2; j++) {
      if (piecesGenerated[pieceIndex][j+2][i]>0) {
        currentMatrix[j][i+2]=piecesGenerated[pieceIndex][j+2][i];
      }
    }
  }
  currentPieceRow = -2;
  currentPieceCol = 2;
  switch (pieceIndex) {
    case 0:
      currentPieceIndex=0;
      break;
    case 1:
      currentPieceIndex=1;
      break;
    case 2:
      currentPieceIndex=3;
      break;
    case 3:
      currentPieceIndex=5;
      break;
    case 4:
      currentPieceIndex=7;
      break;
    case 5:
      currentPieceIndex=11;
      break;
    case 6:
      currentPieceIndex=15;
      break;
  }
  return true;
}

void convertToDeadBlock() {
  for (int i=0;i<cols;i++) {
    for (int j=0;j<rows;j++) {
      if (currentMatrix[j][i]>0) {
        currentMatrix[j][i]=-currentMatrix[j][i];
      }
    }
  }
}

void checkLinesCleared() {
  byte lineErased[rows];
  byte rowCounter=0;
  for (int j=0;j<rows;j++) {
    byte colCounter=0;
    for (int i=0;i<cols;i++) {
      if (currentMatrix[j][i]==0) {
        lineErased[j]=0;
        break;
      }
      else colCounter+=1;
    }
    if (colCounter==cols) {
      lineErased[j]=1;
      rowCounter+=1;
    }  
  }
  
  if (rowCounter==0) return;  // if no lines are cleared
  
  int tempMatrix[rows-rowCounter][cols];
  byte rowCounter2=0;
  for (int j=0;j<rows;j++) {
    if (lineErased[j]==0) {
      for (int i=0;i<cols;i++) tempMatrix[rowCounter2][i]=currentMatrix[j][i]+0;
      rowCounter2+=1;
    }
  }
  for (int j=0;j<rowCounter;j++) {
    for (int i=0;i<cols;i++) {
      currentMatrix[j][i]=0;
    }
  }
  for (int j=0;j<rows-rowCounter;j++) {
    for (int i=0;i<cols;i++) {
      currentMatrix[j+rowCounter][i]=tempMatrix[j][i];
    }
  }
  numberOfLinesCleared+=rowCounter;
}

void checkRestartGame() {
  if (commands[9]==true) {  //reinitialize all variables
    for (int i=0;i<cols;i++) {
      for (int j=0; j<rows; j++) currentMatrix[j][i]=0;
    }
    textColor=random(7)+1;
    numberOfLinesCleared=0;
    
    // reinitilize variables
    gameRunning=false;
    gameOver=false;
    disableMove=false;
    pieceDropping=false;
    fastDrop= false;
    generatePiece();
  }
}

unsigned long lastButtonPressTime=millis();
unsigned long time= millis();
// 1-up; 2-down; 3-left; 4-right

void checkRotate() {
  time= millis(); 
  if ((commands[2]==true || commands[4]==true || commands[5]==true || commands[6]==true || commands[7]==true)
      && time-lastButtonPressTime>110 && disableMove==false && gameRunning==true) {
    rotate();
    lastButtonPressTime=millis();
  }
}

void startDropping() {
  time = millis();
  if (commands[3]==true && time-lastButtonPressTime>110 && disableMove==false && gameRunning==true) {
    pieceDropping=true;
    lastButtonPressTime=millis();
  }
}

void checkLeft()  {
  time= millis();
  if (commands[1]==true && time-lastButtonPressTime>110 && disableMove==false && gameRunning==true) {
    move(3);
    lastButtonPressTime=millis();
  }
}

void checkRight() {  
  time= millis();
  if (commands[0]==true && time-lastButtonPressTime>110 && disableMove==false && gameRunning==true) {
    move(4);
    lastButtonPressTime=millis();
  }
}

void checkDrop() {  
  time= millis();
  if (commands[3]==true && time-lastButtonPressTime>110 && disableMove==false && gameRunning==true) {
    fastDrop=true;
    lastButtonPressTime=millis();
  }
}

//  All Interrupt Functions Go Above Here

void setup() {
  //Serial.begin(9600);
  setupBluetooth();
  strip.begin();

  //  random seed for color selection, direction selection, and food+snakehead generation  
  randomSeed(analogRead(A0));
  byte rand1=random(7);
  rand1=random(7);
  rand1=random(7);
  
  
  //initialize variables
  numberOfLinesCleared=0;
  gameRunning = true;
  gameOver = false;
  disableMove = false;
  fastDrop= false;
  
  generatePiece();
}

//  used in the main loop to calculate the time interval between moves
unsigned long lastMoveTime=millis();
unsigned long currentMoveTime=millis();

unsigned long lastLandedTime=millis();
unsigned long currentLandedTime=millis();



void loop() {
  if (gameRunning==false) {
    displayFrame();
  }
  else {
    resetBluetoothCommands();
    updateBluetoothCommands();
    checkRight();
    checkLeft();
    checkRotate();
    checkDrop();
    checkRestartGame();
    
    displayFrame();
    currentMoveTime=millis();
    if (fastDrop==true) {
      while (!checkIfLanded()) move(2);
      displayFrame();
      fastDrop=false;
    }
    if (commands[3]==true) pieceDropping=false;
    int timeInterval;
    if (!pieceDropping) timeInterval = 800-numberOfLinesCleared*10;
    else timeInterval= 120;
    if (!checkIfLanded() && currentMoveTime-lastMoveTime>timeInterval) {
      move(2);
      lastMoveTime=millis();
    }
    else if (checkIfLanded()) {
      lastLandedTime=millis();
      while (currentLandedTime<lastLandedTime+400) {
        currentLandedTime=millis();
        displayFrame();
      }
      if (!checkIfLanded()) return;
      else {
        disableMove = true;
        convertToDeadBlock();
        checkLinesCleared();
        if (generatePiece()==false) {
          gameOverFunc();
          displayTextOverlay(0);
        }
        else disableMove=false;
      }
    }
  }
}

void gameOverFunc() {
  gameRunning = false;
  gameOver = true;
}

void displayFrame() {    // refreshes the display
  byte color;
  for (int i=0; i<cols; i++) {
    for (int j=0; j<rows; j++) {
      if (currentMatrix[j][i]==0) color=0;
      else if (currentMatrix[j][i]<0) color=-currentMatrix[j][i];
      else if (currentMatrix[j][i]==129) color=textColor;
      else color=currentMatrix[j][i];
      switch (color) {
        case 0:
          strip.setPixelColor(calculer(j, i), 0, 0, 0); 
          break;
        case 1:
          strip.setPixelColor(calculer(j, i), 0, 255, 255); 
          break;
        case 2:
          strip.setPixelColor(calculer(j, i), 255, 0, 255); 
          break;
        case 3:
          strip.setPixelColor(calculer(j, i), 255, 255, 0); 
          break; 
        case 4:
          strip.setPixelColor(calculer(j, i), 0, 0, 255); 
          break; 
        case 5:
          strip.setPixelColor(calculer(j, i), 255, 0, 0); 
          break; 
        case 6:
          strip.setPixelColor(calculer(j, i), 0, 255, 0); 
          break; 
        case 7:
          strip.setPixelColor(calculer(j, i), 0, 0, 255); 
          break;
        default:
          strip.setPixelColor(calculer(j, i), 255, 50, 50); 
      }
    }
  }
  strip.show();
}
  
byte gameOverMatrix[6][6*gameOverLength+7];

void conbineLetters(int index) {
  if (index==0) {  // gameOverLetters[9][6][6]={G,A,M,E,O,V,E,R,blank};
    for (int n=0; n<gameOverLength;n++) {
      for (int i=0; i<6; i++) {
        for (int j=0; j<6; j++) {
          gameOverMatrix[j][i+6*n]=gameOverLetters[n][j][i];
          if (n==0) gameOverMatrix[j][6*gameOverLength+i]=gameOverLetters[n][j][i];
          if (n==1 && i<1) gameOverMatrix[j][6*(gameOverLength+1)+i]=gameOverLetters[n][j][i];
        }
      }
    }
  }
}

unsigned long currentFrameTime = millis();

void displayTextOverlay(int index) {  // i=0: GAMEOVER;
  textColor = 8;
  conbineLetters(index);
  if (index==0)  {
    while (gameOver==true) {
      for (int n=0; n<6*gameOverLength; n++) {
        if (gameOver==false) return;
        for (int i=0;i<8;i++) {
          for (int j=5;j<11;j++) {
            currentMatrix[j][i]=0;
          }
        }  
        for (int i=0; i<8; i++) {
          for (int j=0; j<6; j++) {
            if (gameOverMatrix[j][n+i]!=0) {
              currentMatrix[j+5][i]=gameOverMatrix[j][n+i];
            }
          }
        }
        currentFrameTime = millis();  
        unsigned long time=millis();
        while (time-currentFrameTime<100) {
          time=millis();
          displayFrame();
        }           
      }
    }
  }
}
