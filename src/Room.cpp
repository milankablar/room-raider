/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#include <iostream>
#include "Room.h"

using namespace std;

int Room::getDoorNum(string direction) {
    if(direction == "north") {
        if(northDoor != nullptr) {
            return northDoor->getRoomNum();
        } else {
            return -1;
        }
    } else if(direction == "east") {
        if(eastDoor != nullptr) {
            return eastDoor->getRoomNum();
        } else {
            return -1;
        }
    } else if(direction == "south") {
        if(southDoor != nullptr) {
            return southDoor->getRoomNum();
        } else {
            return -1;
        }
    } else if(direction == "west") {
        if(westDoor != nullptr) {
            return westDoor->getRoomNum();
        } else {
            return -1;
        }
    } else {
        return -2;
    }
}

void Room::printDoors() {
    if(northDoor != nullptr) {
        cout << "north" << endl;
    }
    if(eastDoor != nullptr) {
        cout << "east" << endl;
    }
    if(southDoor != nullptr) {
        cout << "south" << endl;
    }
    if(westDoor != nullptr) {
        cout << "west" << endl;
    }
}