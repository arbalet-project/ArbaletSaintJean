#include <Animation.h>

#ifndef ANIMATION_PACMAN
#define ANIMATION_PACMAN

using namespace std;
class AnimationPacman : public Animation {

    public: 
        

        AnimationPacman() {
            
        }

        int setup(int height, int width, int loops) {
           

	    }

        void loop() {
		
	    
	        for(int posX = 0 ; posX < WIDTH ; posX++){
                drawPacMan(pacManClosed,   posX);
                drawGhost(ghostOne,        posX);
                delay(125);                
                drawPacMan(pacManMidOpen,  posX);
                drawGhost(ghostTwo,        posX);	
                delay(125);
                drawPacMan(pacManOpen,     posX);
                drawGhost(ghostOne,        posX);	            
                delay(125);
                drawPacMan(pacManMidOpen,  posX);
                drawGhost(ghostTwo,        posX);                
                delay(125);
            }
        }


    private:
	
		bool pacManClosed[13][13] = {
	        {0,0,0,0,1,1,1,1,1,0,0,0,0},
	        {0,0,1,1,1,1,1,1,1,1,1,0,0},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {1,1,1,1,1,1,1,1,1,1,1,1,1},
	        {1,1,1,1,1,1,1,1,1,1,1,1,1},
	        {1,1,1,1,1,1,1,1,1,1,1,1,1},
	        {1,1,1,1,1,1,1,1,1,1,1,1,1},
	        {1,1,1,1,1,1,1,1,1,1,1,1,1},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {0,0,1,1,1,1,1,1,1,1,1,0,0},
	        {0,0,0,0,1,1,1,1,1,0,0,0,0}
		};

        bool pacManMidOpen[13][13] = {
	        {0,0,0,0,1,1,1,1,1,0,0,0,0},
	        {0,0,1,1,1,1,1,1,1,1,1,0,0},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {1,1,1,1,1,1,1,1,1,1,0,0,0},
	        {1,1,1,1,1,1,1,0,0,0,0,0,0},
	        {1,1,1,1,0,0,0,0,0,0,0,0,0},
	        {1,1,1,1,1,1,1,0,0,0,0,0,0},
	        {1,1,1,1,1,1,1,1,1,1,0,0,0},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {0,1,1,1,1,1,1,1,1,1,1,1,0},
	        {0,0,1,1,1,1,1,1,1,1,1,0,0},
	        {0,0,0,0,1,1,1,1,1,0,0,0,0}
        };
        
        bool pacManOpen[13][13] = {
	        {0,0,0,0,1,1,1,1,1,0,0,0,0},
	        {0,0,1,1,1,1,1,1,1,0,0,0,0},
	        {0,1,1,1,1,1,1,1,0,0,0,0,0},
	        {0,1,1,1,1,1,1,0,0,0,0,0,0},
	        {1,1,1,1,1,1,0,0,0,0,0,0,0},
	        {1,1,1,1,1,0,0,0,0,0,0,0,0},
	        {1,1,1,1,0,0,0,0,0,0,0,0,0},
	        {1,1,1,1,1,0,0,0,0,0,0,0,0},
	        {1,1,1,1,1,1,0,0,0,0,0,0,0},
	        {0,1,1,1,1,1,1,0,0,0,0,0,0},
	        {0,1,1,1,1,1,1,1,0,0,0,0,0},
	        {0,0,1,1,1,1,1,1,1,0,0,0,0},
	        {0,0,0,0,1,1,1,1,1,0,0,0,0}
		};

        unsigned char ghostOne[13][14] = {
            {0,0,0,0,0,1,1,1,1,0,0,0,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,1,1,1,1,0,0},
            {0,1,1,1,2,2,1,1,1,1,2,2,1,0},
            {0,1,1,2,2,2,2,1,1,2,2,2,2,0},
            {0,1,1,2,2,3,3,1,1,2,2,3,3,0},
            {1,1,1,2,2,3,3,1,1,2,2,3,3,1},
            {1,1,1,1,2,2,1,1,1,1,2,2,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,0,1,1,1,0,0,1,1,1,0,1,1},
            {1,0,0,0,1,1,0,0,1,1,0,0,0,1}
        };

		unsigned char ghostTwo[13][14] = {
            {0,0,0,0,0,1,1,1,1,0,0,0,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,1,1,1,1,0,0},
            {0,1,1,1,2,2,1,1,1,1,2,2,1,0},
            {0,1,1,2,2,2,2,1,1,2,2,2,2,0},
            {0,1,1,2,2,3,3,1,1,2,2,3,3,0},
            {1,1,1,2,2,3,3,1,1,2,2,3,3,1},
            {1,1,1,1,2,2,1,1,1,1,2,2,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,1,1,0,1,1,1,1,0,1,1,1,1},
            {0,1,1,0,0,0,1,1,0,0,0,1,1,0}
        };

		unsigned char ghostDead[13][14] = {
            {0,0,0,0,0,1,1,1,1,0,0,0,0,0},
            {0,0,0,1,1,1,1,1,1,1,1,0,0,0},
            {0,0,1,1,1,1,1,1,1,1,1,1,0,0},
            {0,1,1,1,1,1,1,1,1,1,1,1,1,0},
            {0,1,1,1,1,1,1,1,1,1,1,1,1,0},
            {0,1,1,1,2,2,1,1,2,2,1,1,1,0},
            {1,1,1,1,2,2,1,1,2,2,1,1,1,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,2,2,1,1,2,2,1,1,2,2,1,1},
            {1,2,1,1,2,2,1,1,2,2,1,1,2,1},
            {1,1,1,1,1,1,1,1,1,1,1,1,1,1},
            {1,1,0,1,1,1,0,0,1,1,1,0,1,1},
            {1,0,0,0,1,1,0,0,1,1,0,0,0,1}
        };

        void drawPacMan(bool tab[13][13], int posX){
            for (int i = 0 ; i < 13 ; i++){
                for (int j = 0 ; j < 13 ; j++){
                    PIXELS[i+1][j+posX] = rgb(tab[i][j]*255, tab[i][j]*255, 0);
		    PIXELS[i+1][j+posX-1] = 0;
                }
            }
        }
        
        void drawGhost(unsigned char tab[13][14], int posX){
            for (int i = 0 ; i < 13 ; i++){
                for (int j = 0 ; j < 14 ; j++){
                    switch(tab[i][j]){
                        case 1 : PIXELS[i+1][j+posX-14-2] = red();
		    		 PIXELS[i+1][j+posX-1] = 0;
                                 break;
                        case 2 : PIXELS[i+1][j+posX-14-2] = white();
		    		 PIXELS[i+1][j+posX-1] = 0;
                                 break;
                        case 3 : PIXELS[i+1][j+posX-14-2] = blue();
		    		 PIXELS[i+1][j+posX-1] = 0;   
                                 break;
                    }
                }
            }
        }    


};

#endif