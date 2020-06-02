#pragma once
#include "Soldier.hpp"

using namespace std;


const int max_health_point = 100;
const int Damage = 50;

namespace WarGame{
class Sniper : public  Soldier {

public:

Sniper(int num_p) : Soldier(max_health_point , Damage , num_p){}
Sniper(int max_health_point , int damage , int num_p) : Soldier(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
}
