#pragma once
#include "Soldier.hpp"

using namespace std;


const int max_health_point = 100;
const int Damage = 10;


class FootSoldier : public  Soldier {

public:

FootSoldier(int num_p) : Soldier(max_health_point , Damage , num_p){}
FootSoldier(int max_health_point , int damage , int num_p) : Soldier(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);
Soldier* checkClose(vector<vector<Soldier *>> &board,std::pair<int,int> source , uint player_number);

};
