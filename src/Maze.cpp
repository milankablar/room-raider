/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */

#include "Maze.h"
#include <iostream>
 
using namespace std;

void Maze::addDoor(int srcRoomNum, int dstRoomNum, string direction) {
    Room* srcRoom = rooms[srcRoomNum];
    Room* dstRoom = rooms[dstRoomNum];
    if(direction == "north") {
        srcRoom->setNorthDoor(dstRoom); 
    } else if(direction == "east") {
        srcRoom->setEastDoor(dstRoom); 
    } else if(direction == "south") {
        srcRoom->setSouthDoor(dstRoom); 
    } else if(direction == "west") {
        srcRoom->setWestDoor(dstRoom); 
    } else {
        cout << "ERROR: Invalid room direction" << endl;
    }
}

bool Maze::containsType(string type) {
    for(int i = 0; i < numRooms; ++i) {
        for(int j = 0; j < getRoom(i)->getNumItems(); ++j) {
            if(getRoom(i)->getItem(j)->getType() == type) {
                return true;
            }
        }
    }
    return false;
}