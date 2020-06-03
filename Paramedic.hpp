#pragma once
#include "Soldier.hpp"

using namespace std;


const int max_health_point = 100;
const int Damage = 50;


class Paramedic : public  Soldier {

public:

Paramedic(int num_p) : Soldier(max_health_point , Damage , num_p){}
Paramedic(int max_health_point , int damage , int num_p) : Soldier(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};

