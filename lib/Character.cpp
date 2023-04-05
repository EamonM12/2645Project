#include "Character.h"

Character::Character(int x,int y, int health){
    _x=x;
    _y=y;
    _health=health;
};

void Character::init(int x,int y, int health){

    _x=x;
    _y=y;
    _health = health;
}


int Character::get_health(){return {_health};}
int Character::get_x(){return {_x};};
int Character::get_y(){return {_y};};
