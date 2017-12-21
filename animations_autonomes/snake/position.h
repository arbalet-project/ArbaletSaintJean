#ifndef DEF_POSITION
#define DEF_POSITION

class Position{
    private:
         int m_x, m_y;

     public:
         Position(int x, int y);
         void draw();
         bool equals(Position& p);
         int getX();
         int getY();
         void setX(int x);
         void setY(int y);
         Position& head(int dir);
};

#endif
