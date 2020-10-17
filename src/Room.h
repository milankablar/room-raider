/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef ROOM_H
#define ROOM_H

#include "Container.h"
#include "Item.h"
#include "Key.h"
#include "Treasure.h"
#include "Teleporter.h"
#include "Exit.h"

/**
 * @class Room
 * @author student
 * @date 03/05/20
 * @file Room.h
 * @brief This class represents a Room which has doors in cardinal directions, 
 * is a container and holds 10 items.
 */
class Room : public Container {
private:
    Room * northDoor = nullptr;
    Room * eastDoor = nullptr;
    Room * southDoor = nullptr;
    Room * westDoor = nullptr;
    int roomNum;
    
public:
    Room(int roomNum) : Container(5) {
        this->roomNum = roomNum;
    } 
    
    int getRoomNum() {
        return roomNum;
    }
    
    void setNorthDoor(Room* room) {
        northDoor = room;
    }
    
    void setEastDoor(Room* room) {
        eastDoor = room;
    }
    
    void setSouthDoor(Room* room) {
        southDoor = room;
    }
    
    void setWestDoor(Room* room) {
        westDoor = room;
    }
    
    /**
     * @brief This method returns the room number of a room in the specified direction.
     * @param direction 
     * @return room number
     */
    int getDoorNum(std::string direction);
    
    /**
     * @brief This prints the directions that doors exist in.
     */
    void printDoors();
    
};

#endif