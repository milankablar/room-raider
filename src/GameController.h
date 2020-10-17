/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H

#include "Maze.h"
#include "Player.h"
#include "Key.h"
#include "Treasure.h"
#include "Teleporter.h"
#include "Exit.h"
#include <fstream>
#include <iostream>

/**
 * @class GameController
 * @author student
 * @date 03/05/20
 * @file GameController.h
 * @brief This class in where the game runs and the user can perform commands.
 */
class GameController {
private:
    Maze * maze;
    Player * player;
public:
    GameController() { }
    
    /**
     * @brief This method will run the game when called.
     */
    void run();
    
    /**
     * @brief This helper methods takes in a string and returns it's lowercase form.
     * @param str string
     * @return lowercase string
     */
    std::string lowerString(std::string str);
    
    /**
     * @brief This method moves the player from it's room to another room in the specified direction.
     * @param direction
     */
    void moveCommand(std::string direction);
    
    /**
     * @brief This method moves an item that is in the room to the player's bag.
     * @param itemName
     */
    void takeCommand(std::string itemName);
    
    /**
     * @brief This method moves an item that is in the player's bag to the room.
     * @param itemName
     */
    void dropCommand(std::string itemName);
    
    /**
     * @brief Thie method moves the player in to the specified room if they have a teleporter item.
     */
    void teleportCommand(int roomNum);
    
    /**
     * @brief This method prints the contents of the player's bag.
     */
    void showbagCommand();
    
    /**
     * @brief This method unlocks the exit to the maze.
     */
    void unlockCommand();
    
    /**
     * @brief This method prints out a list of commands and a short description of each.
     * @param filename
     */
    void helpCommand();
    
    /**
     * @brief This method displays the enter room message.
     */
    void displayEnterRoomMessage();
    
    /**
     * @brief This method loads in a file containing the game configuration.
     * @param filename
     */
    void loadFile(std::string filename);
};

#endif