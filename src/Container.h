/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#ifndef CONTAINER_H
#define CONTAINER_H

#include "Item.h"
#include "Key.h"
#include "Teleporter.h"
#include "Treasure.h"
#include "Exit.h"

/**
 * @class Container
 * @author student
 * @date 03/05/20
 * @file Container.h
 * @brief This class represents a container which can be a room or a bag which stores items.
 */
class Container {
private:
    Item ** items;
    int numItems = 0;
    int maxItems = 0;
    
public:
    Container(int maxItems)  {
        this->maxItems = maxItems;
        items = new Item*[maxItems];
        for(int i = 0; i < maxItems; ++i) {
            items[i] = new Item();
        }
    }
    
    ~Container() {
        delete [] items;
    }
    
    int getNumItems() {
        return numItems;
    }
    
    Item* getItem(int index) const {
        if(index < numItems && index >= 0) {
            return items[index];
        } else {
            return nullptr;
        }
    }
    
    /**
     * @brief This method removes an item from the items array at the specified index.
     * @param index
     */
    void removeItem(int index);
    
    /**
     * @brief This method returns the index of an item name in the container.
     * If the item is not in the container, -1 is returned.
     * @param name
     * @return index of item
     */
    int indexOfItemName(std::string name);
    
    /**
     * @brief This method returns the index of an item type in the container.
     * If the item is not in the container, -1 is returned.
     * @param name
     * @return index of item
     */
    int indexOfItemType(std::string type);
    
    /**
     * @brief This method returns a boolean if the container contains the specified item type.
     * @param type
     * @return boolean
     */
    bool containsType(std::string type);
    
    
    /**
     * @brief This method creates and adds an item to the items array.
     * @param itemType
     * @param itemName
     */
    void createItem(std::string itemType, std::string itemName);
    
    /**
     * @brief This method prints the item names that are in a container (room or bag).
     */
    void printItemNames();
    
    /**
     * @brief This method prints the item names and types that are in a container (room or bag).
     */
    void printItemNamesAndTypes();
};

#endif