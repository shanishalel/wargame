#include "Sniper.hpp"
#include "math.h"

using namespace std;


/*attack the strogest soldier by his health points */
    void Sniper :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       int num_player=board[location.first][location.second]->getNum();       
            int max_health=0;
            Soldier *attack = nullptr;
            int first=0;
            int second=0;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr){
                        if(board[i][j]->getNum()!=num_player){//not the same player
                           /*check on all the board if there is an point that are bigger than them
                           if there is so we will save him and his location */
                            if(board[i][j]->getHealth()>max_health){ 
                                attack=board[i][j];
                                max_health=board[i][j]->getHealth();
                                first=i;
                                second=j;
                            }
                        }
                    }    
                }
            }
        //there is some soldier with the highest points
       if ( attack != nullptr){
            int att = board[location.first][location.second]->getDamge();//damage he lets to the other soldier
            int hel = attack->getHealth() - att; //attack him
            if(hel <= 0){ //dead
                board[first][second]=nullptr;
            }
            else{ //got hurt
                attack->setHealth(hel);
            }
        }
       
    }  
    


