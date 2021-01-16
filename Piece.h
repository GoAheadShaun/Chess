#ifndef PIECE_H_
#define PIECE_H_
#include "Square.h"
#include <iostream>
using namespace std;

// abstract
class Piece {

    protected:
        int xS, yS, xE, yE;
        int colour;
        bool white; // if white is true, it's white's turn and if white is false, it's black's turn.

    public:
        Piece();    // Default constructor
        void setColour(int alternator); // set the turn as either white or black.
        bool getColour();   // return the current colour being played.
        bool isWhite(string piece); // Checking if a piece is either white or black.
        void setMove();
        virtual bool canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy); // Checking if a move is legal for an abstract piece
        ~Piece();   // Deconstructor
};

#endif