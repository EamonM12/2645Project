#include "GameEngine.h"
#include <string>
#include <cstdlib> 
#include <stdio.h>


GameEngine::GameEngine(): _player(24,41,2),_zombie1(_Coords[0][0],_Coords[0][1] ,1,2),_zombie2(_Coords[1][0],_Coords[1][1],1,2),_zombie3(_Coords[2][0],_Coords[2][1],1,2),_zombie4(_Coords[3][0],_Coords[3][1],1,2),_zombie5(_Coords[4][0],_Coords[4][1],1,2),_zombie6(_Coords[5][0],_Coords[5][1],1,2),_zombie7(_Coords[6][0],_Coords[6][1],1,2),_zombie8(_Coords[7][0],_Coords[7][1],1,2),_zombie9(_Coords[8][0],_Coords[8][1],1,2){};

void GameEngine::init(){
    _player.init(24,24,5);
    _player.set_health(5);
    // {76,-8},{-5,21},{-5,44},{8,44},{30,44},{70,44},{85,15},{85,40},{85,30}}; 

    _Coords[0][0]=-5 ;
    _Coords[0][1]= -8;

    _Coords[1][0]= -5 ;
    _Coords[1][1]= 21;

    _Coords[2][0]=-5 ;
    _Coords[2][1]= 44;

    _Coords[3][0]=8 ;
    _Coords[3][1]= 44;

    _Coords[4][0]=30;
    _Coords[4][1]= 44;

    _Coords[5][0]=70;
    _Coords[5][1]= 44;

    _Coords[6][0]=85 ;
    _Coords[6][1]= 15;

    _Coords[7][0]=85 ;
    _Coords[7][1]= 40;

    _Coords[8][0]=85 ;
    _Coords[8][1]= 30;


 

}

int GameEngine::player_x(){
    int x = _player.get_position_x();
    return x;
    }
int GameEngine::player_y(){
    int y = _player.get_position_y();

    return y;
}


void GameEngine::update(UserInput input,int c){
    zombie_damage();
     int x_pos= _player.get_position_x();
     int y_pos=_player.get_position_y();
    if(c%2 ==1){
       


       if(input.d== N){
            y_pos--;
   

        }else if(input.d == S){
            y_pos++;
       
        
        }else if(input.d == E){
            x_pos++;
          

        }else if(input.d == W){
            x_pos--;
         

        }else if(input.d == NE){
            y_pos--;
            x_pos++;
         

        }else if(input.d == NW){
            y_pos--;
            x_pos--;
            

        }else if(input.d== SE){
            y_pos++;
            x_pos++;
          

        }else if(input.d == SW){
            y_pos++;
            x_pos--;
            
        }
    
    };
   

    _player.set_position_x(x_pos);
    _player.set_position_y(y_pos);
    check_boundary_collision();
};


 void GameEngine::draw(N5110 &lcd) {
     _player.draw(lcd);
     _zombie1.draw(lcd);
    _zombie3.draw(lcd);
     _zombie4.draw(lcd);
    _zombie6.draw(lcd);
     _zombie7.draw(lcd);
    _zombie8.draw(lcd);
     _zombie9.draw(lcd);;
    
    };


void GameEngine::check_boundary_collision() {
    int play_x=_player.get_position_x();
    int play_y=_player.get_position_y();
    

    if (play_x <= 0 ) {
        play_x = 1;
      
    }if(play_x >=78 ){
        play_x = 77;
    }

    if (play_y <= 0 ) {
        play_y = 1;
      
    }if(play_y >=42 ){
        play_y = 41;
    }

   _player.set_position_x(play_x);
   _player.set_position_y(play_y);
}


void GameEngine::update_zombie(int c){
    zombie_damage();
    int x_pos= _player.get_position_x();
    int y_pos=_player.get_position_y();
    int health = 1;

    if(c%50==1){

    for(int i =0; i<9;i++){
        int dx = x_pos-_Coords[i][0];
        int dy = y_pos- _Coords[i][1];
        if(dx <0){
            _Coords[i][0] = _Coords[i][0]-1;
        }else{
            _Coords[i][0] = _Coords[i][0]+1;
        }

        if(dy <0){
            _Coords[i][1] = _Coords[i][1]-1;
        }else{
            _Coords[i][1] = _Coords[i][1]+1;
        }

    };
    };

    _zombie1.set_position_x(_Coords[0][0]);
    _zombie1.set_position_y(_Coords[0][1]);

    _zombie2.set_position_x(_Coords[1][0]);
    _zombie2.set_position_y(_Coords[1][1]);

    _zombie3.set_position_x(_Coords[2][0]);
    _zombie3.set_position_y(_Coords[2][1]);

    _zombie4.set_position_x(_Coords[3][0]);
    _zombie4.set_position_y(_Coords[3][1]);

    _zombie5.set_position_x(_Coords[4][0]);
    _zombie5.set_position_y(_Coords[4][1]);

    _zombie6.set_position_x(_Coords[5][0]);
    _zombie6.set_position_y(_Coords[5][1]);

    _zombie7.set_position_x(_Coords[6][0]);
    _zombie7.set_position_y(_Coords[6][1]);

    _zombie8.set_position_x(_Coords[7][0]);
    _zombie8.set_position_y(_Coords[7][1]);

    _zombie9.set_position_x(_Coords[8][0]);
    _zombie9.set_position_y(_Coords[8][1]);

}

void GameEngine::rounds(int r,N5110 &lcd){

    std::string round = to_string(r);

    char buffer[14];

    sprintf(buffer,"Round %1d ",r);
    lcd.printString(buffer,0,1);
    lcd.printString("Round",0,1);

    
}

void GameEngine::zombie_damage(){
    int px =_player.get_position_x();
    int py=_player.get_position_y();


    // for (int i=0;i<9; i++){
    //     int dpx = px-_Coords[i][0];
    //     int dpy = py - _Coords[i][1];
    // if( -1 < dpx <1  || -1<dpy <1){
    //     int ph = _player.get_health();
    //     ph = ph-1;
    //     _player.set_health(ph);
    // }
    
   for (int i=0;i<5; i++){
    if( px == _Coords[i][0] && py == _Coords[i][1]){
        int ph = _player.get_health();
        ph = ph-1;
        _player.set_health(ph);
    }
        if( px == _Coords[8-i][0] && py == _Coords[8-i][1]){
        int ph = _player.get_health();
        ph = ph-1;
        _player.set_health(ph);
    }
}
}

int GameEngine::player_health(){
    int h = _player.get_health();
    return{h};

}