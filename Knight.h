#ifndef KNIGHT_H_
#define KNIGHT_H_
#include "Square.h"
#include "Piece.h"
#include "Board.h"
#include <iostream>
using namespace std;

class Knight : public Piece {

    public:
        string getSymbol(bool pieceColour);  // Used to return the knight symbol.
        bool canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy);    // Checks if the knight is moving to a legal square
};

#endif