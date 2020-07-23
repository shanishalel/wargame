#include "FootCommander.hpp"

using namespace std;

/* the footcommander made all his footsoliders attack */
    void FootCommander :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
      for (int i = 0; i < board.size(); i++) {
          for (int j = 0; j < board[0].size(); j++){
                 Soldier *a=board[i][j];
                 if( a != nullptr){
                    if(  FootSoldier *fs = dynamic_cast<FootSoldier*> (a)){ //check that it is a footsolider
                        FootCommander *footcom = dynamic_cast<FootCommander*> (a); //if the solider is an footcommander solider
                       //if it isn't a footcommander or it's the location we in
                        if ( footcom == nullptr || ( i == location.first && j == location.second)) {                     
                            if ( fs->getNum() == s->getNum()){ //the same player
                                if ( fs != nullptr){//there is a footsoldier there
                                    fs->FootSoldier::attack(board , {i,j});
                                }
                            }
                        }
                    }
                }
          }
          
      }

    }


