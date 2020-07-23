#include "Paramedic.hpp"


void Paramedic::attack(vector<vector<Soldier *>> &board, pair<int, int> dest)
{
    int iter = 1;
    for (int x = -iter; x <= iter; x++)
    {

        Soldier *s;
        // iter,x
        if (dest.first + iter >= 0 && dest.first + iter < board.size())
        {
            if (dest.second + x >= 0 && dest.second + x < board[dest.first + iter].size())
            {
                s = board[dest.first + iter][dest.second + x];
                if (s != nullptr && s->getNum() == board[dest.first][dest.second]->getNum())
                {
                    s->setHealth(s->getMaxHealth());
                }
            }
        }
        // -iter,x
        if (dest.first - iter >= 0 && dest.first - iter < board.size())
        {
            if (dest.second + x >= 0 && dest.second + x < board[dest.first - iter].size())
            {
                s = board[dest.first - iter][dest.second + x];
                if (s != nullptr && s->getNum() == board[dest.first][dest.second]->getNum())
                {
                     s->setHealth(s->getMaxHealth());
                }
            }
        }

        //x,-iter
        if (dest.first + x >= 0 && dest.first + x < board.size())
        {
            if (dest.second - iter >= 0 && dest.second - iter < board[dest.first + x].size())
            {
                s = board[dest.first + x][dest.second - iter];
                if (s != nullptr && s->getNum() == board[dest.first][dest.second]->getNum())
                {
                    s->setHealth(s->getMaxHealth());
                }
            }
        }
        //x,iter
        if (dest.first + x >= 0 && dest.first + x < board.size())
        {
            if (dest.second + iter >= 0 && dest.second + iter < board[dest.first + x].size())
            {
                s = board[dest.first + x][dest.second + iter];
                if (s != nullptr && s->getNum() == board[dest.first][dest.second]->getNum())
                {
                    s->setHealth(s->getMaxHealth());
                }
            }
        }
    }
}




/*
   //cure all te soldier that are 1 step close to him of the same player
    void Paramedic :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int i=location.first;
       int j=location.second;
       //UP
       if ( i-1 >= 0 && board[i-1][j] != nullptr ){
           if ( board[i-1][j]->getNum() == s->getNum() ){
               board[i-1][j]->setHealth(board[i-1][j]->getMaxHealth());
           }
       }
       //Down
       if ( i+1 <board.size() && board[i+1][j] != nullptr ){
           if ( board[i+1][j]->getNum() == s->getNum() ){
               board[i+1][j]->setHealth(board[i+1][j]->getMaxHealth());
           }
       }
       //left
        if ( j-1 >= 0 && board[i][j-1] != nullptr ){
           if ( board[i][j-1]->getNum() == s->getNum() ){
               board[i][j-1]->setHealth(board[i][j-1]->getMaxHealth());
           }
       }
       // Right
       if ( j+1< board[0].size() && board[i][j+1] != nullptr ){
           if ( board[i][j+1]->getNum() == s->getNum() ){
               board[i][j+1]->setHealth(board[i][j+1]->getMaxHealth());
           }
       }
        // Up and Left
        if ( i-1 >= 0 && j-1 >= 0 && board[i-1][j-1] != nullptr ){
           if ( board[i-1][j-1]->getNum() == s->getNum() ){
               board[i-1][j-1]->setHealth(board[i-1][j-1]->getMaxHealth());
           }
       }
        // Up and Right
        if ( i-1 >= 0 && j+1< board[0].size() && board[i-1][j+1] != nullptr ){
           if ( board[i-1][j+1]->getNum() == s->getNum() ){
               board[i-1][j+1]->setHealth(board[i-1][j+1]->getMaxHealth());
           }
       }
       //Down and Left
          if ( i+1 <board.size() && j-1 >= 0 && board[i+1][j-1] != nullptr ){
           if ( board[i+1][j-1]->getNum() == s->getNum() ){
               board[i+1][j-1]->setHealth(board[i+1][j-1]->getMaxHealth());
           }
       }
       // Down and Right
        if ( i+1 <board.size() && j+1< board[0].size() && board[i+1][j+1] != nullptr ){
           if ( board[i+1][j+1]->getNum() == s->getNum() ){
               board[i+1][j+1]->setHealth(board[i+1][j+1]->getMaxHealth());
           }
       }
    }

*/


