
#ifndef PLAYER_H
#define PLAYER_H

#include "mbed.h"
#include "N5110.h"
#include "Character.h"
#include "Utils.h"  // for Position

class Player : public Character{

    public: 
    Player(int x, int y, int health);
    void draw(N5110 &lcd);
    void init(int x, int y, int health);
    void set_position_x(int x);
    void set_position_y(int y);
    int get_position_y();
    int get_position_x();

    const int _player[9][6]= {
    { 0,0,1,1,0,0, },
    { 0,1,0,0,1,0, },
    { 0,1,0,0,1,0, },
    { 1,1,1,1,1,1, },
    { 0,0,1,1,0,0, },
    { 0,0,1,1,0,0, },
    { 0,1,0,0,1,0, },
    { 0,1,0,0,1,0, },
    { 0,1,0,0,1,0, },};
 
 
};
#endif