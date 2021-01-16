#ifndef BOARD_H_
#define BOARD_H_
#include "Square.h"
#include "Piece.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>
using namespace std;

class Board {

    private:
        string *piece_layout; // An array to store the pieces in their respective positions.


    public:
        Board(); // Default constructor
        string* resetBoard();   // This function will be used to set all pieces to their starting squares.
        string* makeMove(string *&Arr, int startx, int starty, int endx, int endy); // This function will be used to move a piece from its initial position to its new location.
        void printBoard(string *&Arr);  // This function will be used to print the board.
        string* getBoard(); // Returning currect piece layout.
        int isCheckmate();  // Checks if either side has a king.
        ~Board();   // Deconstructor
};

#endif