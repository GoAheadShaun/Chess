#include "Piece.h"
#include "Square.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Piece::Piece() {
}

// set the turn as either white or black.
void Piece::setColour(int alternator) {
    colour = alternator;
    // If the alternator is 1, the piece is white. Return true.
    // Else, the piece is black. Return false.
    if (alternator == 1) {
          white = true;
    }
    else {
        white = false;
    }
}

// return the current colour being played.
bool Piece::getColour() {return white;}

// Checking if a piece is either white or black.
bool Piece::isWhite(string piece) {
    bool legal;
    // If it's a white piece, return true.
    if (piece == "♔" || piece == "♕" || piece == "♖" || piece == "♗" || piece == "♘" || piece == "♙")  {
        legal = true;
        return legal;
    }
    // If it's a black piece, return false.
    else if (piece == "♚" || piece == "♛" || piece == "♜" || piece == "♝" || piece == "♞" || piece == "♟︎") {
        legal = false;
        return legal;
    }
    // Else, return the opposite boolean of white (so arbritrary spaces are accepted.)
    else {
        legal = !white;
        return legal;
    }
}

// Checking if a move is legal for an abstract piece
bool Piece::canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy) {
    return true;
}

// Deconstructor
Piece::~Piece() {}