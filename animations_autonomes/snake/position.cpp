#include "position.h"
#include "calcul.h"

Position::Position(int x, int y)
  :m_x(x),m_y(y){

}
void Position::draw(){
    color_that_case(m_x, m_y, 50, 50, 50);
}
int Position::getX(){
    return m_x;
}
int Position::getY(){
    return m_y;
}
void Position::setX(int x){
    m_x = x;
}
void Position::setY(int y){
    m_y = y;
}
bool Position::equals(Position* p){
    return m_x == p->getX() && m_y == p->getY();
}
Position* Position::head(int dir){
    switch(dir){
        case T_HAUT:    return new Position(m_x-1, m_y);
        case T_BAS:     return new Position(m_x+1, m_y);
        case T_GAUCHE:  return new Position(m_x, m_y-1);
        case T_DROITE:  return new Position(m_x, m_y+1);
        default: return new Position(0, 0);
    }
}

