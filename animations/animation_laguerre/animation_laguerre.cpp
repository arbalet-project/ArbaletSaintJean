#include <Animation.h>

#ifndef ANIMATION_LAGUERRE
#define ANIMATION_LAGUERRE

using namespace std;

class AnimationLaguerre : public Animation {

    public: 
        int pacManClosed[13][13] = {
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

        int pacManMidOpen[13][13] = {
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
        
        int pacManOpen[13][13] = {
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

        AnimationLaguerre() {
            // Le constructeur. Si j'ai des valeurs par défaut à donner aux variables membres, c'est ici
        }

        int setup(int height, int width, int loops) {
            // Les paramètres d'entrée et de sortie de cette méthode doivent 
            //    correspondre avec l'interface dans Animation.h

	    }

        void loop() {
            // Les paramètres d'entrée et de sortie de cette méthode doivent 
            //    correspondre avec l'interface dans Animation.h
	    
	        for(int posX = 0 ; posX < WIDTH ; posX++){
                drawPacMan(pacManClosed,   posX);
                drawPacMan(pacManMidOpen,  posX);	
                drawPacMan(pacManOpen,     posX);
	            drawPacMan(pacManMidOpen,  posX);
            }
        }


    private:

        void drawPacMan(int tab[13][13], int posX){
	        for (int i = 0 ; i < 13 ; i++){
			    for (int j = 0 ; j < 13 ; j++){
				    PIXELS[i+1][j+posX] = rgb(tab[i][j]*255, tab[i][j]*255, 0);
				    //delay(250);
			    }
	        }
        }

        // J'ai le droit d'ajouter des méthodes privées ici pour
        //   découper correctement mon code.
};

#endif
