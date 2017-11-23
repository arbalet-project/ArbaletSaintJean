#include <Animation.h>


#ifndef ANIMATION_BANDS
#define ANIMATION_BANDS

using namespace std;

class AnimationBands : public Animation 
{
	public:
        
        char dir;
        int posY;
        int posX;
        int cptE;
        int cptS;
        int cptW;
        int cptN;
        int cptTot;
        int cptIni; 
        

        int setup(int height, int width, int loops) 
        {
            dir = 'e';
            posY = 0;
            posX= 0;
            cptE = 0;
            cptS = 0;
            cptW = 0;
            cptN = 0;
            cptTot = height * width;
            cptIni = 0;  
        }
        
        void loop() 
        {
            bands(posY, posX, dir, wid, heig);
        }

    private:

        void bands(int posY, int posX, char dir, int width, int height)
        {
	    if(cptIni == cptTot) // Euh ya pas de case vous êtes sûrs de ce que vous faites ?
                {
		    eteindre();
                    dir = 'e';
                    posY = 0;
                    posX= 0;
                    cptE = 0;
                    cptS = 0;
                    cptW = 0;
                    cptN = 0;
                    cptIni = 0;
                } else
                {
                    cptIni++;
                }
            switch (dir)
            {
                
            case 'e':
                if(posX == (width - cptE) && posY == (0+cptE))// Si t'es au coin a droite
                {
                    whitePoint(posY, posX); // Tu colories la LED en blanche
                } else
                {
                    PIXELS[posY][posX]= blue(); //Sinon tu colories en bleu
                    posX++; //augmente le compteur des abscisses
                }
                break;
             
            case 's':
                if(posX == (width - cptS) && posY == (height - cptS)) // Si t'es au coin inférieur droit
                {
                    whitePoint(posY, posX); // Tu colories la LED en blanche
                } else
                {
                    PIXELS[posY][posX] = blue(); // Sinon Tu colories les LEDs en bleu
                    posY++;// Tu augmentes le compteur des ordonnées
                }
                break;
             
            case 'w':
                if(posX == (0 + cptW) && posY == (height - cptW)) // Si t'es au coin inférieur gauche
                {
                    whitePoint(posY, posX);
                } else
                {
                    PIXELS[posY][posX]= red(); // Sinon tu colories les LEDs en rouge
                    posX--;
                }
                break;
             
            case 'n':
                if(posX == (0 + cptN) && posY == (0 + cptN))
                {
                    whitePoint(posY, posX);
                } else
                {
                    PIXELS[posY][posX]= rgb(255,255,0); // Sinon tu colories les LEDs en jaune
                    posY--;
                }
                break;
             
            default:
                break;
             
            }
        }
         
        void whitePoint(int posY, int posX)
        {
            PIXELS[posY][posX]=white(); //On colorie la LEDs en blanche
			
            switch (dir)
            {
            case 'e': // si on était dirigé vers l'est alors
                dir = 's'; // On se dirige au sud
                posY++; // On avance d'une LED pour ne pas écraser la couleur blanche
                cptE++; // On incrément le compteur est pour ne pas créer de conflit en arrivant au centre du paneau d'affichage
                break;
            
            case 's'://De même
                dir = 'w';
                posX--;
                cptS++;
                break;
             
            case 'w'://De même
                dir = 'n';
                posY--;
                cptW++;
                break;
             
            case 'n'://De même
                dir = 'e';
                posX++;
                cptN++;
                break;
             
            default:// Si defaut alors rien
                break;
             
           }
        }

	void eteindre() {
	for(int l = 0; l<width; l++){//Ligne
		for (int c=0; c<height;c++){//Colonne
			PIXELS[l][c]= rgb(0,0,0);// on éteint la LED a la position l et c
		}
	}	

	}


};


#endif

