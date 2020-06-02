#pragma once
#include "Sniper.hpp"

using namespace std;


const int max_health_point = 120;
const int Damage = 100;

namespace WarGame{
class SniperCommander : public  Sniper {

public:
SniperCommander(int num_p) : Sniper(max_health_point , Damage , num_p){}
SniperCommander(int max_health_point , int damage , int num_p) : Sniper(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
}