#include "Player.h"

Player::Player(int x, int y, int health): Character(x,y,health){}

void Player::init(int x,int y, int health){
    _x=x;
    _y=y;
    _health = health;
};

void Player::draw(N5110 &lcd) {
    lcd.drawSprite(_x,_y,9,6,(int*) _player);
}

void Player::set_position_x(int x){
    _x =x;
}

void Player::set_position_y(int y){
    _y =y;
}

int Player::get_position_y(){return{_y};}


int Player::get_position_x(){return{_x};}



