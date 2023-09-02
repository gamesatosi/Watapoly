#ifndef WATOPOLY_DISPLAY
#define WATOPOLY_DISPLAY

// Printing text display to stout requires square.h
#include <iostream>
#include <vector>

class GameBoard;

// no class, just a helper function that takes in the array of squares and prints to stout

// Prints the information contained in 
void printBoard (GameBoard *g);

#endif
