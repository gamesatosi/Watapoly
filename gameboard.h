#ifndef GAMEBOARD
#define GAMEBOARD

#include <string>
using namespace std;

class Square;
class Random;
class Player;
class OwnableBuilding;

class GameBoard {
    Square *theBoard[41];
    Random *dice;
    Player *players[8];
    char playerIcons[8];
    int cups;
    int current; 

    public:
    bool rolled;
    int numOfPlayers;
    void setPlayer(int i, string n, char c, int timscups, int money, int pos, int DCturns); 
    Player *currentPlayer;
    GameBoard(int cups = 0, int numOfPlayers = 6, bool whether_new = false); // default construction
    ~GameBoard(); // default deletion
    int numCups(); // returns number of cups
    bool isOver(); // checks if only one player has non-zero amount of money
    std::string winner(); //  returns name of player with non-zero amount of money, assumes there is at least one player
                          //  with non-zero money, returns first player with non-zero money if there are multiple
    void roll(); // rolls the die and advances the current player by the amount rolled
    void roll(int die1, int die2); // advances the current player as if they rolled 2 predetermined numbers
    void nextTurn(); // advances to next turn
    void playersOnTile(int i); // prints character icons of all players on the i-th square
    int numPlayersOnTile(int i); // returns number of players on a tile
    Square *getSquare(int i); // returns a pointer to the i-th square on the board
    Player *getPlayer(int i); // returns a pointer to the i-th player in the player array
    Player *getPlayer(std::string name); // returns a pointer to the player with name "name". There must be an existing player
                                         // with name "name"
    Square* ownable(int i); // get the ith ownable building

    Player **getPlayer();
    Square **getSquare();
    Square *getSquare(string s);
    void unmortgage(Square* s);
    void mortgage(Square* s);
    Square* academic(int i);
    bool ownable(string s); // check whether the string is a ownable building
    string auction(Player *players[8], int &current_bid, int maxPlayers, Player *p);
    bool onlyOne(bool withdrawn[8], int max);
};

#endif
