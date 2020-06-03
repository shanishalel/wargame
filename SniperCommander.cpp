#include "SniperCommander.hpp"

using namespace std;


//pass through the board and call every sniper in the board that in the same player
    void  SniperCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
      for (int i = 0; i < board.size(); i++)
      {
          for (int i = 0; i < board[0].size(); i++)
          {
                 Soldier *a=board[i][j];
                 if( a != nullptr){
                 if(   Sniper *fs = dynamic_cast< Sniper*> (a)){
                      SniperCommander *footcom = dynamic_cast< SniperCommander*> (a);
                     if ( footcom == nullptr || ( i == location.first && j == location.second)) {                     
                     if ( fs->getNum() == s->getNum()){
                         fs->Sniper::attack(board , {i,j});
                     }
                    }
                 }  
             }
          }   
      }
    }
