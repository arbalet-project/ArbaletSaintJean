#include <Animation.h>

#ifndef ANIMATION_RAINBOW
#define ANIMATION_RAINBOW

using namespace std;
class AnimationRainbow : public Animation {

    public: 

        AnimationRainbow() {
            delta = 0;
        }

        int setup(int height, int width, int loops) {
            this->height = height;
            this->width = width;
	    }

        void loop() {
            int coordX = 0;
            int coordY = 0;

            for(int i= 0 ; i<width + height ; i++){
                coordX = i;
                coordY = 0;
                int hue = (coordX * 1.0 / width) + delta;
                if(hue > 1){
                    hue--;
                }
                char* color = hsv(hue, 1, 1);

                for(int j = 0; j<i+1; j++){
                    if(coordY < height && coordX < width){
                        PIXELS[coordY][coordX] = color;
                    }
                    coordX--;
                    coordY++;
                }
            }
            delta = delta + (1.0 / width);
            if(delta > 1){
                delta--;
            }
        }


    private:

        int height;
        int width;
        double delta;

};

#endif
