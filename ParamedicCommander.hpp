#pragma once
#include "Paramedic.hpp"

using namespace std;


const int max_health_point = 100;
const int Damage = 200;


class ParamedicCommander : public  Paramedic {

public:

ParamedicCommander(int num_p) : Paramedic(max_health_point , Damage , num_p){}
ParamedicCommander(int max_health_point , int damage , int num_p) : Paramedic(max_health_point , damage , num_p){}
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};
