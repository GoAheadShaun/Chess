#include "King.h"
#include "Square.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;

// Used to return the king symbol.
string King::getSymbol(bool pieceColour) {
    if (pieceColour == true) {
        return "♔";
    } else {
        return "♚";
    }
}

// Checks if the king is moving to a legal square
bool King::canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy) {
    // Setting conditions for if the piece can't move. An abstract piece can move anywhere
    // on the board.
    white = colour;
    // If the input if out of bounds, return false
    if (startx < 1 || startx > 8 || starty < 1 || starty > 8 || endx < 1 || endx > 8 || endy < 1 || endy > 8) {
        return false;
    }
    // for moving a piece to the same square
    else if (startx == endx && starty == endy) {
        return false;
    }
    // If the final position is occupied by a piece of the same colour, return false.
    else if (isWhite(Arr[63-endy*8+endx]) == white) {
        return false;
    }
    else if (endx !=  startx-1 && endx != startx+1 && endy != starty-1 && endy != starty+1) {
        return false;
    }
    else {return true;}
}