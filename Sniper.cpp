#include "Sniper.hpp"
#include "math.h"

using namespace std;

namespace WarGame{
// attack the strogest soldier (by his health points)
    void Sniper :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int num_player=s->getNum();
       Soldier *attack= findMax(board, location , num_player);
       int att = s->getDamge();
       int hel = attack->getHealth() - att;
       attack->setHealth(hel);
    }

//return the soldier with the max_health points
 Soldier* findMax(vector<vector<Soldier *>> &board,std::pair<int,int> location , uint player_number){
            int max_health=0;
            Soldier *s = nullptr;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr && i!=location.first && j!=location.second ){
                        if(board[i][j]->getNum()!=player_number){
                            if(board[i][j]->getHealth()>max_health){
                                max_health=board[i][j]->getHealth();
                                s=board[i][j];
                            }
                        }
                    }    
                }
            }
        return s;
        }


}