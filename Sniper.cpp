#include "Sniper.hpp"
#include "math.h"

using namespace std;



void Sniper::attack(vector<vector<Soldier*>> &board,pair<int,int> dest)
{
    uint maxHP=0;
    Soldier *maxHPs=nullptr;
    int maxi=0;
    int maxj=0;

    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board[i].size();j++)
        {

            if(board[i][j]!=nullptr && board[i][j]->getNum() != board[dest.first][dest.second]->getNum())
            {
                if(board[i][j]->getHealth() > maxHP)
                {
                    maxHPs = board[i][j];
                    maxHP = board[i][j]->getHealth();
                    maxi = i;
                    maxj= j;
                }
            }
        }
    }
    if(maxHPs!=nullptr)
    {
    // maxHPs->setHP(maxHPs->getCurrHP()-board[dest.first][dest.second]->getact());
    // if(maxHPs->getCurrHP() <= 0)
    // {
    //     board[maxi][maxj] = nullptr;
    // }
    int hp = maxHPs->getHealth()-board[dest.first][dest.second]->getDamge();
    if(hp <= 0)
    {
        board[maxi][maxj] = nullptr;
    }
    else
    {
        maxHPs->setHealth(hp);
    }
    
    }
}






/*

// attack the strogest soldier (by his health points)
    void Sniper :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int num_player=s->getNum();
        // Soldier *attack= findMax(board, location , num_player);
       
        int max_health=0;
            Soldier *attack = nullptr;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr){
                        if(board[i][j]->getNum()!=num_player){
                            if(board[i][j]->getHealth()>max_health){
                                max_health=board[i][j]->getHealth();
                                attack=board[i][j];
                            }
                        }
                    }    
                }
            }
       if ( attack == nullptr){
           cout << " i am nullptr" << endl;
       }
       
       int att = s->getDamge();
      int hel = attack->getHealth() - att;
       attack->setHealth(hel);
    }
*/

/*
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
*/
