#ifndef WORLD_H
#define WORLD_H
#include "Level.h"
#include <fstream>
//World object that holds array of levels and iterates through them
class World{
    public:
        World();
        World(int num_levels,int dimension,int initial_lives,int coin_percentage,int nothing_percentage,int goomba_percentage,int koopa_percentage,int mushroom_percentage, std::string outputFile);
        ~World();

        void run();

        

    private:
        Level **levels;
        std::string o_file; 
        int L;

};

#endif
