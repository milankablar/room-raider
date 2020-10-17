/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef BAG_H
#define BAG_H

/**
 * @class Bag
 * @author student
 * @date 03/05/20
 * @file Bag.h
 * @brief This class represents a bag which is a type of container and holds 10 items.
 */
class Bag : public Container { 
private:
    
public:
    Bag() : Container(10) { }
};

#endif