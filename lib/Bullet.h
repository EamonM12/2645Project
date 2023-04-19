#ifndef BULLET_H
#define BULLET_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"


class Bullet
{

public:
    int get_x();
    int get_y();
    Bullet(int x, int y);
    void draw(N5110 &lcd);
    void set_position_x(int x);
    void set_position_y(int y);

    int _x;
    int _y;
    const int _bullet [3][4]= {{1,1,0,0},
                          {1,1,1,1},
                          {1,1,0,0},};
};
#endif