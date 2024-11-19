#ifndef MARIO_H
#define MARIO_H

//Mario object which stores the stats of Mario as he moves through the level
class Mario{
    public:
        Mario();
        ~Mario();
        Mario(int lives);
        void add_life();
        void remove_life();
        void remove_power();
        void add_power();
        void add_coin();
        void remove_coin();
        int get_lives();
        int get_coins();
        int get_pwr_lvl();
        void reset_coins();


    private:
        int v;
        int coins;
        int pwr_lvl;
};

#endif




