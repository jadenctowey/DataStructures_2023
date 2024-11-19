#ifndef LEVEL_H
#define LEVEL_H
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <fstream>
#include "Enemy.h"
#include "Mario.h"

//Level object which holds a 2d array and the functions that correlate as Mario moves through the array
class Level{
    public:
        Level();
        Level(int dimension, int initial_lives, int coin_percentage, int nothing_percentage, int goomba_percentage, int koopa_percentage, int mushroom_percentage, std::string outputFile);
        ~Level();

        int play(bool is_alive);
        void write_events();
        void set_current_level(int lvl);
        std::string get_events();
        int get_moves();




    private:
        static int current_level;
        static int moves;
        std::string events;
        std::string output_file;
        int N;
        bool move_on;
        int boss_num;
        void print_without_array();
        char** field;
        Enemy *enemy;
        Mario *mario;
        void generate_array(bool is_final);
        void print_array();
        void move();
        void coin();
        void mushroom();
        void goomba();
        void koopa();
        void nothing();
        void end_game();
        int boss();
        void warp();
        int c_percentage;
        int x_percentage;
        int g_percentage;
        int k_percentage;
        int m_percentage;
        bool is_alive;
        int enemies_killed;
        int current_col;
        int current_row;
        bool keep_playing;
        int boss_col;
        int boss_row;
        int warp_col;
        int warp_row;

};
#endif