#include </mnt/roon/users/gmargueritte/Arduino/libraries/ArbaletSaintJean/Animation.h>


#ifndef ANIMATION_BANDS
#define ANIMATION_BANDS

using namespace std;

class AnimationK2000 : public Animation
{
public:
    int posY;
    int posXImpair;
    int posXPair;

    int setup(int HEIGHT, int WIDTH, int loops)
    {
        posY = 0;
        posXImpair =
    }

    void loop()
    {
        k2000(posY, posX, WIDTH, HEIGHT);
        delay(400);
    }

private:
    void k2000(int posY, int posX, int WIDTH, int HEIGHT)
    {

    }
}

