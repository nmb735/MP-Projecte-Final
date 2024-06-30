#pragma once
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


#include <vector>
#include "ChessPosition.hpp"
#include <istream>
#include <fstream>
#include <iostream>
#include <string.h>

using namespace std;

const int MAX_PIECES = 32;

typedef vector<ChessPosition> VecOfPositions;

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


private:
	static const int NUM_COLS = 8;
	static const int NUM_ROWS = 8;

	Piece m_board[NUM_COLS][NUM_ROWS];
	int m_nBlackPieces;
	int m_nWhitePieces;
};

Chessboard::Chessboard() //constructor
{
}

Chessboard::~Chessboard()
{

}

int Chessboard::realRow(int row)
{
	int f;

	switch (row)
	{
	case 1: f = 7;
		break;
	case 2: f = 6;
		break;
	case 3: f = 5;
		break;
	case 4: f = 4;
		break;
	case 5: f = 3;
		break;
	case 6: f = 2;
		break;
	case 7: f = 1;
		break;
	case 8: f = 0;
		break;
	default: cout << "Invalid row input in file. Check file content and try again." << endl;
		f = -1;
		break;
	}

	return f;
}

int Chessboard::realColumn(char column)
{
	int c;

	switch (column)
	{
	case 'a': c = 0;
		break;
	case 'b': c = 1;
		break;
	case 'c': c = 2;
		break;
	case 'd': c = 3;
		break;
	case 'e':c = 4;
		break;
	case 'f':c = 5;
		break;
	case 'g':c = 6;
		break;
	case 'h':c = 7;
		break;
	default: cout << "Invalid column input in file. Check file content and try again." << endl;
		break;
	}

	return c;
}

ChessPieceType Chessboard::realType(char type)
{
	ChessPieceType t;

	switch (type)
	{
	case 'R': t = CPT_King;
		break;
	case 'D': t = CPT_Queen;
		break;
	case 'T': t = CPT_Rook;
		break;
	case 'A': t = CPT_Bishop;
		break;
	case 'C': t = CPT_Knight;
		break;
	case 'P': t = CPT_Pawn;
		break;
	default: t = CPT_EMPTY; cout << "Error while reading the piece type. Check the file's content and try again." << endl;
		break;
	}

	return t;
}

ChessPieceColor Chessboard::realColor(int color)
{
	ChessPieceColor c;
	if (color == 0)
		c = CPC_White;
	else
		c = CPC_Black;

	return c;
}

void Chessboard::LoadBoardFromFile(const string& path)
{
	ifstream file;
	file.open(path);

	int color;
	char dot;
	char type;
	char column;
	int row;

	do
	{
		file >> color >> dot >> type >> column >> row;

		int c = realColumn(column);

		int f = realRow(row);

		ChessPieceColor col = realColor(color);

		ChessPieceType typ = realType(type);

		m_board[f][c].setColor(col);

		m_board[f][c].setType(typ);

	} while ((!file.eof()));

	file.close();
}

char Chessboard::intToChar(int i)
{
	char c;

	switch (i)
	{
	case 1: c = '1';
		break;
	case 2: c = '2';
		break;
	case 3: c = '3';
		break;
	case 4: c = '4';
		break;
	case 5: c = '5';
		break;
	case 6: c = '6';
		break;
	case 7: c = '7';
		break;
	case 8: c = '8';
		break;
	default: cout << "Number is out of board range." << endl;
		break;
	}

	return c;
}

string  Chessboard::ToString()
{
	static const int END = 0;
	static const int ROWS = 8;
	static const int COLUMNS = 8;
	static const int MAX_P = 64;
	string exportCB;
	string rowStatus[MAX_P];
	string arrayElement;
	int x = 0;

	while (x < MAX_P)
	{
		for (int i = 0; i < ROWS; i++)
		{
			for (int j = 0; j < COLUMNS; j++)
			{
				arrayElement = m_board[i][j].pieceToString();
				rowStatus[x] = arrayElement;
				x++;
			}
		}
	}

	int y = 0;

	while (y < MAX_P)
	{
		for (int k = 8; k > 0; k--)
		{
			exportCB.append(1, intToChar(k));
			for (int s = 0; s < COLUMNS; s++)
			{
				exportCB.append(" ");
				exportCB.append(rowStatus[y]);
				y++;
			}
			exportCB.append(1, '\n'); //new line
		}
	}

	string lletresColumnes[COLUMNS] = { "a", "b", "c", "d", "e", "f", "g", "h" };

	exportCB.append("  ");
	for (int u = 0; u < COLUMNS; u++)
	{
		exportCB.append(lletresColumnes[u]);
		exportCB.append("  ");
	}

	return exportCB;
}

bool Chessboard::MovePiece(const ChessPosition& posFrom, const ChessPosition& posTo)
{
	VecOfPositions v = GetValidMoves(posFrom);

	int i = 0;
	int x1 = posFrom.getPositionX();
	int y1 = posFrom.getPositionY();

	int x2 = posTo.getPositionX();
	int y2 = posTo.getPositionY();

	cout << "MARC Pos inicial: x1- " << x1 << ", y1- " << y1 << endl;
	cout << "MARC Pos final: x2- " << x2 << ", y2- " << y2 << endl;

	bool trobat = false;

	while ((i < v.size()) && (!trobat))
	{
		if (v[i] == posTo)
			trobat = true;
		else
			i++;
	}

	if (trobat)
	{
		//Data from posFrom to posTo

		m_board[y2][x2].setColor(m_board[y1][x1].getPieceColor()); //Move the piece
		m_board[y2][x2].setType(m_board[y1][x1].getPieceType());

		m_board[y1][x1].setColor(CPC_NONE); //Empty previous piece.
		m_board[y1][x1].setType(CPT_EMPTY);


	}

	return trobat;
}

void Chessboard::sumTeams()
{
	static const int MAX = 16;
	m_nBlackPieces = 0;
	m_nWhitePieces = 0;

	for (int i = 0; i < MAX; i++)
	{
		for (int j = 0; j < MAX; i++)
		{
			if (m_board[i][j].getPieceColor() == CPC_White)
				m_nWhitePieces++;
			else
			{
				if (m_board[i][j].getPieceColor() == CPC_Black)
					m_nBlackPieces++;
			}
		}
	}
}

bool Chessboard::outOfBounds(const ChessPosition& pos1, const ChessPosition& pos2) const {

	bool legal = false;

	int x, y;
	x = pos1.getPositionX();
	y = pos1.getPositionY();

	int d = 7 - y;  //lim. right
	int e = y; //lim left
	int up = x; //lim up
	int down = 7 - x; //lim down

	if ((pos2.getPositionY() <= 7) && (pos2.getPositionY() >= 0) && (pos2.getPositionX() >= 0) && (pos2.getPositionX() <= 7))
	{
		legal = true;
	}

	if (legal == true)
		return false;
	else
		return true;
}

bool Chessboard::opositionPiece(const ChessPosition& pos1, const ChessPosition& pos2) const {

	bool rival = false;

	int x = pos2.getPositionX(); //positions x and y of destination
	int y = pos2.getPositionY();

	int r = pos1.getPositionX();//positions x and y of origin
	int c = pos1.getPositionY();

	if (m_board[c][r].getPieceColor() != CPC_NONE)
	{
		if (m_board[c][r].getPieceColor() == CPC_Black) // If the piece is black, the rivals are white.
		{
			if (m_board[y][x].getPieceColor() == CPC_White)
			{
				rival = true;
			}
		}
		else // If the piece is white, the rivals are black.
		{
			if (m_board[y][x].getPieceColor() == CPC_Black)
			{
				rival = true;
			}
		}
	}

	return rival;
}

bool Chessboard::teamPiece(const ChessPosition& pos1, const ChessPosition& pos2) const {

	bool teamPiece = false;

	int x = pos2.getPositionX(); //positions x and y of destination
	int y = pos2.getPositionY();

	int r = pos1.getPositionX(); //positions x and y of origin
	int c = pos1.getPositionY();

	if (m_board[c][r].getPieceColor() != CPC_NONE)
	{
		if (m_board[c][r].getPieceColor() == CPC_Black)
		{
			if (m_board[y][x].getPieceColor() == CPC_Black)
			{
				teamPiece = true;
			}
		}
		else
		{
			if (m_board[y][x].getPieceColor() == CPC_White)
			{
				teamPiece = true;
			}
		}
	}

	return teamPiece;
}

VecOfPositions Chessboard::posKing(const ChessPosition& pos) const {

	VecOfPositions v; //Dynamic vector
	ChessPosition p;
	Piece cp;

	int x = pos.getPositionX();
	int y = pos.getPositionY();

	//Right
	p.setTot(x + 1, y);
	cp = m_board[y][x + 1];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	//Left
	p.setTot(x - 1, y);
	cp = m_board[y][x - 1];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	//Up
	p.setTot(x, y + 1);
	cp = m_board[y + 1][x];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	//Down
	p.setTot(x, y - 1);
	cp = m_board[y - 1][x];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	//Diagonal Right-Up
	p.setTot(x + 1, y + 1);
	cp = m_board[y + 1][x + 1];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	//Diagonal Left-Up
	p.setTot(x - 1, y + 1);
	cp = m_board[y + 1][x - 1];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	//Diagonal Right-Down
	p.setTot(x + 1, y - 1);
	cp = m_board[y - 1][x + 1];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	//Diagonal Left-Down
	p.setTot(x - 1, y - 1);
	cp = m_board[y - 1][x - 1];
	if ((!outOfBounds(pos, p)))
	{
		if (cp.checkIfEmpty())
		{
			v.push_back(p);
		}

		else
		{
			if ((!teamPiece(pos, p)))
			{
				v.push_back(p);
			}
		}
	}

	return v;
}

VecOfPositions Chessboard::posKnight(const ChessPosition& pos) const { //direccions dels comentaris en un grafic real, no de programacio, pero funciona igual

	VecOfPositions v; //Dynamic Vector
	ChessPosition p;

	int x = pos.getPositionX();
	int y = pos.getPositionY();

	p.setTot(x + 1, y + 2);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); //Up - Right
	}

	p.setTot(x - 1, y + 2);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); // Up - Left
	}

	p.setTot(x + 1, y - 2);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); //Down - Right
	}

	p.setTot(x - 1, y - 2);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); //Down - Left
	}

	p.setTot(x + 2, y + 1);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); // Right - Up
	}

	p.setTot(x + 2, y - 1);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); // Right - Down
	}

	p.setTot(x - 2, y + 1);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); // Left - Up
	}

	p.setTot(x - 2, y - 1);
	if (!outOfBounds(pos, p) && !teamPiece(pos, p))
	{
		v.push_back(p); // Left - Down
	}

	return v;
}

VecOfPositions Chessboard::posRook(const ChessPosition& pos) const { //direccions dels comentaris en un grafic real, no de programacio, pero funciona igual

	VecOfPositions v; //Dynamic Vector
	ChessPosition p;

	int x = pos.getPositionX();
	int y = pos.getPositionY();

	for (int a = 0; a < 4; a++) // Each direction of the Rook
	{
		int i = 0;
		int j = 0;
		bool stop = false;
		do
		{
			switch (a)
			{
			case 0: i++; //Right
				break;
			case 1: i--; //Left
				break;
			case 2: j++; //Up
				break;
			case 3: j--; //Down
				break;
			}

			p.setTot(x + i, y + j);
			if (opositionPiece(pos, p) && !outOfBounds(pos, p) && !teamPiece(pos, p))
			{
				v.push_back(p);
				stop = true;
			}
			else
			{
				if (!outOfBounds(pos, p) && !teamPiece(pos, p))
				{
					v.push_back(p);
				}
				else
				{
					stop = true;
				}
			}
		} while (!stop);
	}
	return v;
}

VecOfPositions Chessboard::posBishop(const ChessPosition& pos) const { //direccions dels comentaris en un grafic real, no de programacio, pero funciona igual

	VecOfPositions v; //Dynamic Vector
	ChessPosition p;

	int x = pos.getPositionX();
	int y = pos.getPositionY();

	for (int a = 0; a < 4; a++) // Each direction of Bishop
	{
		int i = 0;
		int j = 0;
		bool stop = false;
		do
		{
			switch (a)
			{
			case 0: // Up - Right
				i++;
				j++;
				break;
			case 1: // Up - Left
				i--;
				j++;
				break;
			case 2: // Down - Right
				i++;
				j--;
				break;
			case 3: // Down - Left
				i--;
				j--;
				break;
			}

			p.setTot(x + i, y + j);
			if (opositionPiece(pos, p) && !outOfBounds(pos, p) && !teamPiece(pos, p))
			{
				v.push_back(p);
				stop = true;
			}
			else
			{
				if (!outOfBounds(pos, p) && !teamPiece(pos, p))
				{
					v.push_back(p);
				}
				else
				{
					stop = true;
				}
			}
		} while (!stop);
	}
	return v;
}

VecOfPositions Chessboard::posQueen(const ChessPosition& pos) const { //direccions dels comentaris en un grafic real, no de programacio, pero funciona igual

	VecOfPositions v; // Dynamic Vector
	ChessPosition p;


	int x = pos.getPositionX();
	int y = pos.getPositionY();

	for (int a = 0; a < 8; a++) // Each Direction of Queen
	{
		int i = 0;
		int j = 0;
		bool stop = false;
		do
		{
			switch (a)
			{
			case 0: i++; //Right
				break;
			case 1: i--; //Left
				break;
			case 2: j++; //Up
				break;
			case 3: j--; //Down
				break;
			case 4: //Up - Right
				i++;
				j++;
				break;
			case 5: //Up - Left
				i--;
				j++;
				break;
			case 6: //Down - Right
				i++;
				j--;
				break;
			case 7: // Down - Left
				i--;
				j--;
				break;
			}

			p.setTot(x + i, y + j);
			if (opositionPiece(pos, p) && !outOfBounds(pos, p) && !teamPiece(pos, p))
			{
				v.push_back(p);
				stop = true;
			}
			else
			{
				if (!outOfBounds(pos, p) && !teamPiece(pos, p))
				{
					v.push_back(p);
				}
				else
				{
					stop = true;
				}
			}
		} while (!stop);
	}
	return v;
}

VecOfPositions Chessboard::posPawn(const ChessPosition& pos) const { //Al tauler les negres van a dalt i les blanqes a baix

	VecOfPositions v; //Dynamic Vector
	ChessPosition p;

	int x = pos.getPositionX();
	int y = pos.getPositionY();

	if (m_board[y][x].getPieceColor() == CPC_Black)
	{
		p.setTot(x, y + 1); //Can always move one in front
		if (!outOfBounds(pos, p) && !teamPiece(pos, p))
		{
			v.push_back(p);
		}

		if (y == 1 && !teamPiece(pos, p) && !opositionPiece(pos, p)) //If its in its statring position, it can move two ahead if there is no opposition piece.
		{
			p.setTot(x, y + 2);
			if (!outOfBounds(pos, p) && !teamPiece(pos, p))
			{
				v.push_back(p);
			}
		}

		//KILL
		//right
		p.setTot(x + 1, y + 1);
		if (opositionPiece(pos, p))
		{
			v.push_back(p);
		}

		//left
		p.setTot(x - 1, y + 1);
		if (opositionPiece(pos, p))
		{
			v.push_back(p);
		}
	}
	else
	{
		if (m_board[y][x].getPieceColor() == CPC_White)
		{
			p.setTot(x, y - 1); //Always moves one ahead
			if (!outOfBounds(pos, p) && !teamPiece(pos, p))
			{
				v.push_back(p);
			}

			if (y == 6 && !teamPiece(pos, p) && !opositionPiece(pos, p)) // If its in the starting position, it may move two ahead
			{
				p.setTot(x, y - 2);
				if (!outOfBounds(pos, p) && !teamPiece(pos, p))
				{
					v.push_back(p);
				}
			}

			//KILL
		//Right
			p.setTot(x + 1, y - 1);
			if (opositionPiece(pos, p))
			{
				v.push_back(p);
			}

			//Left
			p.setTot(x - 1, y - 1);
			if (opositionPiece(pos, p))
			{
				v.push_back(p);
			}
		}
	}

	return v;
}

VecOfPositions Chessboard::GetValidMoves(const ChessPosition& pos) const
{

	VecOfPositions v; //Dynamic vector
	ChessPosition p;

	v.resize(0);

	int x = pos.getPositionX();
	int y = pos.getPositionY();

	switch (m_board[y][x].getPieceType())
	{
	case CPT_King://REI<- one position (8 possibilities max)
		v = posKing(pos);
		break;
	case CPT_Queen://DAMA<- straight (vertical and horizontal) and diagonal (both axis)
		v = posQueen(pos);
		break;
	case CPT_Rook://TORRE<- Straight (vertical and horizontal)
		v = posRook(pos);
		break;
	case CPT_Bishop://ALFIL<- Diagonal (both axis)
		v = posBishop(pos);
		break;
	case CPT_Knight://CAVALL<- "L" shape
		v = posKnight(pos);
		break;
	case CPT_Pawn://PEO<- Strating position: 2; After: 1; Diagonal (Front) for killing.
		v = posPawn(pos);
		break;
	}

	return v;
}

ChessPieceColor Chessboard::GetPieceColorAtPos(const ChessPosition& pos) const
{
	ChessPieceColor c = m_board[pos.getPositionY()][pos.getPositionX()].getPieceColor();

	return c;
}

ChessPieceType  Chessboard::GetPieceTypeAtPos(const ChessPosition& pos) const
{
	ChessPieceType t = m_board[pos.getPositionY()][pos.getPositionX()].getPieceType();

	return t;
}

#endif /* Chessboard_hpp */