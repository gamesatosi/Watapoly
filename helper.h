#ifndef HELPER
#define HELPER

#include "gameboard.h"
#include "random.h"
#include "square.h"
#include "player.h"
#include "unownable.h"
#include "ownable.h"
#include <iostream>
#include <string>
using namespace std;



// returns true if zero or one elements in withdrawn are false, returns false otherwise
bool onlyOne(bool withdrawn[8], int max) {
    bool hasntWithdrawn = false;
    for(int i = 0; i < max; ++i) {
        if(!withdrawn[i]) {
            if (hasntWithdrawn) {
                return false;
            }
            hasntWithdrawn = true;
        }
    }
    return true;
}

// assumes players[0] is not participating in auction
// doesn't change ownership of building, 
string auction(Player *players[8], int &current_bid, int maxPlayers, Player *p) {
    bool withdrawn[8];
    for (int i = 0; i < 8; i++) {
        withdrawn[i] = false;
    }
    string cmd;
    int increment = 0;

    while(true) {
        // check if only one player hasn't withdrawn
        if (onlyOne(withdrawn, maxPlayers)) {
            break;
        }

        // skip over withdrawn players
        if (withdrawn[increment]) {
            if (increment == maxPlayers - 1) {
                increment = 0;
            } else {
                increment++;
            }
            continue;
        }
        if (p != nullptr) {
            if (players[increment]->getName() == p->getName()) {
                withdrawn[increment] = true;
                ++increment; 
                continue;
            }
        }
        if (players[increment]->bankruptcy()) {
            withdrawn[increment] = true;
            ++increment; 
            continue;
        }
        cout << players[increment]->getName() << ": " << "Would you like to bid or withdraw?" << endl;
        cin >> cmd;
        if (cmd == "bid") {
            int bid;
            cout << "Enter your bid:" << endl;
            cin >> bid;
            if (bid <= current_bid) {
                cout << "Your bid needs to be higher than the current bid of $" << current_bid << endl;
            } else {
                current_bid = bid;
                cout << "The current bid is now $" << current_bid << endl;
                if (increment == maxPlayers - 1) {
                    increment = 0;
                } else {
                    increment++;
                }
            }
        } else if (cmd == "withdraw") {
            withdrawn[increment] = true;
            if (increment == maxPlayers - 1) {
                increment = 0;
            } else {
                increment++;
            }
        } else if (cin.eof()) {
            break;
        } else {
            cout << "Invalid command, try again" << endl;
        }
    }
    for(int i = 0; i < maxPlayers; i++) {
        if(withdrawn[i] == false) {
            return players[i + 1]->getName();
        }
    }
    return nullptr;
}


#endif

