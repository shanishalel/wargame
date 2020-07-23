#include "Board.hpp"
#include <iostream>
#include <limits>
#include <math.h>
using namespace std;

namespace WarGame {


         Soldier*& Board :: operator[](std::pair<int,int> location){
             return board[location.first][location.second];
        }


        Soldier* Board:: operator[](std::pair<int,int> location) const{
            return  board[location.first][location.second];
        }

        
        void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction)
            {
                 if(source.first>=board.size() || source.second>=board.size()){
                    throw invalid_argument("invaild location");
                 }
                Soldier *src = board[source.first][source.second];
                if(src == nullptr)
                {
                    throw invalid_argument("No player on source");
                }
                if(src->getNum() != player_number)
                {
                    throw invalid_argument("Wrong player number");
                }
                // Up, Down, Right, Left
                pair<int,int> dest;
                switch(direction)
                {
                    case Up : dest = make_pair(source.first+1,source.second);
                    break;
                    case Down : dest = make_pair(source.first-1,source.second);
                    break;
                    case Right : dest = make_pair(source.first,source.second+1);
                    break;
                    case Left : dest = make_pair(source.first,source.second-1);
                    break;

                }
                if(dest.first < 0 || dest.second < 0 || dest.first >= board.size() || dest.second >= board[dest.first].size())
                {
                    throw invalid_argument("out of bounds"); 
                }
                if(board[dest.first][dest.second] != nullptr)
                {
                    throw invalid_argument("trying to move to a allocated space"); 
                }
                board[dest.first][dest.second] = src;
                board[source.first][source.second]= nullptr;
                src->attack(board,dest);
            }



         bool Board::has_soldiers(uint player_number) const {
            int count=0;
             for(int i=0; i<board.size();i++){
                 for(int j=0; j<board[i].size();j++){
                     Soldier* s= board[i][j];
                     if (s!=nullptr){
                     if( s->getNum()==player_number){
                        return true;
                     }
                     }
                 }

             }
             return false;
         }


       


  /*
    void Board::move(uint player_number, std::pair<int,int> source, MoveDIR direction) {
            int check =0;
            if ( player_number ==1 ) check =2;
            else check =1;
            //Down
            if (direction == Down){
            if(source.first - 1  < 0) throw ("std::invalid_argument");
             else if (board[source.first-1][source.second] != nullptr) throw ("std::invalid_argument");
                Soldier *s = board[source.first][source.second];
                board[source.first][source.second] = nullptr; // to check
                board[source.first-1][source.second] = s;
                s->attack( board ,{source.first-1,source.second} );
            }
            // UP
            if (direction == Up){
            if(source.first + 1  >= board.size()) throw ("std::invalid_argument");
             else if (board[source.first+1][source.second] != nullptr) throw ("std::invalid_argument");            
                Soldier *s = board[source.first][source.second];
                if(s==nullptr){throw ("std::invalid_argument");
                }
                board[source.first+1][source.second] = s;
               board[source.first][source.second] = nullptr; // to check 
                s->attack( board ,{source.first+1,source.second});
            }
            //Left
            if (direction == Left){
            if(source.second -1 < 0) throw ("std::invalid_argument");
             else if (board[source.first][source.second-1] != nullptr) throw ("std::invalid_argument");
                Soldier *s = board[source.first][source.second];
                board[source.first][source.second] = nullptr; // to check
                board[source.first][source.second-1] = s;
                s->attack( board ,{source.first,source.second-1} );
            }
            //Right
            if (direction == Right){
            if(source.second + 1  >= board[0].size()) throw ("std::invalid_argument");
             else if (board[source.first][source.second+1] != nullptr) throw ("std::invalid_argument");
                Soldier *s = board[source.first][source.second];
                board[source.first][source.second] = nullptr; // to check
                board[source.first][source.second+1] = s;
                s->attack( board ,{source.first,source.second+1} );
            }


        }

    */
    
    
    



}
