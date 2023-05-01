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
    Bullet();
    void draw(N5110 &lcd,int shoot);
    void set_position_x(int x);
    void set_position_y(int y);

    int _x;
    int _y;

        const int bullet [3][4]= {{1,1,0,0},
                                  {1,1,1,1},
                                  {1,1,0,0},};

    
        const int left_bullet [3][4]= {{0,0,1,1},
                                      {1,1,1,1},
                                      {0,0,1,1},};
            
        const int up_bullet [4][3]=  {{0,1,0},
                                      {0,1,0},
                                      {1,1,1},
                                      {1,1,1},};
};  
#endif