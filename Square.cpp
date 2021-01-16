#include "Square.h"
#include <iostream>
#include <stdlib.h>
#include <algorithm>
using namespace std;

// Default constructor
Square::Square() {
    move = "00-00"; // Assigning the default move as an invalid move
}

// This function will be used to read an input and convert that input into a starting coordinate and an ending coordinate.
void Square::position() {
    cout << "enter a move [e.g. E2-E4]: ";
    cin >> move;    // Reading the user's input for their chess move.

    // char *letters = new char[8];
    // letters = {'A','B','C','D','E','F','G','H'};
    // char *numbers = new char[8];
    // numbers = {'1','2','3','4','5','6','7','8'};

    char letters[8] = {'A','B','C','D','E','F','G','H'};
    char numbers[8] = {'1','2','3','4','5','6','7','8'};

    // Setting an invalid input if the input is not 5 characters long.
    if (move.length() != 5) {
        move = "00-00";
    }
    // Setting an invalid input if the delimiter is not in the middle position.
    if (move.at(2) != '-') {
        move = "00-00";
    }

    int count;
    //Replacing all letters with their corresponding numerical value
    for (int i=0; i<5; i++) {
        count = 0;
        for (int j=0; j<8; j++) {

            if (move.at(i) == letters[j]) {
                move.at(i) = numbers[j];
            }
            else if (move.at(i) != numbers[j] && move.at(i) != '-') {
                count++;
            }

            if (count == 8) {
                move = "00-00";    // Setting an invalid number for all remaining invalid characters.
            }

        }

    }

    // delete[] letters;
    // delete[] numbers;

    string delimiter = "-";    // setting the delimiter as - to separate the input

    // The following code block is used to store the start and end moves from the input
    start = move.substr(0, move.find(delimiter));   // storing the first move into "start" by inputing all text upto delimiter
    move.erase(0, move.find(delimiter) + 1);    // deletes the previously read text, including the delimiter
    end = move.substr(0, move.find(delimiter));  // stores the remaining text into "end"

    // Converting from string to integer
    startCoord = stoi(start);
    endCoord = stoi(end);

}

// Returning start coordinate.
int Square::getStart() {return startCoord;}

// Returning end coordinate.
int Square::getEnd() {return endCoord;}

// Find the x value of a coordinate.
void Square::setX(int x) {
    // Dividing by 10 then using modulo 10 assigns the first digit to x.
    this->x = x / 10 % 10;
}

// Return the x value of a coordinate.
int Square::getX() {return x;}

// Find the y value of a coordinate.
void Square::setY(int y) {
    // Using modulo 10 assigns the second digit to y.
    this->y = y % 10;
}

// Return the y value of a coordinate
int Square::getY() {return y;}

// Deconstructor
Square::~Square() {}