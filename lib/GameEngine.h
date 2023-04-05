#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "mbed.h"
#include "N5110.h"
#include "Utils.h"
#include "Player.h"


class GameEngine {
    public:
        GameEngine();  // pass in the lcd object from the main file
        void init();
        int update(UserInput input);
        void draw(N5110 &lcd);
    private:
        void check_wall_collision();
        void check_paddle_collision();
        void check_goal();
        Player _player;
        int _lives;
};

#endif