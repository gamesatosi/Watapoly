#ifndef OWNABLEBUILDING_H
#define OWNABLEBUILDING_H
#include <vector>
#include <string>
#include "square.h"
#include "player.h"

class OwnableBuilding : public Square {
    string type;
    Player* owner = nullptr;
    const int purchase_cost;
public:
    OwnableBuilding(string name, string type, Player* owner, int purchase_cost) : Square{name}, type{type}, owner{owner}, purchase_cost{purchase_cost} {}
    void setOwner(Player *p); // setowner
    Player* getOwner(); // getowner
    string getType() override; // get the type of ownable (academic/residence/gym)
    virtual void notify(GameBoard& g, Player& p) = 0; // communicate between square and player
    int getpurchase_cost(); // get the purchase_cost
    virtual int getFee() = 0;    // get the fee
    virtual int getValue() = 0; // get the value

    virtual void setimprovement_level(int improvement) = 0;
    virtual int getimprovement_cost() = 0;
    virtual string getmonopoly_block() = 0;
    virtual bool improve() = 0;
    virtual int getimprovement_level() = 0;
    ~OwnableBuilding() override {} // the same as board player, so do not delete
};


class Academic_building : public OwnableBuilding {
    const string monopoly_block;
    const int improvement_cost;
    int improvement_level;
    const int level0; // fee for each level
    const int level1;
    const int level2;
    const int level3;
    const int level4;
    const int level5;
    const int level_fee[6] = {level0, level1, level2, level3, level4, level5};
public:
    Academic_building(string name, string type, Player* owner, int purchase_cost, string monopoly_block, 
                        int improvement_cost,int improvement_level, int level0, int level1, int level2, int level3, int level4, int level5) : 
                        OwnableBuilding{name, type, owner, purchase_cost}, monopoly_block{monopoly_block}, 
                        improvement_cost{improvement_cost}, improvement_level{improvement_level},
                        level0{level0}, level1{level1}, level2{level2}, level3{level3}, level4{level4}, level5{level5} {}
    int getimprovement_cost() override; // get the improvement cost
    void notify(GameBoard& g, Player& p) override; // communicate between player and square
    int getimprovement_level() override; // return the improvement level
    bool improve() override; //return true if it can be improved
    int getFee() override; // get the fee
    string getmonopoly_block() override; // get the monopoly_block
    int getValue() override; // get the value for mortgage the improvement 
    void setimprovement_level(int improvement) override; // set the improvement level
};

class Residence : public OwnableBuilding {
    int improvement_level;
public:
    Residence(string name, string type, Player* owner, int purchase_cost, int improvement_level) : 
    OwnableBuilding{name, type, owner, purchase_cost}, improvement_level{improvement_level} {}
    int getFee() override; // get the fee
    int getValue() override; // get the value for selling the improvement
    void notify(GameBoard& g, Player& p) override; // communicate between player and square 

    int getimprovement_cost() override { return 0; } // just for override
    string getmonopoly_block() override { return ""; } // just for override
    bool improve() override { return false; } // just for override
    int getimprovement_level() override { return improvement_level; } // get the improvement level
    void setimprovement_level(int improvement) override; // set the improvement level
};

class Gym : public OwnableBuilding {
    int improvement_level;
public:
    Gym(string name, string type, Player* owner, int purchase_cost, int improvement_level): 
    OwnableBuilding{name, type, owner, purchase_cost}, improvement_level{improvement_level} {}
    int getFee() override;
    int getValue() override;
    void notify(GameBoard& g, Player& p) override;

    int getimprovement_cost() override { return 0; }
    string getmonopoly_block() override { return ""; }
    bool improve() override { return false; }
    int getimprovement_level() override { return improvement_level; }
    void setimprovement_level(int improvement) override;
};

#endif
