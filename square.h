#ifndef SQUARE_H
#define SQUARE_H
#include <vector>
#include <string>
#include <iostream>
#include "gameboard.h"
using namespace std;

class Square {
    const string name;

 public:
    Square(string name) : name{name} {}
    string getName();
    virtual string getType() = 0;
    virtual Player* getOwner() = 0;
    virtual void setOwner(Player *p) = 0;
    virtual void setimprovement_level(int improvement) = 0;
    virtual int getimprovement_cost() = 0;
    virtual int getpurchase_cost() = 0;
    virtual string getmonopoly_block() = 0;
    virtual void notify(GameBoard& g, Player& p) = 0;
    virtual bool improve() {cout << "you cannot improve it, because it is not academic building!" << endl; return false;}
    virtual int getValue() = 0;
    virtual int getimprovement_level() = 0;
    virtual ~Square() {}
};




#endif
