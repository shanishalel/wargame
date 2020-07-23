#include "SniperCommander.hpp"

using namespace std;


/*as a sniper but all the other sniper attack as well*/
 void SniperCommander::attack(vector<vector<Soldier*>> &board,pair<int,int> dest) {
    for(int i=0;i<board.size();i++){
        for(int j=0;j<board[i].size();j++){
            Soldier *s = board[i][j];
            if(s!=nullptr){ 
                if(Sniper *fs = dynamic_cast<Sniper*> (s)){//he is a sniper
                    SniperCommander *fc = dynamic_cast<SniperCommander*> (s); 
                    //if he isn't a sniper commander/ he is the location we are
                    if((fc == nullptr) || (i == dest.first && j==dest.second)){ 
                        if(fs->getNum() == board[dest.first][dest.second]->getNum()){//same player
                            fs->Sniper::attack(board,make_pair(i,j));
                        
                        }
                    }  
                    
                }
            }
        }
    }
    }



/*
//pass through the board and call every sniper in the board that in the same player
    void  SniperCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
      for (int i = 0; i < board.size(); i++)
      {
          for (int j = 0; j < board[0].size(); j++)
          {
                 Soldier *a=board[i][j];
                 if( a != nullptr){
                 if( Sniper *fs = dynamic_cast< Sniper*> (a)){
                      SniperCommander *footcom = dynamic_cast< SniperCommander*> (a);
                     if ( footcom == nullptr || ( i == location.first && j == location.second)) {                     
                     if ( fs->getNum() == s->getNum()){
                        if ( fs != nullptr){
                         fs->Sniper::attack(board , {i,j});
                        }
                     }
                    }
                 }  
             }
          }   
      }
    }
*/