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
public:

    Player(int p){
        player = p;
    }

    virtual ~Player(){}

    virtual void getMove(Board *board, int &x, int &y) = 0;

    int getplayer() {
        return player;
    }
};


#endif // PLAYER_H