#ifndef CHARACTER_H
#define CHARACTER_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"


class Character
{

public:
    Character(int x,int y, int health);
    void init(int _x,int _y, int health);    
    int get_x();
    int get_y();
    int get_health();
    void set_health(int x);
    int _health;
    int _x;
    int _y;
};
#endif