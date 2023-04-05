
#ifndef ZOMBIE_H
#define ZOMBIE_H

#include "mbed.h"
#include "N5110.h"
#include "Character.h"
#include "Utils.h"  // for Position

class Zombie : public Character{

    public: 
    Zombie(int x, int y, int health, int speed);
    void draw(N5110 &lcd);
    void set_position_x(int x);
    void set_position_y(int y);
    int get_speed();
    const int _zombie[9][6]= {
    { 0,0,1,1,0,0, },
    { 0,1,1,1,1,0, },
    { 0,0,1,1,0,0, },
    { 1,1,1,1,1,1, },
    { 0,0,1,1,0,0, },
    { 0,0,1,1,0,0, },
    { 0,1,0,0,1,0, },
    { 0,1,0,0,1,0, },
    { 0,1,0,0,1,0, },};
    int _speed;
 
};
#endif