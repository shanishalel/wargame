#pragma once
#include "Soldier.hpp"


const int max_health_point_foot = 100;
const int Damage_foot = 10;


class FootSoldier : public  Soldier {



public:

FootSoldier(uint num_p) : Soldier(max_health_point_foot , Damage_foot , num_p){}
FootSoldier(uint max_health_point , uint damage , uint num_p) : Soldier(max_health_point , damage , num_p){}
/*shoot the solider that is the closest to him*/
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
