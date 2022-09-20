/*
 * Player.h
 *
 *  Created on: 16 Aug. 2020
 *      Author: dongmo
 * 
 * Repurposed for this Assignment
 */

#ifndef PLAYER
#define PLAYER


using namespace std;
class Player
{
protected:
    int player;
    string name;
public:

    Player(int p, string n){
        player = p;
        name = n;
    }

    virtual ~Player(){}

    virtual void getMove(Board *board, int &x, int &y) = 0;

    int getplayer() {
        return player;
    }

    string getName(){
        return name;
    }
};


#endif // PLAYER_H