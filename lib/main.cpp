#include "mbed.h"
#include "Joystick.h"
#include "Zombie.h"
#include "Player.h"
#include "N5110.h"  
#include "Utils.h"
#include "GameEngine.h"
#include "Bullet.h"
#include <cstdint>
#include <vector>
#include <string>  // for string
using namespace std;
N5110 lcd(PC_7, PA_9, PB_10, PB_5, PB_3, PA_10);
BusOut SegDis(PA_11,PA_12, PB_1,PB_15,PB_14,PB_12,PB_11); 
Joystick joystick(PC_1, PC_0);
DigitalIn button1(PC_11);
DigitalIn button2(PC_10);
DigitalIn button3(PD_2); 

void init();
void welcome();
void Game_Over();
DigitalIn buttonA(BUTTON1); //onboard user button
void check_boundary();
void create_zombies(int x , int y);
void Player_movement();
void shooting(UserInput input, int c);
void fired(UserInput input);
void shooting_check();
void reset_bullet();
int Direction_toogle(UserInput input);
void Game_won();
//global vars
int r;
int r_started=1;
volatile int c = 0;
int y_pos = 24;
int x_pos = 42;
int xs =24;
int ys = 42;
int shoot =0;
GameEngine game;
Bullet bullet;
//               0     1     2     3     4     5     6     7     8     9     A     B     C     D     E     F    
int hexDis[] = {0x3F, 0x06, 0x5B,0x4F,0x66,0x6D,0x7D,0X07,0x7F,0x67,0x00};




int main()
{      
    init();
    welcome();   
    game.init();      
    int fps = 10;
    thread_sleep_for(1000/fps);  // and wait for one frame period - millseconds
    

    while(1){
        UserInput input = {joystick.get_direction(),joystick.get_mag()};
        lcd.clear();
        game.zombie_damage();
        SegDis.write(hexDis[r]);
        // Creating of boundaries
        lcd.drawLine(0,0,100,0,1);  //top
        lcd.drawLine(0,47,100,47,1);   // bottom

        lcd.drawLine(0,0,0,47,1); 
        lcd.drawLine(83,0,83,53,1);

        if(button1.read()==  1&& shoot ==0){
            shoot =2;
        }
        if(button2.read()== 1 && shoot ==0){
            shoot =1;
            //game.insta_kill();
        }
        
        if(button3.read()== 1 && shoot ==0){
            shoot =3;
        }
        if(shoot ==0){
            reset_bullet();
        }
                 

        game.update(input,c);
        game.update_zombie(c);        
        fired(input);
        game.check_bullet_collision(xs,ys);
        shooting_check();
        game.zombie_damage();

        int ended = game.check_zombie_health();
        if(ended == 9 && c%30==1){
            r=r+1;
            game.new_round(r);
            ended =0;
        }

        Game_won();
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
    r=1;
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

    // sprintf(buffer,"Health = %1d ",h);
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
    }
}
void fired(UserInput input){


    if(shoot==1){
        xs=xs+1;
    };
    if(shoot==2){
        xs=xs-1;
    };
    if(shoot==3){
        ys=ys+1;
    };  

        bullet.set_position_x(xs);
        bullet.set_position_y(ys);
        bullet.draw(lcd,shoot);
    
}

 void shooting_check(){

     if(bullet.get_x() <= 0  || bullet.get_x()>=78  ){

            //  bullet.set_position_x(-5);
            // bullet.set_position_y(-5);
            reset_bullet();
            shoot=0;

     }

     if(bullet.get_y() <= 0  || bullet.get_y()>=42  ){

            //  bullet.set_position_x(-5);
            // bullet.set_position_y(-5);
            reset_bullet();
            shoot=0;

     }

 }

 void reset_bullet(){
    xs= game.player_x();
    
    ys =game.player_y();

 };

void Game_won(){

    if  (r >9){
            while (1) {
            lcd.clear();
            lcd.drawLine(0,0,100,0,1);  //top
            lcd.drawLine(0,47,100,47,1);   // bottom
            lcd.drawLine(0,0,0,47,1); 
            lcd.drawLine(83,0,83,53,1);
            lcd.printString("You Won! ",0,2);  
            lcd.printString("Press Button A ",0,3);
            if( buttonA.read()== 0){
                main();
            }
            lcd.refresh();
            
           
        }
    }

}

