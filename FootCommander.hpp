#pragma once
#include "FootSoldier.hpp"


const int max_health_point_footcom = 150;
const int Damage_footcom = 20;

class FootCommander : public  FootSoldier {



public:

FootCommander(int num_p) : FootSoldier(max_health_point_footcom , Damage_footcom , num_p){}
FootCommander(int max_health_point , int damage , int num_p) : FootSoldier(max_health_point , damage , num_p){}
/* the footcommander call all his footsoliders to attack and he attack too */
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
