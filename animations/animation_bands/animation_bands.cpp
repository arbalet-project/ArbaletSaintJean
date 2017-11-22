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
		int wid;
		int heig;
        

        int setup(int height, int width, int loops) 
        {
			dir = 'e';
			wid = width;
			heig = height;
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
			switch (dir)
			{
				if(cptIni == cptTot) // Euh ya pas de case vous êtes sûrs de ce que vous faites ?
				{
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
            case 'e':
				if(posX == (width - cptE) && posY == (0+cptE))
				{
					whitePoint(posY, posX);
				} else
				{
					PIXELS[posY][posX]= blue();
					posX++;
				}
				break;
             
			case 's':
				if(posX == (width - cptS) && posY == (height - cptS))
				{
					whitePoint(posY, posX);
				} else
				{
					PIXELS[posY][posX] = blue();
					posY++;
				}
				break;
             
            case 'w':
				if(posX == (0 + cptW) && posY == (height - cptW))
				{
					whitePoint(posY, posX);
				} else
				{
					PIXELS[posY][posX]= red();
					posX--;
				}
				break;
             
            case 'n':
				if(posX == (0 + cptN) && posY == (0 + cptN))
				{
					whitePoint(posY, posX);
				} else
				{
					PIXELS[posY][posX]= rgb(255,255,0);
					posY--;
				}
				break;
             
            default:
				;
				break;
             
			}
		}
         
        void whitePoint(int posY, int posX)
        {
			PIXELS[posY][posX]=rgb(255,255,255);
			
            switch (dir)
            {
			case 'e':
				dir = 's';
				posY++;
				cptE++;
				break;
            
            case 's':
				dir = 'w';
				posX--;
				cptS++;
				break;
             
            case 'w':
				dir = 'n';
				posY--;
				cptW++;
				break;
             
            case 'n':
				dir = 'e';
				posX++;
				cptN++;
				break;
             
            default:
				;
				break;
             
           }
		}
};


#endif

