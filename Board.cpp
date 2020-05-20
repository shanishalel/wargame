#include "Board.hpp"
#include <iostream>
using namespace std;

namespace WarGame {


         Soldier*& Board :: operator[](std::pair<int,int> location){
             return board[location.first][location.second];
        }


        Soldier* Board:: operator[](std::pair<int,int> location) const{
            return  board[location.first][location.second];
        }

        void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {

        }

         bool Board::has_soldiers(uint player_number) const {
            int count=0;
             for(int i=0; i<board.size();i++){
                 for(int j=0; j<board[i].size();j++){
                     Soldier* s= board[i][j];
                     if(s!=nullptr && s->num_player==player_number){
                        return true;
                     }
                 }

             }
             return false;
         }
}
