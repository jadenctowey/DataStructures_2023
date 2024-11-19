#include "Mario.h"

Mario::Mario(){//default Constructor
    v = 3;
    coins = 0;
    pwr_lvl = 0;
}

Mario::~Mario(){}


Mario::Mario(int lives){//Constructor
    v = lives;
    coins = 0;
    pwr_lvl = 0;
}

void Mario::add_life(){//Adds life to Mario
    v += 1;
}
void Mario::remove_life(){//Removes life from Mario
    v -= 1;
}
void Mario::remove_power(){//Removes power from Mario
    pwr_lvl -= 1;
}
void Mario::add_power(){//Adds power to Mario
    pwr_lvl += 1;
}
void Mario::add_coin(){//Adds coin to Mario
    coins += 1;
}
void Mario::remove_coin(){//Removes coin from Mario
    coins -= 1;
}
int Mario::get_lives(){//Returns the amount of lives Mario has
    return v;
}
int Mario::get_coins(){//Returns the amount of coins Mario has
    return coins;
}
int Mario::get_pwr_lvl(){//Returns Marios current power level
    return pwr_lvl;
}
void Mario::reset_coins(){//Sets Marios coins to 0
    coins = 0;
}