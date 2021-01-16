#ifndef QUEEN_H_
#define QUEEN_H_
#include "Square.h"
#include "Piece.h"
#include "Board.h"
#include <iostream>
using namespace std;

class Queen : public Piece {

    public:
        string getSymbol(bool pieceColour);  // Used to return the queen symbol.
        bool canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy);    // Checks if the queen is moving to a legal square
};

#endif