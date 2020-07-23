#include "Paramedic.hpp"

/* cure all the solider that are 1 step near him */
    void Paramedic :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
       //UP
       if ( i-1 >= 0 && board[i-1][j] != nullptr ){ //there is a footsoldier there
           if ( board[i-1][j]->getNum() == s->getNum() ){ //the same player
               board[i-1][j]->setHealth(board[i-1][j]->getMaxHealth()); //cure him
           }
       }
       //Down
       if ( i+1 <board.size() && board[i+1][j] != nullptr ){//there is a footsoldier there
           if ( board[i+1][j]->getNum() == s->getNum() ){//the same player
               board[i+1][j]->setHealth(board[i+1][j]->getMaxHealth());//cure him
           }
       }
       //left
        if ( j-1 >= 0 && board[i][j-1] != nullptr ){//there is a footsoldier there
           if ( board[i][j-1]->getNum() == s->getNum() ){//the same player
               board[i][j-1]->setHealth(board[i][j-1]->getMaxHealth());//cure him
           }
       }
       // Right
       if ( j+1< board[0].size() && board[i][j+1] != nullptr ){//there is a footsoldier there
           if ( board[i][j+1]->getNum() == s->getNum() ){//the same player
               board[i][j+1]->setHealth(board[i][j+1]->getMaxHealth());//cure him
           }
       }
        // Up and Left
        if ( i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] != nullptr ){//there is a footsoldier there
           if ( board[i-1][j-1]->getNum() == s->getNum() ){//the same player
               board[i-1][j-1]->setHealth(board[i-1][j-1]->getMaxHealth());//cure him
           }
       }
        // Up and Right
        if ( i-1 >= 0 && j+1< board[0].size() && board[i-1][j+1] != nullptr ){//there is a footsoldier there
           if ( board[i-1][j+1]->getNum() == s->getNum() ){//the same player
               board[i-1][j+1]->setHealth(board[i-1][j+1]->getMaxHealth());//cure him
           }
       }
       //Down and Left
          if ( i+1 <board.size() && j-1 >= 0 && board[i+1][j-1] != nullptr ){//there is a footsoldier there
           if ( board[i+1][j-1]->getNum() == s->getNum() ){//the same player
               board[i+1][j-1]->setHealth(board[i+1][j-1]->getMaxHealth());//cure him
           }
       }
       // Down and Right
        if ( i+1 <board.size() && j+1< board[0].size() && board[i+1][j+1] != nullptr ){//there is a footsoldier there
           if ( board[i+1][j+1]->getNum() == s->getNum() ){//the same player
               board[i+1][j+1]->setHealth(board[i+1][j+1]->getMaxHealth());//cure him
           }
       }
    }




