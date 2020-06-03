#include "FootSoldier.hpp"
#include "math.h"

using namespace std;


    //move 1 step every direction and shot on soldier that is the closest to him
    //gets the board and the location of the soldier
    void FootSoldier :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int num_player=s->getNum();
      // Soldier *attack= checkClose(board, location , num_player);
       
         int min_dis=99999999;
            Soldier *attack = nullptr;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr && i!=location.first && j!=location.second ){
                        if(board[i][j]->getNum()!=num_player){
                            int temp=sqrt(pow(i-location.first,2)+pow(j-location.second,2)); //distance
                            if(temp<min_dis){
                                min_dis=temp;
                                attack=board[i][j];
                            }
                        }
                    }    
                }
            }


       int att = s->getDamge();
       int hel = attack->getHealth() - att;
       attack->setHealth(hel);
    }

/*
//return the soldier that we need to attack (get our player number)
 Soldier* checkClose(vector<vector<Soldier *>> &board,std::pair<int,int> location , uint player_number){
            int min_dis=99999999;
            Soldier *s = nullptr;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr && i!=location.first && j!=location.second ){
                        if(board[i][j]->getNum()!=player_number){
                            int temp=sqrt(pow(i-location.first,2)+pow(j-location.second,2)); //distance
                            if(temp<min_dis){
                                min_dis=temp;
                                s=board[i][j];
                            }
                        }
                    }    
                }
            }
        return s;

        }
*/

