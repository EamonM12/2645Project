#include "Zombie.h"

Zombie::Zombie(int x, int y, int health, int speed): Character(x,y,health),_speed{speed}{}

void Zombie::draw(N5110 &lcd) {
    lcd.drawSprite(_x,_y,9,6,(int*) _zombie);
}
void Zombie::set_position_x(int x){
    _x =x;
}

void Zombie::set_position_y(int y){
    _y =y;
}