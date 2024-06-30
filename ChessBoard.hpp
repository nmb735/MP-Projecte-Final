//
//  Chessboard.hpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#ifndef Chessboard_hpp
#define Chessboard_hpp

#include <stdio.h>
#include "Piece.hpp"
#include "GameInfo.h"
#include "ChessPosition.hpp"

class Chessboard {

public:
	//Conctructors and Destructors
	Chessboard();
	~Chessboard();

	//Getters and Setters
	int getNBlackPieces() const { return m_nBlackPieces; };
	int getNWhitePieces() const { return m_nWhitePieces; };
	void setPiece(int i, int j, Piece p) { m_board[i][j] = p; };
	void setPiece(const Piece& p, const ChessPosition& pos) { m_board[pos.getPositionY() - 1][pos.getPositionX() - 1] = p; }; //Retirar "- 1"
	Piece getPiece(const ChessPosition& pos) const { return m_board[pos.getPositionY() - 1][pos.getPositionX() - 1]; }; //Retirar "- 1"

	//Working Methods
	void render() const;

	void sumTeams();
	// DESCRIPTION:
	// Changes the attributes of the class to fit the number of pieces left on each team.
	//
	// PARAMETERS:
	// -
	// 
	// RETURN:
	// - 

	int realRow(int row);
	// DESCRIPTION:
	// Takes the row read and used by the board and the file's data, 
	// and transforms it into adquate coordinates.
	//
	// PARAMETERS:
	// row: row read by the file or aquired elsewhere. 
	// 
	// RETURN:
	// - Transformed row value.
	// - Specified error message if data doesnt match. 

	int realColumn(char column);
	// DESCRIPTION:
	// Takes the column read and used by the board and the file's data, 
	// and transforms it into adquate coordinates.
	//
	// PARAMETERS:
	// column: column read by the file or aquired elsewhere. 
	// 
	// RETURN:
	// - Transformed column value.
	// - Specified error message if data doesnt match.

	ChessPieceType  realType(char type);
	// DESCRIPTION:
	// Takes the type of piece read and used by the board and the file's data, 
	// and transforms it into workable data.
	//
	// PARAMETERS:
	// type: type read by the file or aquired elsewhere. 
	// 
	// RETURN:
	// - Transformed type value.
	// - Specified error message if data doesnt match.

	ChessPieceColor realColor(int color);
	// DESCRIPTION:
	// Takes the color of piece read and used by the board and the file's data, 
	// and transforms it into workable data.
	//
	// PARAMETERS:
	// color: color read by the file or aquired elsewhere. 
	// 
	// RETURN:
	// - Transformed color value.
	// - Specified error message if data doesnt match.

	void LoadBoardFromFile(const string& path);
	// DESCRIPTION:
	// Reads a board's status through data inside of a file in a
	// specific and previoulsy specified format.
	//
	// PARAMETERS:
	// path: name of the file. 
	// 
	// RETURN:
	// Does not return anything as it is a void, however it will initialize the board 
	 // with the given data.

	bool MovePiece(const ChessPosition& posFrom, const ChessPosition& posTo);
	// DESCRIPTION:
	// Moves a piece following the parameter's instructions and the respective piece's information.
	// Uses the function in Piece.h to determine if the space is empty.
	//
	// PARAMETERS:
	// posFrom: position of origin.
	// posTo: new desired position. 
	// 
	// RETURN:
	// - TRUE: the move was possible.
	// - FALSE: the move was not possible.

	char intToChar(int i);
	// DESCRIPTION:
	// Transforms the value of an integer into a char, in order to fit the specified format of board exports.
	//
	// PARAMETERS:
	// i: the integer to transform. 
	// 
	// RETURN:
	// - The value of the integer in a char variable.
	// - Specified error message if data doesnt match.

	string  ToString();
	// DESCRIPTION:
	// Transforms the state of the board into a string with a specific reading format.
	//
	// PARAMETERS:
	// - 
	// 
	// RETURN:
	// - The string with the board's information.

	 //Working Methods Sub-Aspect 1: Get Valid Moves

	bool outOfBounds(const ChessPosition& pos_esta, const ChessPosition& pos) const;
	// DESCRIPTION:
	// Analizes if a move exits the board's dimensions.
	//
	// PARAMETERS:
	// -
	// 
	// RETURN:
	// - TRUE: There is a position that exits the board's dimensions, making the move illegal.
	// - FALSE: There isn't a position that exits the board's dimensions, making the move legal.
	//

   // bool check();
	// DESCRIPTION:
	// Analizes if a move originates a check situation.
	//
	// PARAMETERS:
	// -
	// 
	// RETURN:
	// - TRUE: There is a position that originates a check situation, making the move illegal.
	// - FALSE: There isn't a position that originates a check situation, making the move legal.
	//

   // bool checkMate();
	// DESCRIPTION:
	// Analizes if a move originates a check mate situation.
	//
	// PARAMETERS:
	// -
	// 
	// RETURN:
	// - TRUE: There is a position that originates a check mate situation, making the move illegal.
	// - FALSE: There isn't a position that originates a check mate situation, making the move legal.
	//

	bool opositionPiece(const ChessPosition& pos_esta, const ChessPosition& pos) const;;
	// DESCRIPTION:
	// Analizes if a move end up on an opposition piece.
	//
	// PARAMETERS:
	// -
	// 
	// RETURN:
	// - TRUE: There is a position that ends up on an opposition piece, making the move illegal.
	// - FALSE: There isn't a position that ends up on an opposition piece, making the move legal.
	//

	bool teamPiece(const ChessPosition& pos_esta, const ChessPosition& pos) const;
	// DESCRIPTION:
	// Analizes if a move end up on a team piece.
	//
	// PARAMETERS:
	// -
	// 
	// RETURN:
	// - TRUE: There is a position that ends up on a team piece, making the move illegal.
	// - FALSE: There isn't a position that ends up on a team piece, making the move legal.
	//

	VecOfPositions posKing(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Determines the valid moves for the King piece.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Vector of positions with the possible positions.

	VecOfPositions posKnight(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Determines the valid moves for the Knight piece.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Vector of positions with the possible positions.

	VecOfPositions posRook(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Determines the valid moves for the Rook piece.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Vector of positions with the possible positions.

	VecOfPositions posBishop(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Determines the valid moves for the Bishop piece.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Vector of positions with the possible positions.

	VecOfPositions posPawn(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Determines the valid moves for the Pawn piece.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Vector of positions with the possible positions.

	VecOfPositions posQueen(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Determines the valid moves for the Queen piece.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Vector of positions with the possible positions.

	VecOfPositions GetValidMoves(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Analizes which moves are legal according to a piece's structure and their situation.
	// The proces will analize which piece is located in the position, and it will call a function analyzing the available moves.
	// PARAMETERS:
	// pos: position of the piece.
	// 
	// RETURN:
	// Vector of valid moves.

	ChessPieceColor GetPieceColorAtPos(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Obtains the color of a piece in a certain position.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Color of the piece.

	ChessPieceType  GetPieceTypeAtPos(const ChessPosition& pos) const;
	// DESCRIPTION:
	// Obtains the type of a piece in a certain position.
	//
	// PARAMETERS:
	// pos: position where the piece is located in.
	// 
	// RETURN:
	// - Type of the piece.

	ChessPosition   emptyPos ();

	bool			isItKing(const int& x, const int& y) { return (m_board[y][x].getPieceType() == CPT_King); }


private:
	static const int NUM_COLS = 8;
	static const int NUM_ROWS = 8;

	Piece m_board[NUM_COLS][NUM_ROWS];
	int m_nBlackPieces;
	int m_nWhitePieces;
};


#endif /* Chessboard_hpp */
