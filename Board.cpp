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
    while ( s == nullptr){

      
        Soldier *s = nullptr;
    int first = source.first;
    int second = source.second;
    int up=1 , right =1 , down =1 ,left=1;
        if (first -up >= 0 &&  board[first-up][second] != nullptr ) s= board[first-up][second];
        else if (first +down < board.size() &&  board[first+down][second] != nullptr ) s= board[first+down][second];
        else if (second -left >= 0 &&  board[first][second-left] != nullptr ) s= board[first][second-left];
        else if (second +right < board[0].size() &&  board[first][second+right] != nullptr ) s= board[first][second+right];
        //
        else if (first -up >= 0  && second -left >= 0  && board[first-up][second-left] != nullptr )  s= board[first-up][second-left];
        else if (first -up >= 0  && second +right < board[0].size() && board[first-up][second+right] != nullptr ) s= board[first-up][second+right];
        else if (first +down < board.size() && second +right < board[0].size() && board[first+down][second+right] != nullptr ) s= board[first+down][second+right];
        else if (first +down < board.size() && second -left >= 0  && board[first+down][second-left] != nullptr )  s= board[first+down][second-left];
    down++;
    up++;
        if (first -up >= 0  && second -left >= 0  && board[first-up][second-left] != nullptr )  s= board[first-up][second-left];
        else if (first -up >= 0  && second +right < board[0].size() && board[first-up][second+right] != nullptr ) s= board[first-up][second+right];
        else if (first +down < board.size() && second +right < board[0].size() && board[first+down][second+right] != nullptr ) s= board[first+down][second+right];
        else if (first +down < board.size() && second -left >= 0  && board[first+down][second-left] != nullptr )  s= board[first+down][second-left];

    left++;
    right++;

    */
    
    
    



}
