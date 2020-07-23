#pragma once
#include "Sniper.hpp"



const int max_health_point_snipecom = 120;
const int Damage_snipecom = 100;


class SniperCommander : public  Sniper {

public:
SniperCommander(uint num_p) : Sniper(max_health_point_snipecom , Damage_snipecom , num_p){}
SniperCommander(uint max_health_point , uint damage , uint num_p) : Sniper(max_health_point , damage , num_p){}
/*as a sniper but all the other sniper attack as well*/
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
