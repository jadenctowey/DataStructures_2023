#include "Enemy.h"
#include<cstdlib>
#include <ctime>

Enemy::Enemy(){
    srand((unsigned) time(NULL)); //Sets the parameter for random as the current time
}
Enemy::~Enemy(){}

int Enemy::fight_boss(){ //Fights boss with a 50% chance to return 1 for a win or 0 for a loss
    if(rand() % 2 == 0){
        return 1;
    }
    else{
        return 0;
    }
}


int Enemy::fight_koopa(){ //Fights koopa with a 65% chance to win
    if(rand() % 100 < 65){
        return 1;
    }
    else{
        return 0;
    }
}

int Enemy::fight_goomba(){ //Fight goomba with a 80% change to win
    if(rand() % 5 != 0){
        return 1;
    }
    else{
        return 0;
    }
}
