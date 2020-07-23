#pragma once
#include "Soldier.hpp"

using namespace std;

const int max_health_point_foot = 100;
const int Damage_foot = 10;


class FootSoldier : public  Soldier {



public:

FootSoldier(uint num_p) : Soldier(max_health_point_foot , Damage_foot , num_p){}
FootSoldier(uint max_health_point , uint damage , uint num_p) : Soldier(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);
//Soldier* checkClose(vector<vector<Soldier *>> &board,std::pair<int,int> location , uint player_number);

};
