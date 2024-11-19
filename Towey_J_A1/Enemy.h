#ifndef ENEMY_H
#define ENEMY_H

//Enemy object which holds the functions that handle whether Mario beat and enemy or not
class Enemy{
    public:
        Enemy();
        ~Enemy();

        int fight_koopa();
        int fight_goomba();
        int fight_boss();
    private:

};
#endif
