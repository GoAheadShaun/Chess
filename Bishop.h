#ifndef BISHOP_H_
#define BISHOP_H_
#include "Square.h"
#include "Piece.h"
#include "Board.h"
#include <iostream>
using namespace std;

class Bishop : public Piece {

    public:
        string getSymbol(bool pieceColour);  // Used to return the bishop symbol.
        bool canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy);    // Checks if the bishop is moving to a legal square
};

#endif