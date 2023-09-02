#ifndef UNOWNABLEBUILDING_H
#define UNOWNABLEBUILDING_H
#include <vector>
#include <string>
#include "square.h"
#include "player.h"
#include "gameboard.h"
#include "random.h"
using namespace std;

class Unownable : public Square{
public:
    Unownable(string name): Square{name} {}
    //~Unownable();
    virtual void notify(GameBoard& g, Player& p) = 0;
    string getType() override;
    Player* getOwner() override;
    void setOwner(Player *p) override;
    void setimprovement_level(int improvement) override;
    int getimprovement_cost() override;
    int getpurchase_cost() override;
    string getmonopoly_block() override;
    bool improve() override;
    int getValue() override;
    int getimprovement_level() override;
    ~Unownable() override {};
};

class CoopFee : public Unownable{
public:
    CoopFee(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class GooseNesting : public Unownable{
public:
    GooseNesting(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class OSAP : public Unownable{
public:
    OSAP(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class Tuition : public Unownable{
public:
    Tuition(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class Slc : public Unownable{
public:
    Slc(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class NeedlesHall : public Unownable{
public:
    NeedlesHall(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class GoToTims : public Unownable{
public:
    GoToTims(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class LandDCTimsLine : public Unownable{
public:
    LandDCTimsLine(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

class SentToDCTimsLine : public Unownable{
public:
    SentToDCTimsLine(string name): Unownable{name} {}
    void notify(GameBoard& g, Player& p) override;
};

#endif

    