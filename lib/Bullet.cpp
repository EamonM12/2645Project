#include "Bullet.h"

Bullet::Bullet(){}

void Bullet::draw(N5110 &lcd, int shoot) {
    if(shoot ==1){
    lcd.drawSprite(_x,_y,3,4,(int*) bullet);
    };  
    if(shoot==2){
    lcd.drawSprite(_x,_y,3,4,(int*) left_bullet);
    };
    if(shoot==3){
    lcd.drawSprite(_x,_y,4,3,(int*) up_bullet);
    };
}
void Bullet::set_position_x(int x){
    _x =x;
}

void Bullet::set_position_y(int y){
    _y =y;
}

int Bullet::get_x(){return{_x};}
int Bullet::get_y(){return{_y};}