#include "Bullet.h"

Bullet::Bullet(int x, int y){}

void Bullet::draw(N5110 &lcd) {
    lcd.drawSprite(_x,_y,9,6,(int*) _bullet);
}
void Bullet::set_position_x(int x){
    _x =x;
}

void Bullet::set_position_y(int y){
    _y =y;
}

int Bullet::get_x(){return{_x};}
int Bullet::get_y(){return{_y};}