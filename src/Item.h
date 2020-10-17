/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef ITEM_H
#define ITEM_H

#include <string>

/**
 * @class Item
 * @author student
 * @date 03/05/20
 * @file Item.h
 * @brief This class represents an item and stores it's name.
 */
class Item {
private:
public:
    std::string name;
    std::string type;
    
    Item() { }
    
    Item(std::string name) {
        this->name = name;
    }
    
    std::string getName() {
        return name;
    }
    
    std::string getType() {
        return type;
    }
};

#endif