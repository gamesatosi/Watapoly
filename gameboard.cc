#include "gameboard.h"
#include "random.h"
#include "square.h"
#include "player.h"
#include "unownable.h"
#include "ownable.h"
#include <iostream>
#include <string>
using namespace std;

GameBoard::GameBoard(int cups, int numOfPlayers, bool whether_new): cups{cups}, rolled{false}, numOfPlayers{numOfPlayers} {
    // initialize player character icons
    playerIcons[0] = 'G';
    playerIcons[1] = 'B';
    playerIcons[2] = 'D';
    playerIcons[3] = 'P';
    playerIcons[4] = 'S';
    playerIcons[5] = '$';
    playerIcons[6] = 'L';
    playerIcons[7] = 'T';
    
    // initialize dice
    dice = new Random(6);
    
    // initialize player array to nullptr and current player
    if (whether_new) {
        for(int i = 0; i < numOfPlayers; i++) {
            cout << "enter the name, icon of player" << i << ":" << endl;
            string name; 
            char icon;
            cin >> name >> icon;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                --i;
                cout << "please enter name and icon again" << endl;
                continue;
            }
            players[i] = new Player(name, icon, 0, 1500, 0, -1);
        }
    } else {
        for (int i = 0; i < numOfPlayers; ++i) {
            players[i] = nullptr;
        }
    }
    currentPlayer = players[0];
    current = 0;

    //initialize board (need constructors)
    theBoard[0] = new OSAP{"OSAP"};
    theBoard[1] = new Academic_building{"AL", "academic", nullptr, 40, "Arts1", 50, 0, 2, 10, 30, 90, 160, 250};
    theBoard[2] = new Slc("Slc");
    theBoard[3] = new Academic_building{"ML", "academic", nullptr, 60, "Arts1", 50, 0, 4, 20, 60, 180, 320, 450};
    theBoard[4] = new Tuition("Tuition");
    theBoard[5] = new Residence{"MKV", "residence", nullptr, 200, 0};
    theBoard[6] = new Academic_building{"ECH", "academic", nullptr, 100, "Arts2", 50, 0, 6, 30, 90, 270, 400, 550};
    theBoard[7] = new NeedlesHall("NeedlesHall");
    theBoard[8] = new Academic_building{"PAS", "academic", nullptr, 100, "Arts2", 50, 0, 6, 30, 90, 270, 400, 550};
    theBoard[9] = new Academic_building{"HH", "academic", nullptr, 120, "Arts2", 50, 0, 8, 40, 100, 300, 450, 600};

    theBoard[10] = new LandDCTimsLine("LandDCTimsLine");
    theBoard[11] = new Academic_building{"RCH", "academic", nullptr, 140, "Eng", 100, 0, 10, 50, 150, 450, 625, 750};
    theBoard[12] = new Gym{"PAC", "gym", nullptr, 150, 0};
    theBoard[13] = new Academic_building{"DWE", "academic", nullptr, 140, "Eng", 100, 0, 10, 50, 150, 450, 625, 750};
    theBoard[14] = new Academic_building{"CPH", "academic", nullptr, 160, "Eng", 100, 0, 12, 60, 180, 500, 700, 900};
    theBoard[15] = new Residence{"UWP", "residence", nullptr, 200, 0};
    theBoard[16] = new Academic_building{"LHI", "academic", nullptr, 180, "Health", 100, 0, 14, 70, 200, 550, 750, 950};
    theBoard[17] = new Slc("Slc");
    theBoard[18] = new Academic_building{"BMH", "academic", nullptr, 180, "Health", 100, 0, 14, 70, 200, 550, 750, 950};
    theBoard[19] = new Academic_building{"OPT", "academic", nullptr, 200, "Health", 100, 0, 16, 80, 220, 600, 800, 1000};

    theBoard[20] = new GooseNesting("GooseNesting");
    theBoard[21] = new Academic_building{"EV1", "academic", nullptr, 220, "Env", 150, 0, 18, 90, 250, 700, 875, 1050};
    theBoard[22] = new NeedlesHall("NeedlesHall");
    theBoard[23] = new Academic_building{"EV2", "academic", nullptr, 220, "Env", 150, 0, 18, 90, 250, 700, 875, 1050};
    theBoard[24] = new Academic_building{"EV3", "academic", nullptr, 240, "Env", 150, 0, 20, 100, 300, 750, 925, 1100};
    theBoard[25] = new Residence{"V1", "residence", nullptr, 200, 0};
    theBoard[26] = new Academic_building{"PHYS", "academic", nullptr, 260, "Sci1", 150, 0, 22, 110, 330, 800, 975, 1150};
    theBoard[27] = new Academic_building{"B1", "academic", nullptr, 260, "Sci1", 150, 0, 22, 110, 330, 800, 975, 1150};
    theBoard[28] = new Gym {"CIF", "gym", nullptr, 150, 0};
    theBoard[29] = new Academic_building{"B2", "academic", nullptr, 280, "Sci1", 150, 0, 24, 120, 360, 850, 1025, 1200};

    theBoard[30] = new GoToTims("GoToTims");
    theBoard[31] = new Academic_building{"EIT", "academic", nullptr, 300, "Sci2", 200, 0, 26, 130, 390, 900, 1100, 1275};
    theBoard[32] = new Academic_building{"ESC", "academic", nullptr, 300, "Sci2", 200, 0, 26, 130, 390, 900, 1100, 1275};
    theBoard[33] = new Slc("Slc");
    theBoard[34] = new Academic_building{"C2", "academic", nullptr, 320, "Sci2", 200, 0, 28, 150, 450, 1000, 1200, 1400};
    theBoard[35] = new Residence{"REV", "residence", nullptr, 200, 0};
    theBoard[36] = new NeedlesHall("NeedlesHall");
    theBoard[37] = new Academic_building{"MC", "academic", nullptr, 350, "Math", 200, 0, 35, 175, 500, 1100, 1300, 1500};
    theBoard[38] = new CoopFee("CoopFee");
    theBoard[39] = new Academic_building{"DC", "academic", nullptr, 400, "Math", 200, 0, 50, 200, 600, 1400, 1700, 2000};

    theBoard[40] = new SentToDCTimsLine("SentToDCTimsLine");
}

void GameBoard::setPlayer(int i, string n, char c, int timscups, int money, int pos, int DCturns){
    if (players[i] != nullptr) delete players[i];
    players[i] = new Player(n, c, timscups, money, pos, DCturns);
}

GameBoard::~GameBoard() {
    for(int i = 0; i < numOfPlayers; i++) {
        delete players[i];
    }

    for(int j = 0; j < 41; j++) {
        delete theBoard[j];
    }
    delete dice;
}

int GameBoard::numCups() {
    return cups;
}

bool GameBoard::isOver() {
    int count = 0;
    for(int i = 0; i < numOfPlayers; i++) {
        if (players[i]->getMoney() >= 0) {
            count++;
        }
    }
    if (count == 1) return true;
    return false;
}

std::string GameBoard::winner() {
    string s;
    for (int i = 0; i < numOfPlayers; i++) {
        if (players[i]->getMoney() != 0) {
            s = players[i]->getName();
        }
    }
    return s;
}

// needs abstract notify in square class
void GameBoard::roll() {
    int r1 = dice->generate();
    int r2 = dice->generate();
    cout << "you roll a " << r1 << " and a " << r2 << endl;
    currentPlayer->move(r1 + r2);
    theBoard[currentPlayer->getPosition()]->notify(*this, *currentPlayer);
}

void GameBoard::roll(int die1, int die2) {
    cout << "you roll a " << die1 << " and a " << die2 << endl;
    currentPlayer->move(die1 + die2);
    theBoard[currentPlayer->getPosition()]->notify(*this, *currentPlayer);
}

void GameBoard::nextTurn() {
    while (true) {
        current++;
        current = current % numOfPlayers;
        if (players[current]->bankruptcy()) {
            continue;
        } else {
            currentPlayer = players[current];
            if (currentPlayer->getPosition() == 10 && currentPlayer->getDCturns() != -1) {
                theBoard[40]->notify(*this, *currentPlayer);
            }
            break;
        }
    }
}

void GameBoard::playersOnTile(int i) {
    for(int j = 0; j < numOfPlayers; j++) {
        if (players[j]->getPosition() == i) {
            cout << players[j]->getCharacter();
        }
    }
}

int GameBoard::numPlayersOnTile(int i) {
    int count = 0;
    for(int j = 0; j < numOfPlayers; j++) {
        if (players[j]->getPosition() == i) {
            count++;
        }
    }
    return count;
}

Square* GameBoard::getSquare(int i) {
    return theBoard[i];
}

Player* GameBoard::getPlayer(int i) {
    return players[i];
}

Player* GameBoard::getPlayer(string name) {
    for (int i = 0; i < numOfPlayers; i++) {
        if(players[i]->getName() == name) {
            return players[i];
        }
    }
    return nullptr;
}

Player** GameBoard::getPlayer(){
    return players;
}

Square** GameBoard::getSquare(){
    return theBoard;
}

Square *GameBoard::getSquare(string s){
    for (int i = 0; i < 41; ++i){
	if (theBoard[i]->getName() == s) return theBoard[i];
    }
    return nullptr;
}

void GameBoard::mortgage(Square* s){ // mortgage all
    currentPlayer->mortgage(s);
    int l = (s->getimprovement_level() * s->getimprovement_cost() + s->getpurchase_cost()) * 0.5;
    s->setimprovement_level(-1);
    currentPlayer->earn(l);
}

void GameBoard::unmortgage(Square* s){
    int c = s->getpurchase_cost() * 0.6;
    if (currentPlayer->eligibleBankruptcy(c)) {
	cout<<"no enough money"<<endl;
	return;
    }
    currentPlayer->spend(c);
    currentPlayer->unmortgage(s);
    s->setimprovement_level(0);
}


Square* GameBoard::academic(int i) {
    Square* lol[22] = {theBoard[1], theBoard[3], theBoard[6], theBoard[8], theBoard[9], theBoard[11], 
                            theBoard[13], theBoard[14], theBoard[16], theBoard[18], theBoard[19], theBoard[21], 
                            theBoard[23], theBoard[24], theBoard[26], theBoard[27], theBoard[29], theBoard[31], 
                            theBoard[32], theBoard[34], theBoard[37], theBoard[39]}; //  academic buildings
    return lol[i];
}

bool GameBoard::ownable(string s) {
    Square* lol[28] = {theBoard[1], theBoard[3], theBoard[5], theBoard[6], theBoard[8], theBoard[9], theBoard[11], 
                        theBoard[12], theBoard[13], theBoard[14], theBoard[15], theBoard[16], theBoard[18], theBoard[19], theBoard[21], 
                        theBoard[23], theBoard[24], theBoard[25], theBoard[26], theBoard[27], theBoard[28], theBoard[29], theBoard[31], 
                        theBoard[32], theBoard[34], theBoard[35], theBoard[37], theBoard[39]};
    for (int i = 0; i < 28; ++i) {
        if (lol[i]->getName() == s) return true;
    }
    return false;
}

Square* GameBoard::ownable(int i) {
    Square* lol[28] = {theBoard[1], theBoard[3], theBoard[5], theBoard[6], theBoard[8], theBoard[9], theBoard[11], 
                        theBoard[12], theBoard[13], theBoard[14], theBoard[15], theBoard[16], theBoard[18], theBoard[19], theBoard[21], 
                        theBoard[23], theBoard[24], theBoard[25], theBoard[26], theBoard[27], theBoard[28], theBoard[29], theBoard[31], 
                        theBoard[32], theBoard[34], theBoard[35], theBoard[37], theBoard[39]};
    return lol[i];
}



// returns true if zero or one elements in withdrawn are false, returns false otherwise
bool GameBoard::onlyOne(bool withdrawn[8], int max) {
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
string GameBoard::auction(Player *players[8], int &current_bid, int maxPlayers, Player *p) {
    bool withdrawn[8];
    for (int i = 0; i < 8; i++) {
        withdrawn[i] = false;
    }
    string cmd;
    int increment = 0;

    while(true) {
        // check if only one player hasn't withdrawn
        if (this->onlyOne(withdrawn, maxPlayers)) {
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

