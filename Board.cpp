#include "Square.h"
#include "Board.h"
#include "Piece.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include <iostream>
#include <string>
using namespace std;

// Default constructor
Board::Board() {
    piece_layout = new string[64]; // creating a dynamic array to hold the pieces.
    // Assigning an arbritrary symbol to each square which represents an empty square.
    for (int i=0; i<64; i++) {
        piece_layout[i] = "﹎";
    }
}

// This function will be used to move a piece from its initial position to its new location.
string* Board::makeMove(string *&Arr, int startx, int starty, int endx, int endy) {

    piece_layout = Arr;
    piece_layout[63-endy*8+endx] = piece_layout[63-starty*8+startx];  // Copying the piece to its new location
    piece_layout[63-starty*8+startx] = "﹎"; // Emptying the initial position of the piece

    return piece_layout;
}

// This function will be used to set all pieces to their starting squares.
string* Board::resetBoard() {

    King king;
    Rook rook;
    Bishop bishop;
    Queen queen;
    Knight knight;
    Pawn pawn;

    // Assigning black pieces to their initial positions
    piece_layout[0] = rook.getSymbol(false);
    piece_layout[1] = knight.getSymbol(false);
    piece_layout[2] = bishop.getSymbol(false);
    piece_layout[3] = queen.getSymbol(false);
    piece_layout[4] = king.getSymbol(false);
    piece_layout[5] = bishop.getSymbol(false);
    piece_layout[6] = knight.getSymbol(false);
    piece_layout[7] = rook.getSymbol(false);
    // Assigning white pieces to their initial positions
    piece_layout[56] = rook.getSymbol(true);
    piece_layout[57] = knight.getSymbol(true);
    piece_layout[58] = bishop.getSymbol(true);
    piece_layout[59] = queen.getSymbol(true);
    piece_layout[60] = king.getSymbol(true);
    piece_layout[61] = bishop.getSymbol(true);
    piece_layout[62] = knight.getSymbol(true);
    piece_layout[63] = rook.getSymbol(true);


    // Assigning black and white pawns to their respective initial positions
    for (int i=0; i<8; i++) {
        piece_layout[i+8] = pawn.getSymbol(false);
        piece_layout[55-i] = pawn.getSymbol(true);
    }
}

// This function will be used to print the board.
void Board::printBoard(string *&Arr) {

    piece_layout = Arr;

    // Printing the board
    cout << "   --------------------------------------- " << endl;

    for (int i=0; i<8; i++) {
        cout << (8-i) << "  | ";

        for (int j=0; j<8; j++) {

                cout << piece_layout[i*8+j] << " | ";

        }
        cout << endl;
        cout << "   --------------------------------------- " << endl;
    }

    cout << "     A    B    C    D    E    F    G    H   " << endl;
}

// Returns piece layout array
string* Board::getBoard() {return piece_layout;}

// Checks if either side has a king
int Board::isCheckmate() {
    int countWhite = 0;
    int countBlack = 0;
    King king;
    for (int i=0; i<64; i++) {
        if (piece_layout[i] == king.getSymbol(true)) {
            countWhite ++;
        }
        else if (piece_layout[i] == king.getSymbol(false)) {
            countBlack ++;
        }
    }

    if (countWhite == 0) {
        return 1;
    }
    else if (countBlack == 0) {
        return 2;
    }
    else {
        return 0;
    }
}

// Deconstructor
Board::~Board() {delete[] piece_layout;}