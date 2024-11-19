#include "World.h"
#include<cstdlib>

World::World(){ //Default constructor
    L = 4;
    levels = new Level *[L];
    for(int i = 0; i< L;i++){
        levels[i] = new Level();
    }
}

//Constructor
World::World(int num_levels,int dimension,int initial_lives,int coin_percentage,int nothing_percentage,int goomba_percentage,int koopa_percentage,int mushroom_percentage, std::string output_file){
    L = num_levels;
    levels = new Level *[L];
    for(int i = 0; i< L;i++){
        levels[i] = new Level(dimension, initial_lives, coin_percentage, nothing_percentage, goomba_percentage, koopa_percentage, mushroom_percentage, output_file);
    }
    o_file = output_file;
    
    
    

}

World::~World(){ //Deconstructor
    for(int i = 0; i< L;i++){
        delete levels[i];
    }
    delete[] levels;
}



void World::run() { //Runs through each level and checks if the user won or not
    bool lost = false;
    std::ofstream outputFile(o_file);

    outputFile << "Starting Mario Game\n";
    
    outputFile.close();

    for (int i = 0; i < L; i++) {
        levels[0]->set_current_level(i + 1);
        if (i != L - 1) {
            if (levels[i]->play(false) == 0) {
                lost = true;
                break;
            }
        } else {
            std::cout << "Starting final level." << std::endl;
            if (levels[i]->play(true) == 0) {
                lost = true;
            }
        }
    }

    std::ofstream outFile(o_file, std::ios_base::app);

    if(lost) {
        std::cout << "LOST" << std::endl;
        outFile << "Mario Lost in " << levels[0]->get_moves()  << " moves.";
    } else {
        std::cout << "WON" << std::endl;

        outFile << "Mario Won in " << levels[0]->get_moves()  << " moves.";
    }

    outFile.close();
}
