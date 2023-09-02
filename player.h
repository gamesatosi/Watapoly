#ifndef PLAYER_H
#define PLAYER_H

#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;

class Square;
class Ownable_building;

class Player{
    int money;
    int position;
    map<Square*, int> property;
    vector<Square*> mortgages;
    char character;
    string name;
    int timscups;
    int DCturns; // how many turns they have stayed in DC tims line, equals -1 if they are landed on DC tims line (but not sent here) or not in tims line
    int lastRoll;
    int num_academic_building = 0;
    int num_residences = 0;
    int num_gym = 0;
    int num_Art1 = 0;
    int num_Art2 = 0;
    int num_Eng = 0;
    int num_Health = 0;
    int num_Env = 0;
    int num_Sci1 = 0;
    int num_Sci2 = 0;
    int num_Math = 0;
public:
    int getNumProperty() { return num_academic_building + num_gym + num_residences;}
    Player(string n, char c, int timscups, int money, int pos, int DCturns);
    bool monopoly(string block);
    int getnum_academic_building();
    int getnum_residences();
    int getnum_gym();
    int getnum_Art1();
    int getnum_Art2();
    int getnum_Eng();
    int getnum_Health();
    int getnum_Env();
    int getnum_Sci1();
    int getnum_Sci2();
    int getnum_Math();
    int getMoney();
    int getPosition();
    bool bankruptcy();
    void setBankruptcy();
    void setLastRoll(int r);
    int getLastRoll();
    map<Square*, int> getProperty();
    vector<Square*> getMortgage();
    char getCharacter();
    string getName();
    int getTimscups();
    int getDCturns();
    void leaveTimsLine();
    void sentTimsLine();
    void spend(int fee); //you need to check eligbility of bankruptcy first before spend. i.e. money owed is less than the current money it has
    bool smartSpend(int fee, Player* p); // smart spend will automaticlly do bankruptcy stuff if the money owed to p is greater than the current money it has
					// if p is nullptr, give money to bank
    void earn(int fee);
    void stayTimsLine();
    void useTimscups();
    void receiveTimscups();
    int totalMoney(); // returns all assets including savings, printed prices of all buildings owned and costs of improvemnts
    void addProperty(Square* s); // this function adds a building only, does not automatically reduce money
    void deleteProperty(Square* s); // this function deletes a building only, does not automatically increase money
    void setPosition(int pos); // useful for sending player to tims line
    void move(int p); // modify the position by entering an integer e.g. -3, but it doesn't do related square effects
    void display(); // display the assets, used in command "assets" "all"
    void mortgage(Square* s); // this function mortgages a building only, does not automatically increase money or modify the status in academic building class
				// it automatically move building from property to mortgage, you don't need to deleteProperty(Square* s)
    void unmortgage(Square* s);// similar to the above
    void buyImprovement(Square* s); // this function add a improvement to a building only, does not automatically reduce money or modify the academic building status
    void sellImprovement(Square* s);// this function sell a improvement to a building only, does not automatically increase money or modify the academic building status
    bool eligibleBankruptcy(int fee);// checks if player's money owe > money pay
    bool declareBankruptcy(int fee, Player* p); // if p is a nullptr means give all
				// assets to the bank. this function does not modify academic building status
				// if p is a pointer to a Player, move all of the assets of this player to p
				// must check eligbility before you declare bankruptcy
				// this function will handle all bankruptcy related stuff (including asking for willingness to unmortgage right now)
				// after calling this function, the gameboard must delete the pointer to this player
				// returns true if the player bankrupt, returns false if the player mortgages to earn money
    bool bankruptcy(int fee, Player* p);// combination of the two above, if returns false, nothing changes, returns true if the player declares bankruptcy successfully
};
    
#endif
