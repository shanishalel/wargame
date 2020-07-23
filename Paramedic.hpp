#pragma once
#include "Soldier.hpp"


const int max_health_point_para = 100;
const int Damage_para = 50;


class Paramedic : public  Soldier {


public:

Paramedic(uint num_p) : Soldier(max_health_point_para , Damage_para , num_p){}
Paramedic(uint max_health_point , uint damage , uint num_p) : Soldier(max_health_point , damage , num_p){}
/*cure all the solider that are 1 step near him*/
void attack(vector<vector<Soldier *>> &board, pair<int, int> location);

};

