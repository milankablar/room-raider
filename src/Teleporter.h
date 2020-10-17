/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef TELEPORTER_H
#define TELEPORTER_H

#include "Item.h"

/**
 * @class Teleporter
 * @author student
 * @date 03/05/20
 * @file Teleporter.h
 * @brief This class represents a teleporter item and stores it's name.
 */
class Teleporter : public Item {
private:
public:
    Teleporter(std::string name) {
        this->name = name;
        this->type = "teleporter";
    }
};

#endif