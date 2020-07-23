#include "FootSoldier.hpp"
#include "math.h"

/* shoot the solider that is the closest to him */
void FootSoldier::attack(vector<vector<Soldier *>> &board, pair<int, int> dest)
{

    double closest=board.size()*board.size();
    int ci,cj;
    int found =0;
    
    for(int i=0;i<board.size();i++)
    {
        for(int j=0;j<board.size();j++)
        {
            Soldier *s;
            s= board[i][j];
            //check all the board and save the closest until there
            if(s!=nullptr && (s->getNum() != board[dest.first][dest.second]->getNum())) // isn't the same player
            {
                //distance= sqrt[(x1-x2)^2+(y1-y2)^2]
                double dist = sqrt((i-dest.first)*(i-dest.first) + (j-dest.second)*(j-dest.second)); 
                if(dist<closest)
                {
                    closest =dist;
                    ci = i;
                    cj = j;
                    found = 1;
                }
            }
        }
    }

    if(found){ // found=1
        Soldier *s = board[ci][cj];
        int hp = s->getHealth() - board[dest.first][dest.second]->getDamge();//the shoot 
        if(hp <= 0){//he is dead
            board[ci][cj] = nullptr;
        }
        else{//he is damage
            s->setHealth(hp);
        }
        
        
    }
}







    /*
    //move 1 step every direction and shot on soldier that is the closest to him
    //gets the board and the location of the soldier
    void FootSoldier :: attack(vector<vector<Soldier *>> &board, pair<int, int> location){
       Soldier *s = board[location.first][location.second];
       int num_player=s->getNum();
      // Soldier *attack= checkClose(board, location , num_player);
        int v=0 , z=0;
         int min_dis=99999999;
            Soldier *attack = nullptr;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr ){
                        if(board[i][j]->getNum()!=num_player){
                            int temp=sqrt(pow(i-location.first,2)+pow(j-location.second,2)); //distance
                            if(temp<min_dis){
                                min_dis=temp;
                                attack=board[i][j];
                                v=i;
                                z=j;
                            }
                        }
                    }    
                }
            }


       int att = s->getDamge();
       int hel = attack->getHealth() - att;
       attack->setHealth(hel);
       if(attack->getHealth() <= 0){
           board[v][z] = nullptr;
       }
    }
    


//return the soldier that we need to attack (get our player number)
 Soldier* checkClose(vector<vector<Soldier *>> &board,std::pair<int,int> location , uint player_number){
            int min_dis=99999999;
            Soldier *s = nullptr;
            for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]!=nullptr && i!=location.first && j!=location.second ){
                        if(board[i][j]->getNum()!=player_number){
                            int temp=sqrt(pow(i-location.first,2)+pow(j-location.second,2)); //distance
                            if(temp<min_dis){
                                min_dis=temp;
                                s=board[i][j];
                            }
                        }
                    }    
                }
            }
        return s;

        }

*/
