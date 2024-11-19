#include "Level.h"
#include "Enemy.h"
#include "Mario.h"
#include "Level.h"
#include "Enemy.h"
#include "Mario.h"

int Level::current_level = 0;
int Level::moves = 0;

Level::Level(){ // default constructor
    N = 2;
    enemies_killed = 0;
    keep_playing = true;
    is_alive = true;
    srand((unsigned) time(NULL));
    current_row = rand() % N;
    current_col = rand() % N;
    boss_col = 0;
    boss_row = 0;
    warp_col = 1;
    warp_row = 1;
    events = "";
    field = new char*[N];
    enemy = new Enemy();
    mario = new Mario();
    for (int i = 0; i < N; i++) {
        field[i] = new char[N];
    }
}

Level::Level(int dimension, int initial_lives, int coin_percentage, int nothing_percentage, int goomba_percentage, int koopa_percentage, int mushroom_percentage, std::string outputFile){ //Constructor
    N = dimension;
    enemies_killed = 0;
    events = "";
    boss_num = 0;
    move_on = true;
    c_percentage = coin_percentage;
    x_percentage = nothing_percentage;
    g_percentage = goomba_percentage; 
    k_percentage = koopa_percentage; 
    m_percentage = mushroom_percentage;
    output_file = outputFile;
    srand((unsigned) time(NULL));
    current_row = rand() % N;
    current_col = rand() % N;
    is_alive = true;
    keep_playing = true;
    boss_col = 0;
    boss_row = 0;
    warp_col = 1;
    warp_row = 1;
    field = new char*[N];
    enemy = new Enemy();
    mario = new Mario(initial_lives);
    //Dynamically allocated 2d array
    for (int i = 0; i < N; i++) {
        field[i] = new char[N];
    }
}

//Deletes all dynamically allocated objects
Level::~Level(){
    for(int i = 0; i < N; i++) {
        delete[] field[i];
    }
    delete[] field;
    delete mario;
    delete enemy;

}


//Method to play through a level.  Parameter determines whether level is the final level or not
int Level::play(bool is_final){
    bool move_on = true;
    generate_array(is_final);
    print_without_array();
    while(keep_playing){
        events += "\nCurrent row:" + std::to_string(current_col + 1) + " Current column:" + std::to_string(current_row + 1) + "\n";
        events += "Power Level:" + std::to_string(mario->get_pwr_lvl()) + "\n";
        events += "Current Level:" + std::to_string(current_level) + "\n";
        print_array();
        write_events();
        if(field[current_col][current_row] == 'c'){
            coin();
        }else if(field[current_col][current_row] == 'm'){
            mushroom();
        }else if(field[current_col][current_row] == 'g'){
            goomba();
        }else if(field[current_col][current_row] == 'k'){
            koopa();
        }else if(field[current_col][current_row] == 'x'){
            nothing();
        }else if(field[current_col][current_row] == 'b'){
            boss_num = boss();
            if(is_final && boss_num == 1){
                keep_playing = false;
            }
            if(boss_num == 0){
                move_on = false;
            }else{
                move_on = true;

            }
        }else if(field[current_col][current_row] == 'w'){
            warp();
            write_events();
            break;
        }
        write_events();
        if(move_on == true){
            move();
        }else{
            events += "Mario will stay put.\n";
        }
        
    }
    if(is_alive == true){    
        return 1;
    }else{
        return 0;
    }
}






//Generates array based on the percentages passed into the constructor
void Level::generate_array(bool is_final){
    int c_upper = 100;
    int c_lower = 100 - c_percentage;
    int m_upper = c_lower;
    int m_lower = m_upper - m_percentage;
    int g_upper = m_lower;
    int g_lower = g_upper - g_percentage;
    int k_upper =g_lower;
    int k_lower = k_upper - k_percentage;
    int x_upper = k_lower;
    int x_lower = 0;
    
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            int randint = rand() % 100;
            char c;
            if(randint < c_upper && randint > c_lower){
                c = 'c';
            }else if(randint < m_upper && randint > m_lower){
                c = 'm';
            }else if(randint < g_upper && randint > g_lower){
                c = 'g';
            }else if (randint < k_upper && randint > k_lower){
                c = 'k';
            }else if (randint < x_upper && randint > x_lower){
                c = 'x';
            }
        
            
            field[i][j] = c;
        }
    }
    boss_col = rand() % N;
    boss_row = rand() % N;
    warp_col = rand() % N;
    warp_row = rand() % N;
    while(warp_col == boss_col && warp_row == boss_row){
        warp_col = rand() % N;
        warp_row = rand() % N;
    }
    field[boss_col][boss_row] = 'b';
    if(is_final == false){
        field[warp_col][warp_row] = 'w';
    }
}

//Formats the array to the events string
void Level::print_array(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if(current_col == i && current_row == j){
                events += "H ";
            }else{
                events += std::string(1, field[i][j]) + " ";
            }
        }
        events += "\n";
    }
    for(int i = 0; i<(N*2)-1; i++){
        events += "-";
    }
    events += "\n";
}

//Same as print_array() however does not print where the Hero is
void Level::print_without_array(){
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
                events += std::string(1, field[i][j]) + " ";
        }
        events += "\n";
    }
    for(int i = 0; i<(N*2)-1; i++){
        events += "-";
    }
    events += "\n";
}

//Randomly picks where Mario will move
void Level::move(){
    // 0 = up, 1 = right, 2 = down, 3 = left
    moves += 1;
    int randint = rand() % 4;
    if(randint == 0){
        current_row -= 1;
        events += "Mario will move LEFT\n";
        if(current_row == -1){
            current_row = N-1;
        }
    }else if(randint == 1){
        current_col += 1;
        events += "Mario will move DOWN\n";
        if(current_col == N){
            current_col = 0;
        }
    }else if(randint == 2){
        current_row += 1;
        events += "Mario will move RIGHT\n";
        if(current_row == N){
            current_row = 0;
        }
    }else{
        current_col -= 1;
        events += "Mario will move UP\n";
        if(current_col == -1){
            current_col = N - 1;
        }
    }
}

//Adds coint to Mario and checks if Mario gets an additional life
void Level::coin(){
    mario->add_coin();
    field[current_col][current_row] = 'x';
    events += "Collected coin\n";
    if(mario->get_coins() == 20){
        mario->add_life();
        mario->reset_coins();
    }
    events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
    events += "Lives:" + std::to_string(mario->get_lives()) + "\n"; 
}

//Raises Marios power if he is not at Power Level 2 already
void Level::mushroom(){
    field[current_col][current_row] = 'x';
    events += "Collected Mushroom\n";
    if(mario->get_pwr_lvl() != 2){
        mario->add_power();
    }
    events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
    events += "Lives:" + std::to_string(mario->get_lives()) + "\n";
}

//Fights goomba and checks if Mario continues or fails the game
void Level::goomba(){
    if(enemy->fight_goomba() == 1){
        enemies_killed += 1;
        field[current_col][current_row] = 'x';
        events =+ "Fought goomba and won\n";
        if(enemies_killed == 7){
            mario->add_life();
        }
    }else{
        events += "Fought goomba and lost\n";
        if(mario->get_pwr_lvl() > 0){
            mario->remove_power();
        }else{
            if(mario->get_lives() == 0){
                end_game();
            }else{
                mario->remove_life();
            }
        }
    }
    events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
    events += "Lives:" + std::to_string(mario->get_lives()) + "\n";
}
//Changes variables to end the game when Mario loses
void Level::end_game(){
    keep_playing = false;
    is_alive = false;
    events += "You died\n";
}
//Fights Koopa and checks if Mario continues or not
void Level::koopa(){
    if(enemy->fight_koopa() == 1){
        events += "Fought koopa and won\n";
        enemies_killed += 1;
        field[current_col][current_row] = 'x';
        if(enemies_killed == 7){
            mario->add_life();
        }
    }else{
        events += "Fought koopa and lost\n";
        if(mario->get_pwr_lvl() > 0){
            mario->remove_power();
        }else{
            if(mario->get_lives() == 0){
                end_game();
            }else{
                mario->remove_life();
            }
        }
    }
    events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
    events += "Lives:" + std::to_string(mario->get_lives()) + "\n";
}

//Handles Mario leanding on empyt square
void Level::nothing(){
    events += "Landed on empty square \n";
    events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
    events += "Lives:" + std::to_string(mario->get_lives()) + "\n";
}

//Fights boss and ckecks if Mario moves on or not
int Level::boss(){
    if(enemy->fight_boss() == 1){
        enemies_killed += 1;
        field[current_col][current_row] = 'x';
        events += "Fought boss and won\n";
        if(enemies_killed == 7){
            mario->add_life();
        }
        events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
        events += "Lives:" + std::to_string(mario->get_lives()) + "\n";
        return 1;
    }else{
        events += "Fought boss and lost\n";
        if(mario->get_pwr_lvl() > 0){
            mario->remove_power();
        }else{
            if(mario->get_lives() == 0){
                end_game();
            }else{
                mario->remove_life();
            }
        }
        events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
        events += "Lives:" + std::to_string(mario->get_lives()) + "\n";
        return 0;
    }

}

//Moves Mario to the next Level
void Level::warp(){
    events += "Landed on warp pipe\n";
    keep_playing = false;
    events += "Coins:" + std::to_string(mario->get_coins()) + "\n";
    events += "Lives:" + std::to_string(mario->get_lives()) + "\n";
    events += "\n";
}

//Writes everything from events into the output file
void Level::write_events(){
    std::ofstream outputFile(output_file, std::ios_base::app);

    outputFile << events;

    outputFile.close();
    events = "";
}

//returns events
std::string Level::get_events(){
    return events;
}

//sets current level
void Level::set_current_level(int lvl){
    current_level = lvl;
}

//returns the amount of moves
int Level::get_moves(){
    return moves;
}