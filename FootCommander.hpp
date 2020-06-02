#pragma once
#include "Soldier.hpp"

using namespace std;


const int max_health_point = 150;
const int Damage = 20;

namespace WarGame{
class FootCommander : public  Soldier {

public:

FootCommander(int num_p) : Soldier(max_health_point , Damage , num_p){}
FootCommander(int max_health_point , int damage , int num_p) : Soldier(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
}