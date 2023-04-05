#include "GameEngine.h"

void GameEngine::init(){
    _player.init(24,24,1);
}


// void PongEngine::draw(N5110 &lcd) {
//     //printf("Pong Engine: Draw\n");
//     // draw the elements in the LCD buffer
//     // pitch
//     lcd.drawLine(0,0,WIDTH-1,0,1);  // top
//     lcd.drawLine(WIDTH-1,0,WIDTH-1,HEIGHT-1,1);  // back wall
//     lcd.drawLine(0,HEIGHT-1,WIDTH-1,HEIGHT-1,1); // bottom
//     _ball.draw(lcd);
//     _paddle.draw(lcd);
// }

void GameEngine::check_wall_collision() {
    int x = _player.get_position_x();
    int y = _player.get_position_y();
    if(x == 1 ){
        x=x-1;  
    }       
    if(y == 1){
        y=y-1;
    }if(y ==38){
        y=y+1;
    }
    if(x ==74){
        x=x+1;
    }
    _player.set_position_x(x);
    _player.set_position_y(y);

    };


// void PongEngine::check_paddle_collision() {
//     //printf("Pong Engine: Check Paddle Collision\n");
//     // read current ball and paddle attributes
//     Position2D ball_pos = _ball.get_pos();
//     Position2D ball_velocity = _ball.get_velocity();
//     Position2D paddle_pos = _paddle.get_pos();  // paddle

//     // see if ball has hit the paddle by checking for overlaps
//     if (
//         (ball_pos.y >= paddle_pos.y) && //top
//         (ball_pos.y <= paddle_pos.y + _paddle.get_height() ) && //bottom
//         (ball_pos.x >= paddle_pos.x) && //left
//         (ball_pos.x <= paddle_pos.x + _paddle.get_width() )  //right
//     ) {
//         // if it has, fix position and reflect x velocity
//         ball_pos.x = paddle_pos.x + _paddle.get_width();
//         ball_velocity.x = -ball_velocity.x;
//     }

//     // write new attributes
//     _ball.set_velocity(ball_velocity);
//     _ball.set_pos(ball_pos);
// }

// void PongEngine::check_goal() {
//     //printf("Pong Engine: Check Goal\n");
//     Position2D ball_pos = _ball.get_pos();
//     int size = _ball.get_size();
//     int speed = abs(_ball.get_velocity().x);  // speed is magnitude of velocity
//     // check if ball position has gone off the left
//     if (ball_pos.x + size < 0) {
//         // reset the ball
//         _ball.init(size,speed);
//         _lives--;  // lose a life
//     }   
// }