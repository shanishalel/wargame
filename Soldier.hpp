#pragma once
#include <stdlib.h>
#include <iostream>

class Soldier{
    public:
    int  health_points;
    int damage;
    int num_player;

    Soldier(){}

    int getNum(){
        return num_player;
    }
    int getHealth(){
        return health_points;
    }
    int getDamge(){
        return damage;
    }
    void attack(Soldier s);

};
