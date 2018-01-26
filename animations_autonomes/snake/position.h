#ifndef DEF_POSITION
#define DEF_POSITION

#define TAILLE 300
#define LARGEUR 20
#define HAUTEUR 15
#define T_HAUT 8
#define T_BAS 2
#define T_GAUCHE 4
#define T_DROITE 6

class Position{
    private:
         int m_x, m_y;

    public:
         Position(int x, int y);
         void draw();
         void drawFruit();
         bool equals(Position* p);
         int getX();
         int getY();
         void setX(int x);
         void setY(int y);
         Position* head(int dir);
         void eteindreCase();
};

#endif

