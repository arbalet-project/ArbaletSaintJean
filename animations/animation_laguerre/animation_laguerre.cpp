#include <Animation.h>

#ifndef ANIMATION_LAGUERRE
#define ANIMATION_LAGUERRE

using namespace std;

class AnimationLaguerre : public Animation {
    public: bool pacManClosed[13][13], pacManMidOpen[13][13], pacManOpen[13][13];
        AnimationLaguerre() {
            // Le constructeur. Si j'ai des valeurs par défaut à donner aux variables membres, c'est ici
        }

        int setup(int height, int width, int loops) {
            // Les paramètres d'entrée et de sortie de cette méthode doivent 
            //    correspondre avec l'interface dans Animation.h
            
		bool pacManClosed[13][13] = {
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}
		};

	 	bool pacManMidOpen[13][13] = {
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 0},
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}
		};

	 	bool pacManOpen[13][13] = {
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}, 
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 0},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0, 0},
	{1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0, 0},
	{0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0, 0},
	{0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 0, 0},
	{0, 0, 0, 0, 1, 1, 1, 1, 1, 0, 0, 0, 0}
		};


	}

        void loop() {
            // Les paramètres d'entrée et de sortie de cette méthode doivent 
            //    correspondre avec l'interface dans Animation.h
	    
            
            for (int i = 0 ; i < 13 ; i++){
		for (int j = 0 ; j < 13 ; j++){
			PIXELS[i+1][j+3] = rgb(pacManClosed[i][j]*255, pacManClosed[i][j]*255, 0);
			//delay(250);
		}
	    }
	
            for (int i = 0 ; i < 13 ; i++){
		for (int j = 0 ; j < 13 ; j++){
			PIXELS[i+1][j+3] = rgb(pacManMidOpen[i][j]*255, pacManMidOpen[i][j]*255, 0);
			//delay(250);
		}
	    }	

	    for (int i = 0 ; i < 13 ; i++){
		for (int j = 0 ; j < 13 ; j++){
			PIXELS[i+1][j+3] = rgb(pacManOpen[i][j]*255, pacManOpen[i][j]*255, 0);
			//delay(250);
		}
	    }	

	    for (int i = 0 ; i < 13 ; i++){
		for (int j = 0 ; j < 13 ; j++){
			PIXELS[i+1][j+3] = rgb(pacManMidOpen[i][j]*255, pacManMidOpen[i][j]*255, 0);
			//delay(250);
		}
	    }	
			
        }

    private:
        // J'ai le droit d'ajouter des méthodes privées ici pour
        //   découper correctement mon code.
};

#endif
