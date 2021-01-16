# Main output
out: main.o Square.o Board.o Piece.o King.o Rook.o Bishop.o Queen.o Knight.o Pawn.o
	g++ main.o Square.o Board.o Piece.o King.o Rook.o Bishop.o Queen.o Knight.o Pawn.o -o out

main.o: main.cpp
	g++ -c main.cpp

Square.o: Square.cpp Square.h
	g++ -c Square.cpp

Board.o: Board.cpp Board.h
	g++ -c Board.cpp

Piece.o: Piece.cpp Piece.h
	g++ -c Piece.cpp

King.o: King.cpp King.h
	g++ -c King.cpp

Rook.o: Rook.cpp Rook.h
	g++ -c Rook.cpp

Bishop.o: Bishop.cpp Bishop.h
	g++ -c Bishop.cpp

Queen.o: Queen.cpp Queen.h
	g++ -c Queen.cpp

Knight.o: Knight.cpp Knight.h
	g++ -c Knight.cpp

Pawn.o: Pawn.cpp Pawn.h
	g++ -c Pawn.cpp

# Removing all .o files
clean:
	rm *.o out