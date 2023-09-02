#include <iostream>
#include <sstream>
#include <string>
#include <vector>
#include <fstream>
#include <map>
#include "gameboard.h"
#include "player.h"
#include "square.h"
#include "ownable.h"
#include "unownable.h"
#include "textdisplay.h"
#include <cstring>
using namespace std;




int main(int argc, char *argv[]){

// get a new board
GameBoard* b = new GameBoard();



    // load game
    int load = 0;
    int test = 0;
    for (int i = 0; i < argc; ++i) { // seeking for whether there exists load or test
        if (strcmp(argv[i], "-load") == 0) load = i;
        if (strcmp(argv[i], "-testing") == 0) test = i;
    }

    if (strcmp(argv[load], "-load") == 0) { // ensure there exist load 
        if (load + 1 >= argc) { // ensure it follows a file
            cout << "the load command does not follow a file!" << endl;
            return 0;
        }
        ifstream infile{argv[load + 1]}; // load file
        if (infile.fail()) {
            cerr << "Could not find the file!" << endl;
            return 0;
        }
        int num_player;
        infile >> num_player; // read number of players
        // load players
        delete b;
        b = new GameBoard{0, num_player};
        for (int j = 0; j < b->numOfPlayers; ++j) {
            string name;
            char initial;
            int TimsCup;
            int money;
            int position;
            int turn = -1;
            infile >> name >> initial >> TimsCup >> money >> position;
            if (position == 10) { // check whether it is in tims line;
                int a = 0;
                infile >> a;
                if (a == 1) {
                    infile >> turn;
                }
            }
            if (infile.fail()) {
                cout << "incorrect format for players of load file!" << endl;
                break;
            }
            // set players after finishing players file
            b->setPlayer(j, name, initial, TimsCup, money, position, turn);
            if (j == 0) {
                b->currentPlayer = b->getPlayer(0);
            }
        }
        // load ownable building
        while (true) {
            string name;
            string owner;
            int improvement;
            infile >> name >> owner >> improvement;
            if (infile.eof()) {
                break;
            }
            if (infile.fail()) {
                cout << "incorrect format for ownable building of load file!" << endl;
                break;
            }
            Player *p;
            if (owner != "BANK") {
                p = b->getPlayer(owner);
                if (p == nullptr) {cout << "invalid player!" << endl; return 0;}
            }
            Square *s = b->getSquare(name);
            if (s == nullptr || !(b->ownable(name))) {cout << "invalid square!" << endl; return 0;}
            // set owner of the building
            if (owner != "BANK") {
                s->setOwner(p);
                p->addProperty(s);
            }
            // set improvement of the building
            s->setimprovement_level(improvement);
            if (improvement == -1) p->mortgage(s);
            for (int i = 0; i < improvement; ++i){
                p->buyImprovement(s);
            }
        }
    }
    // whether testing_mode
    bool testing_mode = false;
    if (strcmp(argv[test], "-testing") == 0) { 
        testing_mode = true;
    }
    // general playing part
    bool rolled = false;
    string cmd;
    while (cin >> cmd) {
        if (cmd == "roll") { // test mode
        if (testing_mode) { // testing roll
            int die1;
            int die2;
            cin >> die1 >> die2;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "enter the die number again!" << endl;
                continue;
            }
            b->roll(die1,die2);
        } else if (!(rolled)) {
            b->roll();
            rolled = true;
        } else {
            cout << "you have rolled the dice!!!!" << endl;
        }
            // next turn
        } else if (cmd == "next") {
            b->nextTurn();
            rolled = true;
        } else if (cmd == "trade") { // trade money or property ##in addition, all trade are based on improvement can be left
            string name;
            string give;
            string receive;
            cin >> name >> give >> receive;
            if (cin.fail()) {
                cout << "incorrect input!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            Player *p = b->getPlayer(name);  // get the pointer of player
            if (p == nullptr) {
                cout << "the name is invalid, please enter it again!" << endl;
                continue;
            }
            // conditional arguments
            int give_int;
            int receive_int;
            Square* give_building;
            Square* receive_building;
            // check whether own it or afford the money
            if (b->ownable(give)) {
                if (b->getSquare(give)->getOwner() == b->currentPlayer) {
                    give_building = b->getSquare(give);
                } else {
                    cout << "You does not own this building!" << endl;
                    continue;
                }
            } else {
                stringstream ss(give);
                ss >> give_int;
                if (ss.fail()) {
                    cout << "invalid give!" << endl;
                    ss.clear();
                    ss.ignore();
                    continue;
                }
                if (give_int > b->currentPlayer->getMoney()) {
                    cout << "you have no enough money to exchange!" << endl;
                    continue;
                }
            }

            // check whether own it or afford the money
            if (b->ownable(receive) && b->getSquare(receive)->getOwner() == p) {
                if (b->getSquare(receive)->getOwner() == p) {
                    receive_building = b->getSquare(receive);
                } else {
                    cout << "Another trader does not own this building!" << endl;
                    continue;
                }
            } else {
                stringstream ss(receive);
                ss >> receive_int;
                if (ss.fail()) {
                    cout << "invalid receive!" << endl;
                    ss.clear();
                    ss.ignore();
                    continue;
                }
                if (receive_int > p->getMoney()) {
                    cout << "Another trader does not have enough money!" << endl;
                    continue;
                }
            }

            // ask whether to exchange
            cout << b->currentPlayer->getName() << " wanna to use " << give << " to trade " << receive << " from " << name << endl;
            cout << "do you wanna to exchange? [accept/reject]" << endl;
            string response;
            cin >> response;
            if (response == "accept") { // accept to trade
                if (give[0] >= '0' && give[0] <= '9') {
                    b->currentPlayer->spend(give_int);
                    p->earn(give_int);
                } else {
                    b->currentPlayer->deleteProperty(give_building); // construct getownable!!!!!!!!!!!!!!!!!
                    p->addProperty(give_building);
                    give_building->setOwner(p);
                }

                if (receive[0] >= '0' && receive[0] <= '9') {
                    p->spend(receive_int);
                    b->currentPlayer->earn(receive_int);
                } else {
                    p->deleteProperty(receive_building); // construct getownable!!!!!!!!!!!!!!!!!
                    b->currentPlayer->addProperty(receive_building);
                    receive_building->setOwner(b->currentPlayer);
                }



            } else if (response == "reject") { // reject to trade
                cout << "trade is rejected" << endl;
            } else {
                cout << "invalid input!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
        } else if (cmd == "improve") { // improve the property
            string buildingname;
            cin >> buildingname;
            if (cin.fail()) {
                cout << "invalid input!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            Square * o = b->getSquare(buildingname);
            if (b->ownable(buildingname)) {
                string bs;
                cin >> bs;
                if (cin.fail()) {
                    cout << "invalid input!" << endl;
                    cin.clear();
                    cin.ignore();
                    continue;
                }
                if (bs == "buy") {
                    if (o->getOwner()->getName() == b->currentPlayer->getName()) {
                            if (o->improve()) {
                                b->currentPlayer->spend(o->getimprovement_cost());
				                b->currentPlayer->buyImprovement(o); //4.10
                            }
                    } else {
                        cout << "you do not own it, so you cannot improve it!" << endl;
                    }
                }
                if (bs == "sell") {
                    if (o->getOwner()->getName() == b->currentPlayer->getName()) {
                        cout << "you get " << o->getValue() << " now!" << endl; 
                        b->currentPlayer->earn(o->getValue()); 
			            b->currentPlayer->sellImprovement(o); //4.10
                    } else {
                        cout << "you do not own this property!" << endl;
                    }
                }
            } else {
                cout << "it is unownable!" << endl;
                continue;
            }
        } else if (cmd == "mortgage") {
            string buildingname;
            cin >> buildingname;
            if (cin.fail()) {
                cout << "invalid input!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            if (b->ownable(buildingname) && b->getSquare(buildingname)->getOwner()->getName() == b->currentPlayer->getName() 
            && b->getSquare(buildingname)->getimprovement_level() != -1) {
                b->mortgage(b->getSquare(buildingname)); 
                // mortgage in gameboard, then it earns the money (auto to sell both improvement and property)
            } else {
                cout << "you do not own this building or your input is invalid!" << endl;
                continue;
            }
        } else if (cmd == "unmortgage") {
            string buildingname;
            cin >> buildingname;
            if (cin.fail()) {
                cout << "invalid input!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            if (b->ownable(buildingname) && b->getSquare(buildingname)->getOwner()->getName() == b->currentPlayer->getName()
            && b->getSquare(buildingname)->getimprovement_level() == -1) {
                b->unmortgage(b->getSquare(buildingname)); // unmortgage in gameboard, then it spends the money 
            } else {
                cout << "you do not own this building or your input is invalid!" << endl;
                continue;
            }
        } else if (cmd == "bankrupt") {
            if (b->currentPlayer->getMoney() == -1) {
                cout << "Congratulation, you are out!" << endl;
            }
            if (b->currentPlayer->getMoney() == -2) {
                if (b->currentPlayer->getNumProperty() == 0) {
                    cout << "you have no property to bid! LOL!" << endl;
                    continue;
                }
                cout << "Congratulation, your property start to be bidden now!!!" << endl;
                cout << "All property will be bidden together!" << endl;
                cout << "The following are properties!" << endl;
                b->currentPlayer->display();
                while (true) { // auction for bankruptcy!!!!!!
                    int bid = 0;
                    string s = b->auction(b->getPlayer(), bid, b->numOfPlayers, nullptr);
                    Player* player = b->getPlayer(s);
                    if (player->getMoney() >= bid) {
                        cout << "you win these building!" << endl;
                        player->spend(bid);
                        map <Square*, int> m = b->currentPlayer->getProperty();
                        for (auto a : m) {
                            player->addProperty(a.first);
                            a.first->setOwner(player);
                            
                        }
                        break;
                    } else {
                        cout << "you have no enough money! the auction will start again!" << endl;
                        continue;
                    }
                }


            }
        } else if (cmd == "assets") {
            b->currentPlayer->display();
            
        } else if (cmd == "all") {
            for (int i = 0; i < b->numOfPlayers; ++i) {
                if (b->getPlayer(i)->bankruptcy()) {
                    continue;
                }
                cout << b->getPlayer(i)->getName() << ":" << endl;
                b->getPlayer(i)->display();
            }

        } else if (cmd == "save") {
            ofstream save_file;
            string file_name;
            cin >> file_name;
            if (cin.fail()) {
                cout << "incorrect format of file name!" << endl;
                cin.clear();
                cin.ignore();
                continue;
            }
            save_file.open (file_name);
            // save the number of players
            save_file << b->numOfPlayers << endl;
            // save player information
            for (int i = 0; i < b->numOfPlayers; ++i) {
                save_file << b->currentPlayer->getName() << " " << b->currentPlayer->getCharacter() << " " 
                << b->currentPlayer->getTimscups() << " " << b->currentPlayer->getMoney() << " ";

                if (b->currentPlayer->getPosition() == 10 && b->currentPlayer->getDCturns() == -1) {
                    save_file << 10 << " " << 0;
                } else if (b->currentPlayer->getPosition() == 30) {
                    save_file << 10 << " " << 1 << " " << 0;
                } else if (b->currentPlayer->getPosition() == 10) {
                    save_file << 10 << " " << 1 << " " << b->currentPlayer->getDCturns();
                }else {
                    save_file << b->currentPlayer->getPosition();
                }
                save_file << endl;
                b->nextTurn(); // move to next player
            } // player will be the same as before since it is a whole turn

            for (int i = 0; i < 28 ; ++i) { 
                save_file << b->ownable(i)->getName() << " ";
                if ( b->ownable(i)->getOwner() == nullptr) {
                    save_file << "BANK";
                } else {
                    save_file << b->ownable(i)->getOwner()->getName();
                }
                save_file << " " << b->ownable(i)->getimprovement_level() << endl;
            }
            // close file
            save_file.close();
        } else if (cmd == "newgame") {
            cout << "please enter the number of cup and the number of players:" << endl;
            int num;
            int cup;
            cin >> cup >> num;
            if (cin.fail()) {
                cin.clear();
                cin.ignore();
                cout << "please try again!" << endl;
                continue;
            }
            delete b;
            b = new GameBoard(cup, num, true);
        } else {
            cout << "invalid input!" << endl;
        }
        if (b->isOver()) {
            cout << b->winner() << " win the game!!!!" << endl;
        }

        // print the board for each operation
        printBoard(b);


    }
    delete b;
}


