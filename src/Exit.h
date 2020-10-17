/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef EXIT_H
#define EXIT_H

#include "Item.h"

/**
 * @class Exit
 * @author student
 * @date 03/05/20
 * @file Exit.h
 * @brief This class represents an exit item which is used to unlock the end of the game.
 */
class Exit : public Item {
private:
public:
    Exit(std::string name) {
        this->name = name;
        this->type = "exit";
    }
    
};

#endif