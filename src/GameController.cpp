/*
 * Course:      CS 2040-011
 * Term:        Spring 2020
 * Assignment:  Lab 6 - Room Raider
 * Author:      Milan Kablar
 * Date:        5/1/2020
 */
 
#include "GameController.h"
#include <string> 

 
using namespace std;

void GameController::run() {
    std::string filename;
    string command;
    cout << "Welcome to Room Raider" << endl;
    cout << std::endl;
    
    bool validFile = false;
    while(!validFile) {
        cout << "Please enter the path to your game configuration file: " << endl;
        cin >> filename;
        loadFile(filename);
        
        if(maze->containsType("exit") && maze->containsType("key")) {
            validFile = true;
        }
        
        if(!validFile) {
            cout << "There is not at least one exit and one key in the maze" << endl;
        }
    }
    
    cout << endl;

    displayEnterRoomMessage();
    
    while(command != "exit" && command != "unlock") {
        cout << "What would you like to do?" << endl;
        cin >> command;
        command = lowerString(command);
        
        if(command == "move") {
            string direction;
            cin >> direction;
            direction = lowerString(direction);
            cout << endl;
            moveCommand(direction);
        } else if(command == "take") {
            string itemName;
            cin >> itemName;
            cout << endl;
            takeCommand(itemName);
        } else if(command == "drop") {
            string itemName;
            cin >> itemName;
            cout << endl;
            dropCommand(itemName);
        } else if(command == "teleport") {
            int roomNum;
            cin >> roomNum;
            cout << endl;
            teleportCommand(roomNum);
        } else if(command == "showbag") {
            cout << endl;
            showbagCommand();
        } else if(command == "help") {
            cout << endl;
            helpCommand();
        } else if(command == "unlock") {
            cout << endl;
            unlockCommand();
        } else if(command == "exit") {
            cout << endl;
            cout << "Game over!" << endl;
        } else {
            cout << "ERROR: Invalid command input" << endl;
            cout << endl;
        }
    }
}

string GameController::lowerString(string str) {
    for(int i = 0; i < str.size(); ++i) {
        str[i] = tolower(str[i]);
    }
    return str;
}

void GameController::moveCommand(string direction) {
    Room* currentRoom = maze->getRoom(player->currentRoomNum);
    int doorNum = currentRoom->getDoorNum(direction);
    if(doorNum == -2) {
        cout << "ERROR: Invalid direction input" << endl;
        cout << endl;
    } else if(doorNum == -1) {
        cout << "You can't move in that direction!" << endl;
        cout << endl;
    } else {
        player->setCurrentRoomNum(doorNum);
        displayEnterRoomMessage();
    }
    
}

void GameController::takeCommand(string itemName) {
    Room* currentRoom = maze->getRoom(player->currentRoomNum);
    Bag* bag = player->getBag();
    int itemIndex = currentRoom->indexOfItemName(itemName);
    
    if(itemIndex != -1) {
        Item* item = currentRoom->getItem(itemIndex);
        if(item->getType() != "exit") {
            bag->createItem(item->getType(), item->getName());
            currentRoom->removeItem(itemIndex);
            cout << item->getName() << " picked up and added to your bag." << endl;
        } else {
            cout << "An exit item can not be picked up" << endl;
        }
    } else {
        cout << "You don't see a " << itemName << " to take!" << endl;
    }
    cout << endl;
}

void GameController::dropCommand(string itemName) {
    Room* currentRoom = maze->getRoom(player->currentRoomNum);
    Bag* bag = player->getBag();
    
    int itemIndex = bag->indexOfItemName(itemName);
    if(itemIndex != -1) {
        Item* item = bag->getItem(itemIndex);
        currentRoom->createItem(item->getType(), item->getName());
        bag->removeItem(itemIndex);
        cout << item->getName() << " dropped and added to the room." << endl;
    } else {
        cout << "You don't see a " << itemName << " to drop!" << endl;
    }
}

void GameController::teleportCommand(int roomNum) {
    int teleportIndex = player->getBag()->indexOfItemType("teleporter");
    if(roomNum < 0 || roomNum >= maze->getNumRooms()) {
        cout << "You can't teleport to a room that doesn't exist!" << endl;
    } else if(teleportIndex != -1) {
        player->setCurrentRoomNum(roomNum);
        player->getBag()->removeItem(teleportIndex);
        cout << "As if by magic you are transporter to room " << roomNum << "." << endl;
        displayEnterRoomMessage();
    } else {
        cout << "You can't teleport without a teleporter!" << endl;
        cout << endl;
    }
}

void GameController::helpCommand() {
    cout << "move <direction> - move the player in the given direction -- possible directions are north, south, east, west." 
        << "A player can only move in a direction if there is a door out of the room in that direction." << endl;
    cout << "take <item> - move an item (by name) that is in the room to the player's --"
        << "only movable items can be picked up." << endl;
    cout << "drop <item> - move an item (by name) that is in the player's bag into the room" << endl;
    cout << "showbag - print the contents of the player's bag." << endl;
    cout << "teleport <room> - teleport to the given room -- only possible if the player has a teleporter in their bag."
        << "Teleporters are single use items. They are removed from the player's bag when used." << endl;
    cout << "unlock - unlocks the exit to the maze -- only possible if the player is in the room containing"
        << "a maze exit and if the player has a key in their bag." << endl;
    cout << "exit - exits the game" << endl;
    cout << endl;
}

void GameController::showbagCommand() {
    player->getBag()->printItemNamesAndTypes();
    cout << endl;
}

void GameController::unlockCommand() {
    int exitIndex = maze->getRoom(player->currentRoomNum)->indexOfItemType("exit");
    int keyIndex = player->getBag()->indexOfItemType("key");
    if(exitIndex != -1 && keyIndex != -1) {
        string exitName = maze->getRoom(player->currentRoomNum)->getItem(exitIndex)->getName();
        string keyName = player->getBag()->getItem(keyIndex)->getName();
        cout << "Using the " << keyName << ", you unlock " << exitName << " and escape the maze." << endl;
        cout << "Your bag contains the following treasure:" << endl;
        player->getBag()->printItemNames();
    } else {
        cout << "You don't have the key or exit to escape the maze!" << endl;
    }
}

void GameController::displayEnterRoomMessage() {
    Room* newRoom = maze->getRoom(player->currentRoomNum);
    cout << "You are in one of the maze rooms. "
        << "A sign on the wall says, \"Welcome to room " << player->currentRoomNum << "\"" << endl;
    cout << "Looking around you see the following items" << endl;
    newRoom->printItemNames();
    cout << endl;

    cout << "The room has doors in the following directions" << endl;
    newRoom->printDoors();
    cout << endl;
}

void GameController::loadFile(string filename) {
    ifstream fin;
    int numRooms;
    int startingRoom;
    fin.open(filename);
    
    fin >> numRooms;
    maze = new Maze(numRooms);
    fin >> startingRoom;
    player = new Player(startingRoom);
    
    char firstThing;
    int srcRoomNum;
    int dstRoomNum;
    string direction;
    
    fin >> firstThing;
    while(firstThing != '*') {
        srcRoomNum = firstThing - '0';
        fin >> dstRoomNum;
        fin >> direction;
                    
        maze->addDoor(srcRoomNum, dstRoomNum, direction);
        fin >> firstThing;
    }
    
    
    int roomIndex;
    string itemType;
    string itemName;

    fin >> firstThing;
    while(firstThing != '-') {
        roomIndex = firstThing - '0';
        fin >> itemType;
        fin >> itemName;
    
        maze->getRoom(roomIndex)->createItem(itemType, itemName);
        fin >> firstThing;
    }
}