#include "mbed.h"
#include "Joystick.h"
#include "Zombie.h"
#include "Player.h"
#include "N5110.h"  
#include "Utils.h"
#include "GameEngine.h"
#include "Bullet.h"
#include <vector>
#include <string>  // for string
using namespace std;

// MAKE SET NO OF ZOMBIES
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



void init();
void welcome();
void Game_Over();
DigitalIn buttonA(BUTTON1); //onboard user button
void check_boundary();
void create_zombies(int x , int y);
void Player_movement();
void shooting();

//global vars
int r = 1;
int r_started=1;
volatile int c = 0;
volatile int shoot = 1;
int y_pos = 24;
int x_pos = 42;
GameEngine game;




int main()
{      
    init();
    welcome();   
    game.init();      
    printf("\n");
    printf("%d",game.player_health());
    printf("\n");
    int fps = 10;
    thread_sleep_for(1000/fps);  // and wait for one frame period - millseconds
    

    while(1){
        UserInput input = {joystick.get_direction(),joystick.get_mag()};
        lcd.clear();
        game.zombie_damage();
        if(r_started==1){
            game.rounds(r,lcd);
            if(c%1000==1){
            r_started =0;
        }}
       
        // Creating of boundaries
        lcd.drawLine(0,0,100,0,1);  //top
        lcd.drawLine(0,47,100,47,1);   // bottom

        lcd.drawLine(0,0,0,47,1); 
        lcd.drawLine(83,0,83,53,1);

        game.update(input,c);
        game.update_zombie(c);
        game.zombie_damage();
        Game_Over();
        game.draw(lcd);
        lcd.refresh();
        lcd.clear();
        c=c+1;
       
    }
     
    
}


void init() {
    lcd.init(LPH7366_1);
    lcd.setContrast(0.5);
    joystick.init();
};

void welcome() { // splash screen
    lcd.drawLine(0,2,100,2,1);
    lcd.drawLine(0,45,100,45,1);
   

    const int gun[5][11] ={{1,0,0,0,0,0,0,0,1,0,0},
                          {1,1,1,1,1,1,1,1,1,1,1},
                          {1,1,1,1,1,1,1,0,0,0,0},
                          {1,1,1,0,0,0,0,0,0,0,0},
                          {1,0,0,0,0,0,0,0,0,0,0}   };
    const int bullet [3][4]= {{1,1,0,0},
                          {1,1,1,1},
                          {1,1,0,0},};
    const int flare [5][4]= {{0,1,1,1},
                             {0,0,0,1},
                             {1,1,0,0},
                             {1,0,0,1},
                             {0,1,1,1},};
        const int skull [6][5]= {{0,1,1,1,0},
                                 {1,0,1,0,1},
                                 {1,0,1,0,1},
                                 {1,1,1,1,1},
                                 {0,1,1,1,0},
                                 {0,1,1,1,0},};

    lcd.printString("Zombie",0,1);  
    lcd.printString( "Survival",0,2);
    lcd.drawSprite(20,30,5,11,(int*) gun);
    lcd.drawSprite(42,30,3,4,(int*) bullet);
    lcd.drawSprite(35,30,5,4,(int*) flare);
    lcd.drawSprite(48,30,6,5,(int*) skull);
    lcd.refresh();

    ThisThread::sleep_for(5000ms);

        // while (buttonA.read() == 1){
        // lcd.printString(" DOG    ",0,1);  
        //  ThisThread::sleep_for(100ms);
      
        // }
}

void Game_Over(){    

    int h = game.player_health();
    std::string health = to_string(h);
    
    char buffer[14];

    sprintf(buffer,"Health = %1d ",h);
    lcd.printString(buffer,0,1);

    if  (h <1){
            while (1) {
            lcd.clear();
            lcd.drawLine(0,0,100,0,1);  //top
            lcd.drawLine(0,47,100,47,1);   // bottom
            lcd.drawLine(0,0,0,47,1); 
            lcd.drawLine(83,0,83,53,1);
            lcd.printString("Game Over ",0,2);  
            lcd.printString("Press Button A ",0,3);
            if( buttonA.read()== 0){
                main();
            }
            lcd.refresh();
            
           
        }
    }
    else {
       lcd.printString(buffer,0,1);
    }}



void shooting(){
       printf("\n");
    int x= x_pos;
    
    int y= y_pos;
    Bullet bullet(x,y);

    if(c%10 ==1){
    x = x+2;
     }


    bullet.set_position_x(x);
    bullet.set_position_y(y);
    bullet.draw(lcd);


};