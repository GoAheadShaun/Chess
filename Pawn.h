#ifndef PAWN_H_
#define PAWN_H_
#include "Square.h"
#include "Piece.h"
#include "Board.h"
#include <iostream>
using namespace std;

class Pawn : public Piece {

    public:
        string getSymbol(bool pieceColour); // Used to return the pawn symbol.
        bool canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy);    // Checks if the pawn is moving to a legal square
};

#endif