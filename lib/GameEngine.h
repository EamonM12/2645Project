#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"
#include "Player.h"
#include "Zombie.h"
#include <vector>
class GameEngine {
    public:
        GameEngine();  // pass in the lcd object from the main file
        void init();
        void update(UserInput input, int c);
        void draw(N5110 &lcd);
        int player_y();
        int player_x();
        void update_zombie(int c);
        vector<vector<int>> _Coords{{-5,-8},{76,-8},{-5,21},{-5,44},{8,44},{30,44},{70,44},{85,15},{85,40},{85,30}};
    private:
        void check_wall_collision();
        void check_boundary_collision();
        void check_goal();
        Player _player;
        int _lives;
        
        Zombie _zombie1;
        Zombie _zombie2;
        Zombie _zombie3;
        Zombie _zombie4;
        Zombie _zombie5;
        Zombie _zombie6;
        Zombie _zombie7;
        Zombie _zombie8;
        Zombie _zombie9;
};  

#endif