/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef MAZE_H
#define MAZE_H

#include "Room.h"
#include <iostream>

/**
 * @class Maze
 * @author student
 * @date 03/05/20
 * @file Maze.h
 * @brief This class represents a maze which has an array of rooms.
 */
class Maze {
private:
    Room ** rooms;
    int numRooms;
    
public:
    Maze(int numRooms) {
        this->numRooms = numRooms;
        rooms = new Room*[numRooms];
        for(int i = 0; i < numRooms; ++i) {
            rooms[i] = new Room(i);
        }
    }
    
    ~Maze() {
        delete [] rooms;
    }
    
    int getNumRooms() {
        return numRooms;
    }
    
    Room* getRoom(int roomIndex) const {
        return rooms[roomIndex];
    }
    
    /**
     * @brief This method returns a boolean if the maze contains an item of a specified type.
     * @param type
     * @return boolean
     */
    bool containsType(std::string type);

    /**
     * @brief This method facilitates a one way connection between two rooms in a direction.
     * @param srcRoomNum
     * @param dstRoomNum
     * @param direction
     */
    void addDoor(int srcRoomNum, int dstRoomNum, std::string direction);
};

#endif