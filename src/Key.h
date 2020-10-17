/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef KEY_H
#define KEY_H

#include "Item.h"

/**
 * @class Key
 * @author student
 * @date 03/05/20
 * @file Key.h
 * @brief This class represents a key item and stores it's name.
 */
class Key : public Item {
private:
public:
    Key(std::string name) {
        this->name = name;
        this->type = "key";
    }
};

#endif