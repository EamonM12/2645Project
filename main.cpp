#include "mbed.h"
#include "Joystick.h"
#include "Zombie.h"
#include "Player.h"
#include "N5110.h"  
#include "Utils.h"
#include "GameEngine.h"
#include <vector>
#include <string>  // for string
using namespace std;

#// MAKE SET NO OF ZOMBIES
// USE IF STATMENTS TO SELECT IF NEEDED ZOMBIE1/ZOMBIE2
//DRAW THEM 
// INIT
// ZOMBIE COLLISIONS AND PLAYER COLLISION



////TO DO:
// FIX CLASSES
// CREATE PATHFINDING
//CREATE BORDER
//SHOOTING
//OPTIONS
//HEALTH
//ROUNDS
//


N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
Joystick joystick(PC_1, PC_0);
DigitalIn buttonA(BUTTON1); //onboard user button

int y_pos = 24;
int x_pos = 42;
  

void init();
void render();
void welcome();
void game_over();
void check_boundary();
void create_zombies(int x , int y);
void Player_movement();


//global vars
int r = 10;
int r_started=0;
vector<vector<int>> Coords{{-5,-8},{76,-8},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1},{1,1}};
volatile int c = 0;



int main()
{      
    init();      // initialise devices and objects
    welcome();   // waiting for the user to start 
    // render();
    int fps = 10;
    thread_sleep_for(1000/fps);  // and wait for one frame period - millseconds
    GameEngine game;

    while(1){
        
        lcd.clear();

        // Creating of boundaries
        lcd.drawLine(0,0,100,0,1); 
        lcd.drawLine(0,47,100,47,1);  
        lcd.drawLine(0,0,0,47,1);
        lcd.drawLine(80,0,80,53,1);
        create_zombies(x_pos,y_pos);
        printf("%d",x_pos);
        printf("%d",y_pos);
        // Player movement
        Player_movement();
        player.set_position_x(x_pos);
        player.set_position_y(y_pos);
        player.draw(lcd);      
        
        
        lcd.refresh();
        lcd.clear();
        c=c+1;
       
    }
     
    
}

void Player_movement(){
        if(joystick.get_direction() == N){
            y_pos--;
            printf(" Direction: N\n");

        }else if(joystick.get_direction() == S){
            y_pos++;
            printf(" Direction: S\n");
        
        }else if(joystick.get_direction() == E){
            x_pos++;
            printf(" Direction: E\n");

        }else if(joystick.get_direction() == W){
            x_pos--;
            printf(" Direction: W\n");

        }else if(joystick.get_direction() == NE){
            y_pos--;
            x_pos++;
            printf(" Direction: NE\n");

        }else if(joystick.get_direction() == NW){
            y_pos--;
            x_pos--;
            printf(" Direction: NW\n");

        }else if(joystick.get_direction() == SE){
            y_pos++;
            x_pos++;
            printf(" Direction: SE\n");

        }else if(joystick.get_direction() == SW){
            y_pos++;
            x_pos--;
            printf(" Direction: SW\n");
        } else {
            printf(" Direction: Centre\n");
        }
}

void create_zombies(int x, int y){
int health = 1;

Zombie zombie1( Coords[0][0],Coords[0][1] ,health,2);
Zombie zombie2( Coords[1][0],Coords[1][1],health,2);
// Zombie zombie3( , ,health,2);
// Zombie zombie4( ,,health,2);
// Zombie zombie5( , ,health,2);
// Zombie zombie6( , ,health,2);
// Zombie zombie7( , ,health,2);
// Zombie zombie8( ,,health,2);
// Zombie zombie9( , ,health,2);

if(c%100==1){

for(int i =0; i<2;i++){
    int dx = x -Coords[i][0];
    int dy = y- Coords[i][1];
    printf("%d",dx);
    printf("%d",dy);
    if(dx <0){
        Coords[i][0] = Coords[i][0]-1;
    }else{
        Coords[i][0] = Coords[i][0]+1;
    }

     if(dy <0){
        Coords[i][1] = Coords[i][1]-1;
    }else{
        Coords[i][1] = Coords[i][1]+1;
    }

};
};

zombie1.set_position_x(Coords[0][0]);
zombie1.set_position_y(Coords[0][1]);

zombie2.set_position_x(Coords[1][0]);
zombie2.set_position_y(Coords[1][1]);

zombie1.draw(lcd);
zombie2.draw(lcd);



};


void init() {
    lcd.init(LPH7366_1);
    lcd.setContrast(0.5);
    joystick.init();
};

void welcome() { // splash screen
    lcd.drawLine(0,2,100,2,1);
    lcd.drawLine(0,45,100,45,1);
    

    lcd.printString("     Zombies    ",0,1);  
    lcd.printString("Press Nucleo",0,3);
    lcd.printString("Blue button",0,4);
    lcd.refresh();

    ThisThread::sleep_for(5000ms);

        // while (buttonA.read() == 1){
        // lcd.printString(" DOG    ",0,1);  
        //  ThisThread::sleep_for(100ms);
      
        // }
}

void game_over() { // splash screen 
    while (1) {
        lcd.clear();
        lcd.printString("  Game Over ",0,2);  
        lcd.refresh();
        ThisThread::sleep_for(250ms);
        lcd.clear();
        lcd.refresh();
        ThisThread::sleep_for(250ms);
    }
}