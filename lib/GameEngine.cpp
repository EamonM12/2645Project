#include "GameEngine.h"
#include <string>

GameEngine::GameEngine(): _player(24,41,2),_zombie1(_Coords[0][0],_Coords[0][1] ,1,2),_zombie2(_Coords[1][0],_Coords[1][1],1,2),_zombie3(_Coords[2][0],_Coords[2][1],1,2),_zombie4(_Coords[3][0],_Coords[3][1],1,2),_zombie5(_Coords[4][0],_Coords[4][1],1,2),_zombie6(_Coords[5][0],_Coords[5][1],1,2),_zombie7(_Coords[6][0],_Coords[6][1],1,2),_zombie8(_Coords[7][0],_Coords[7][1],1,2),_zombie9(_Coords[8][0],_Coords[8][1],1,2){};

void GameEngine::init(){
    _player.init(24,24,1);
  
    _zombie1.init( -5,-8,1,2);
    _zombie2.init(76,-8,1,2);
//     _zombie3.init( _Coords[0][0],_Coords[0][1] ,1,2);
//     _zombie5.init( _Coords[0][0],_Coords[0][1] ,1,2);
//     _zombie6.init( _Coords[0][0],_Coords[0][1] ,1,2);
//     _zombie7.init( _Coords[0][0],_Coords[0][1] ,1,2);
//     _zombie8.init( _Coords[0][0],_Coords[0][1] ,1,2);
//     _zombie9.init( _Coords[0][0],_Coords[0][1] ,1,2);
//     _zombie10.init( _Coords[0][0],_Coords[0][1] ,1,2);
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
    printf("Xcoord:\n");
    printf("%d",x_pos);
    printf("y:coord\n");
    printf("%d",y_pos);
    printf("\n");

    _player.set_position_x(x_pos);
    _player.set_position_y(y_pos);
    check_boundary_collision();

};


 void GameEngine::draw(N5110 &lcd) {
     _player.draw(lcd);
     _zombie1.draw(lcd);
    _zombie2.draw(lcd);
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
int x_pos= _player.get_position_x();
int y_pos=_player.get_position_y();
int health = 1;

if(c%100==1){

for(int i =0; i<2;i++){
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




}
void GameEngine::check_goal() {
    //printf("Pong Engine: Check Goal\n");
   
    
}