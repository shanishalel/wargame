#include "Board.hpp"
namespace WarGame {


         Soldier*& Board :: operator[](std::pair<int,int> location){

             board[location.first][location.second] = this;
             return *board;
        }


        Soldier* Board:: operator[](std::pair<int,int> location) const{
            return  board[location.first][location.second];
        }

        void move(uint player_number, std::pair<int,int> source, MoveDIR direction) {

        }

         bool has_soldiers(uint player_number) {


         }
}
