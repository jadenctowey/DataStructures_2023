
#include "Mario.h"
#include "Enemy.h"
#include "Level.h"
#include "World.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main(int argc, char* argv[]) {
    

    ifstream inputFile(argv[1]); // Creates an ifstream object read the input file
    string outputName = argv[2]; //Sets outputName to the second command line argument
    

    int num_levels, dimension, initial_lives, coin_percentage, nothing_percentage, goomba_percentage, koopa_percentage, mushroom_percentage; //Declares all the variables that will be passed into World

    string line;
    int line_number = 1; //Holds current line number from input file

    while (getline(inputFile, line)) {  //Reads line from input file
        istringstream lineStream(line);
        int value;

        switch (line_number) { //stores value in different variables based on line number
            case 1:
                lineStream >> num_levels;
                break;
            case 2:
                lineStream >> dimension;
                break;
            case 3:
                lineStream >> initial_lives;
                break;
            case 4:
                lineStream >> coin_percentage;
                break;
            case 5:
                lineStream >> nothing_percentage;
                break;
            case 6:
                lineStream >> goomba_percentage;
                break;
            case 7:
                lineStream >> koopa_percentage;
                break;
            case 8:
                lineStream >> mushroom_percentage;
                break;
            default:
                break;
        }

        line_number++;
    }

    inputFile.close(); //Close the input file

    
    //Creates world pointer
    World *w = new World( num_levels, dimension, initial_lives, coin_percentage, nothing_percentage, goomba_percentage, koopa_percentage, mushroom_percentage, outputName);
    //Runs world
    w->run();
    //deletes World
    delete w;

    return 0;
}