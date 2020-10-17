/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef TREASURE_H
#define TREASURE_H

#include "Item.h"

/**
 * @class Treasure
 * @author student
 * @date 03/05/20
 * @file Treasure.h
 * @brief This class represents a treasure item and stores it's name.
 */
class Treasure : public Item {
private:
public:
    Treasure(std::string name) {
        this->name = name;
        this->type = "treasure";
    }
};

#endif