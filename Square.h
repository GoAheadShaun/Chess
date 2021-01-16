#ifndef SQUARE_H_
#define SQUARE_H_
#include <iostream>
#include "Piece.h"
using namespace std;

class Square {

    private:
        string move;
        string start;
        string end;
        int startCoord;
        int endCoord;
        int x;
        int y;


    public:
        Square();   // Default constructor
        void position();    // Function used to get an input from the user and convert that input to coordinates
        int getStart(); //  Returning the coordinate of the initial piece position
        int getEnd();   // Returning the coordinate of the final piece position
        void setX(int x);   // Separating  the x component of a coordinate
        int getX(); // Returning the x component of a coordinate
        void setY(int y); // Extracting the y component of a coordinate
        int getY(); // Returning the y component of a coordinate
        ~Square();  // Deconstructor
};


#endif