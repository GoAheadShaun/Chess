#ifndef KING_H_
#define KING_H_
#include "Square.h"
#include "Piece.h"
#include "Board.h"
#include <iostream>
using namespace std;

class King : public Piece {

    public:
        string getSymbol(bool pieceColour); // Used to return the king symbol.
        bool canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy);    // Checks if the king is moving to a legal square
};

#endif