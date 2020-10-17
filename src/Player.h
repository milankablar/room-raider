/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef PLAYER_H
#define PLAYER_H

#include "Bag.h"

/**
 * @class Player
 * @author student
 * @date 03/05/20
 * @file Player.h
 * @brief This class represents a player which carries a bag and is in a room.
 */
class Player {
private:
    Bag * bag;
public:
    int currentRoomNum;
    
    Player(int startingRoomNum) {
        currentRoomNum = startingRoomNum;
        bag = new Bag();
    }
    
    void setCurrentRoomNum(int roomNum) {
        currentRoomNum = roomNum;
    }
    
    Bag* getBag() {
        return bag;
    }
};

#endif