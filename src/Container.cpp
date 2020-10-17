/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#include <iostream>
#include "Container.h"
 
using namespace std;

void Container::createItem(string itemType, string itemName) {
    if(itemType == "key") {
        items[numItems] = new Key(itemName);
    } else if(itemType == "treasure") {
        items[numItems] = new Treasure(itemName);
    } else if(itemType == "teleporter") {
        items[numItems] = new Teleporter(itemName);
    } else if(itemType == "exit") {
        items[numItems] = new Exit(itemName);
    } else {
        cout << "ERROR: Invalid item type" << endl;
    }
    ++numItems;
}

void Container::removeItem(int index) {
    if(index < numItems && index >= 0) {
        numItems = numItems - 1;
        for(int i = index; i < numItems; ++i) {
            items[i] = items[i+1];
        }
    } 
}
    
void Container::printItemNames() {
    for(int i = 0; i < numItems; ++i) {
        cout << items[i]->name << endl;
    }
}

int Container::indexOfItemName(string name) {
    for(int i = 0; i < getNumItems(); ++i) {
        if(getItem(i)->getName() == name) {
            return i;
        }
    }
    return -1;
}

int Container::indexOfItemType(string type) {
    for(int i = 0; i < getNumItems(); ++i) {
        if(getItem(i)->getType() == type) {
            return i;
        }
    }
    return -1;
}

bool Container::containsType(string type) {
    for(int j = 0; j < getNumItems(); ++j) {
        if(getItem(j)->getType() == type) {
            return true;
        }
    }
    return false;
}

void Container::printItemNamesAndTypes() {
    for(int i = 0; i < numItems; ++i) {
        cout << items[i]->name << " - " << items[i]->type << endl;
    }
}