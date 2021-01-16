#include <iostream>
#include <string>
#include "Board.h"
#include "Square.h"
#include "Piece.h"
#include "King.h"
#include "Rook.h"
#include "Bishop.h"
#include "Queen.h"
#include "Knight.h"
#include "Pawn.h"
#include <stdlib.h>
#include <algorithm>
using namespace std;

int main(void) {

    int count;
    int alternator;
    alternator = -1;
    bool checkmate = false;

    Board board;
    board.resetBoard();
    string * arr2 = board.getBoard();
    board.printBoard(arr2);

    // A WHILE loop used to keep the game running until either side's king is captured.
    while (checkmate == false) {
        count = 0;
        alternator *= -1;   // To switch between turns

        // Printing outputs.
        if (alternator == 1) {
            cout << "White to play, ";
        } else {
            cout << "Black to play, ";
        }

        // Creating a while loop
        while (count == 0) {
            // Getting start coordinates and end coordinates
            Square square;
            square.position();
            square.setX(square.getStart());
            square.setY(square.getStart());
            int xS = square.getX();
            int yS = square.getY();
            square.setX(square.getEnd());
            square.setY(square.getEnd());
            int xE = square.getX();
            int yE = square.getY();

            // Creating objects for each piece type
            Piece piece;
            King king;
            Rook rook;
            Bishop bishop;
            Queen queen;
            Knight knight;
            Pawn pawn;

            piece.setColour(alternator);    // Setting the colour of the current player's piece.
            bool colour = piece.getColour();

            // Setting conditions for if the KING is being moved
            if (arr2[63-yS*8+xS] == king.getSymbol(true) || arr2[63-yS*8+xS] == king.getSymbol(false)) {
                if (king.canMove(arr2, colour, xS, yS, xE, yE) == false) {
                    board.printBoard(arr2);
                    cout << "Invalid move! Please re-";

                } else {
                    arr2 = board.makeMove(arr2, xS, yS, xE, yE);
                    board.printBoard(arr2);
                    count++;
                }
            }

            // Setting conditions for if the ROOK is being moved
            else if (arr2[63-yS*8+xS] == rook.getSymbol(true) || arr2[63-yS*8+xS] == rook.getSymbol(false)) {
                if (rook.canMove(arr2, colour, xS, yS, xE, yE) == false) {
                    board.printBoard(arr2);
                    cout << "Invalid move! Please re-";

                } else {
                    arr2 = board.makeMove(arr2, xS, yS, xE, yE);
                    board.printBoard(arr2);
                    count++;
                }
            }

            // Setting conditions for if the BISHOP is being moved
            else if (arr2[63-yS*8+xS] == bishop.getSymbol(true) || arr2[63-yS*8+xS] == bishop.getSymbol(false)) {
                if (bishop.canMove(arr2, colour, xS, yS, xE, yE) == false) {
                    board.printBoard(arr2);
                    cout << "Invalid move! Please re-";

                } else {
                    arr2 = board.makeMove(arr2, xS, yS, xE, yE);
                    board.printBoard(arr2);
                    count++;
                }
            }

            // Setting conditions for if the QUEEN is being moved
            else if (arr2[63-yS*8+xS] == queen.getSymbol(true) || arr2[63-yS*8+xS] == queen.getSymbol(false)) {
                if (queen.canMove(arr2, colour, xS, yS, xE, yE) == false) {
                    board.printBoard(arr2);
                    cout << "Invalid move! Please re-";

                } else {
                    arr2 = board.makeMove(arr2, xS, yS, xE, yE);
                    board.printBoard(arr2);
                    count++;
                }
            }

            // Setting conditions for if the KNIGHT is being moved
            else if (arr2[63-yS*8+xS] == knight.getSymbol(true) || arr2[63-yS*8+xS] == knight.getSymbol(false)) {
                if (knight.canMove(arr2, colour, xS, yS, xE, yE) == false) {
                    board.printBoard(arr2);
                    cout << "Invalid move! Please re-";

                } else {
                    arr2 = board.makeMove(arr2, xS, yS, xE, yE);
                    board.printBoard(arr2);
                    count++;
                }
            }

            // Setting conditions for if the PAWN is being moved
            else if (arr2[63-yS*8+xS] == pawn.getSymbol(true) || arr2[63-yS*8+xS] == pawn.getSymbol(false)) {
                if (pawn.canMove(arr2, colour, xS, yS, xE, yE) == false) {
                    board.printBoard(arr2);
                    cout << "Invalid move! Please re-";

                } else {
                    arr2 = board.makeMove(arr2, xS, yS, xE, yE);
                    board.printBoard(arr2);
                    count++;
                }
            }

            // For an ABSTRACT PIECE
            else {
                if (piece.canMove(arr2, colour, xS, yS, xE, yE) == false) {
                    board.printBoard(arr2);
                    cout << "Invalid move! Please re-";

                } else {
                    arr2 = board.makeMove(arr2, xS, yS, xE, yE);
                    board.printBoard(arr2);
                    count++;
                }
            }
        }

        // Checking if either king has been captured.
        if (board.isCheckmate() == 2) {
            checkmate = true;
            cout << "GG! White wins the war." << endl;
        }
        else if (board.isCheckmate() == 1) {
            checkmate = true;
            cout << "GG! Black wins the war." << endl;
        }
        else {
            checkmate = false;
        }
    }

    return 0;
}