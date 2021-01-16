#include "Pawn.h"
#include "Square.h"
#include "Board.h"
#include "Piece.h"
#include <iostream>
#include <string>
using namespace std;


string Pawn::getSymbol(bool pieceColour) {
    if (pieceColour == true) {
        return "♙";
    } else {
        return "♟";
    }
}  // Used to return the pawn symbol.

bool Pawn::canMove(string *&Arr, bool colour, int startx, int starty, int endx, int endy) {
    // Setting conditions for if the piece can't move. An abstract piece can move anywhere
    // on the board.
    white = colour;
    // If the input if out of bounds, return false
    if (startx < 1 || startx > 8 || starty < 1 || starty > 8 || endx < 1 || endx > 8 || endy < 1 || endy > 8) {
        return false;
    }
    // If the final position is occupied by a piece of the same colour, return false.
    else if (isWhite(Arr[63-endy*8+endx]) == white) {
        return false;
    }
    // for moving a piece to the same square
    else if (startx == endx && starty == endy) {
        return false;
    }
    else {
        if (colour == true) { // Checks is the pawn being moved is white
            if (endx == startx) {  // checks if the pawn is moving forward vertically
                if (starty == 2) {  // Checks if the pawn is starting on its inital square
                    if ((endy == starty+1 || endy == starty+2) && Arr[63-endy*8+endx] == "﹎") { // Checks that the pawn is moving forward to an empty square
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    if (endy != starty+1 || Arr[63-endy*8+endx] != "﹎") { // Checks that the pawn is moving forward to an empty square
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
            else if ((endx == startx+1 && endy == starty+1) || (endx == startx-1 && endy == starty+1)) {   // Checks if the pawn is moving diagonally
                if (isWhite(Arr[63-endy*8+endx]) == false && Arr[63-endy*8+endx] != "﹎") { // Checks if the pawn is moving diagonally to a black piece
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        else { // if the piece is black (same as above but checks for squares occupied by white pieces and pieces now move down the board)
            if (endx == startx) {
                if (starty == 7) {
                    if ((endy == starty-1 || endy == starty-2) && Arr[63-endy*8+endx] == "﹎") {
                        return true;
                    }
                    else {
                        return false;
                    }
                }
                else {
                    if (endy != starty-1 || Arr[63-endy*8+endx] != "﹎") {
                        return false;
                    }
                    else {
                        return true;
                    }
                }
            }
            else if ((endx == startx+1 && endy == starty-1) || (endx == startx-1 && endy == starty-1)) {
                if (isWhite(Arr[63-endy*8+endx]) == true && Arr[63-endy*8+endx] != "﹎") {
                    return true;
                }
                else {
                    return false;
                }
            }
            else {
                return false;
            }
        }
    }
} // // Checks if the pawn is moving to a legal square