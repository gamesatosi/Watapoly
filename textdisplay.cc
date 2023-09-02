#include "gameboard.h"
#include "ownable.h"
#include <iostream>
using namespace std;

int max (int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

void printBoard (GameBoard *g) {
    cout << "____________________________________________________________________________________________________" << endl;
    //print upgrades
    cout << "|Goose   |";
    for (int i = 0; i < g->getSquare(21)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(21)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|NEEDLES |";
    for (int i = 0; i < g->getSquare(23)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(23)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i < g->getSquare(24)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(24)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|V1      |";
    for (int i = 0; i < g->getSquare(26)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(26)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i < g->getSquare(27)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(27)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|CIF     |";
    for (int i = 0; i < g->getSquare(29)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(29)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|GO TO   |" << endl;
    cout << "|Nesting |--------|HALL    |--------|--------|        |--------|--------|        |--------|TIMS    |" << endl;
    cout << "|        |EV1     |        |EV2     |EV3     |        |PHYS    |B1      |        |B2      |        |" << endl;
    // print player characters (line 5)
    cout << "|";
    g->playersOnTile(20);
    for (int i = 0; i < (8 - g->numPlayersOnTile(20)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(21);
    for (int i = 0; i < (8 - g->numPlayersOnTile(21)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(22);
    for (int i = 0; i < (8 - g->numPlayersOnTile(22)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(23);
    for (int i = 0; i < (8 - g->numPlayersOnTile(23)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(24);
    for (int i = 0; i < (8 - g->numPlayersOnTile(24)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(25);
    for (int i = 0; i < (8 - g->numPlayersOnTile(25)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(26);
    for (int i = 0; i < (8 - g->numPlayersOnTile(26)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(27);
    for (int i = 0; i < (8 - g->numPlayersOnTile(27)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(28);
    for (int i = 0; i < (8 - g->numPlayersOnTile(28)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(29);
    for (int i = 0; i < (8 - g->numPlayersOnTile(29)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(30);
    for (int i = 0; i < (8 - g->numPlayersOnTile(30)); i++) {
        cout << " ";
    }
    cout << "|" << endl;

    for(int i = 0; i < 11; i++) {
        cout << "|________";
    }
    cout << "|" << endl;
    // end of top row of board

    // print upgrades
    cout << "|";
    for (int i = 0; i < g->getSquare(19)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(19)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    for (int i = 0; i < g->getSquare(31)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(31)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|--------|                                                                                |--------|" << endl;
    cout << "|OPT     |                                                                                |EIT     |" << endl;
    cout << "|";
    g->playersOnTile(19);
    for (int i = 0; i < (8 - g->numPlayersOnTile(19)); i++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    g->playersOnTile(31);
    for (int i = 0; i < (8 - g->numPlayersOnTile(31)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                                                                                |________|" << endl;
    //print upgrades
    cout << "|";
    for (int i = 0; i < g->getSquare(18)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(18)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    for (int i = 0; i < g->getSquare(32)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(32)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|--------|                                                                                |--------|" << endl;
    cout << "|BMH     |                                                                                |ESC     |" << endl;
    cout << "|";
    g->playersOnTile(18);
    for (int i = 0; i < (8 - g->numPlayersOnTile(18)); i++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    g->playersOnTile(32);
    for (int i = 0; i < (8 - g->numPlayersOnTile(32)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                                                                                |________|" << endl;
    cout << "|SLC     |                                                                                |SLC     |" << endl;
    cout << "|        |                                                                                |        |" << endl;
    cout << "|        |                                                                                |        |" << endl;
    cout << "|";
    g->playersOnTile(17);
    for (int i = 0; i < (8 - g->numPlayersOnTile(17)); i++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    g->playersOnTile(33);
    for (int i = 0; i < (8 - g->numPlayersOnTile(33)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                                                                                |________|" << endl;
    //print upgrades
    cout << "|";
    for (int i = 0; i < g->getSquare(16)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(16)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    for (int i = 0; i < g->getSquare(34)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(34)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|--------|                                                                                |--------|" << endl;
    cout << "|LHI     |                                                                                |C2      |" << endl;
    cout << "|";
    g->playersOnTile(16);
    for (int i = 0; i < (8 - g->numPlayersOnTile(16)); i++) {
        cout << " ";
    }
    cout << "|                  ____________________________________________                  |";
    g->playersOnTile(34);
    for (int i = 0; i < (8 - g->numPlayersOnTile(34)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                 |                                            |                 |________|" << endl;
    cout << "|UWP     |                 | #   #  ##  #####  ###  ###   ###  #  #   # |                 |REV     |" << endl;
    cout << "|        |                 | #   # #  #   #   #   # #  # #   # #  #   # |                 |        |" << endl;
    cout << "|        |                 | # # # ####   #   #   # ###  #   # #   # #  |                 |        |" << endl;
    cout << "|";
    g->playersOnTile(15);
    for (int i = 0; i < (8 - g->numPlayersOnTile(15)); i++) {
        cout << " ";
    }
    cout << "|                 | # # # #  #   #   #   # #    #   # #    #   |                 |";
    g->playersOnTile(35);
    for (int i = 0; i < (8 - g->numPlayersOnTile(35)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                 | ##### #  #   #    ###  #     ###  ###  #   |                 |________|" << endl;
    // print upgrades
    cout << "|";
    for (int i = 0; i < g->getSquare(14)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(14)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|                 |____________________________________________|                 |NEEDLES |" << endl;
    cout << "|--------|                                                                                |HALL    |" << endl;
    cout << "|CPH     |                                                                                |        |" << endl;
    cout << "|";
    g->playersOnTile(14);
    for (int i = 0; i < (8 - g->numPlayersOnTile(14)); i++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    g->playersOnTile(36);
    for (int i = 0; i < (8 - g->numPlayersOnTile(36)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                                                                                |________|" << endl;
    //print upgrades
    cout << "|";
    for (int i = 0; i < g->getSquare(13)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(13)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    for (int i = 0; i < g->getSquare(37)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(37)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|--------|                                                                                |--------|" << endl;
    cout << "|DWE     |                                                                                |MC      |" << endl;
    cout << "|";
    g->playersOnTile(13);
    for (int i = 0; i < (8 - g->numPlayersOnTile(13)); i++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    g->playersOnTile(37);
    for (int i = 0; i < (8 - g->numPlayersOnTile(37)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                                                                                |________|" << endl;
    cout << "|PAC     |                                                                                |COOP    |" << endl;
    cout << "|        |                                                                                |FEE     |" << endl;
    cout << "|        |                                                                                |        |" << endl;
    cout << "|";
    g->playersOnTile(12);
    for (int i = 0; i < (8 - g->numPlayersOnTile(12)); i++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    g->playersOnTile(38);
    for (int i = 0; i < (8 - g->numPlayersOnTile(38)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|                                                                                |________|" << endl;
    //print upgrades
    cout << "|";
    for (int i = 0; i < g->getSquare(11)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(11)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    for (int i = 0; i < g->getSquare(39)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(39)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|--------|                                                                                |--------|" << endl;
    cout << "|RCH     |                                                                                |DC      |" << endl;
    cout << "|";
    g->playersOnTile(11);
    for (int i = 0; i < (8 - g->numPlayersOnTile(11)); i++) {
        cout << " ";
    }
    cout << "|                                                                                |";
    g->playersOnTile(39);
    for (int i = 0; i < (8 - g->numPlayersOnTile(39)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    cout << "|________|________________________________________________________________________________|________|" << endl;
    cout << "|DC Tims |";
    for (int i = 0; i < g->getSquare(9)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(9)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|";
    for (int i = 0; i < g->getSquare(8)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(8)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|NEEDLES |";
    for (int i = 0; i < g->getSquare(6)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(6)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|MKV     |TUITION |";
    for (int i = 0; i < g->getSquare(3)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(3)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|SLC     |";
    for (int i = 0; i < g->getSquare(1)->getimprovement_level(); i++) {
        cout << "I";
    }
    for (int j = 0; j < 8 - max(0, g->getSquare(1)->getimprovement_level()); j++) {
        cout << " ";
    }
    cout << "|COLLECT |" << endl;
    cout << "|Line    |--------|--------|HALL    |--------|        |        |--------|        |--------|OSAP    |" << endl;
    cout << "|        |HH      |PAS     |        |ECH     |        |        |ML      |        |AL      |        |" << endl;
    cout << "|";
    g->playersOnTile(10);
    for (int i = 0; i < (8 - g->numPlayersOnTile(10)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(9);
    for (int i = 0; i < (8 - g->numPlayersOnTile(9)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(8);
    for (int i = 0; i < (8 - g->numPlayersOnTile(8)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(7);
    for (int i = 0; i < (8 - g->numPlayersOnTile(7)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(6);
    for (int i = 0; i < (8 - g->numPlayersOnTile(6)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(5);
    for (int i = 0; i < (8 - g->numPlayersOnTile(5)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(4);
    for (int i = 0; i < (8 - g->numPlayersOnTile(4)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(3);
    for (int i = 0; i < (8 - g->numPlayersOnTile(3)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(2);
    for (int i = 0; i < (8 - g->numPlayersOnTile(2)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(1);
    for (int i = 0; i < (8 - g->numPlayersOnTile(1)); i++) {
        cout << " ";
    }
    cout << "|";
    g->playersOnTile(0);
    for (int i = 0; i < (8 - g->numPlayersOnTile(0)); i++) {
        cout << " ";
    }
    cout << "|" << endl;
    for(int i = 0; i < 11; i++) {
        cout << "|________";
    }
    cout << "|" << endl;

}
