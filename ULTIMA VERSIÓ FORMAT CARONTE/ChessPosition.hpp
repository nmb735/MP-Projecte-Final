#pragma once
//
//  ChessPosition.hpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#ifndef ChessPosition_hpp
#define ChessPosition_hpp

#include <stdio.h>
#include <string>
#include <vector>
#include <cstring>
#include "Piece.hpp"
#include "ChessPosition.hpp"
#include <iostream>

using namespace std;

class ChessPosition {

public:
	//Constructors and Destructors
	ChessPosition() { m_posX = 0; m_posY = 0; };
	ChessPosition(int x, int y) { m_posX = x; m_posY = y; };
	ChessPosition(int r, char c) { m_posX = setWorkingColumn(c); m_posY = setWorkingRow(r); };
	ChessPosition(string pos);
	~ChessPosition() {};

	//Getters and Setters
	int getPositionX() const { return m_posX; };
	int getPositionY() const { return m_posY; };
	void setPositionX(int x) { m_posX = x; };
	void setPositionY(int y) { m_posY = y; };
	void setTot(int x, int y) { m_posX = x; m_posY = y; };

	//Working methods
	int setWorkingRow(int row);
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

	int setWorkingColumn(char column);
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

	int setGraphicRow(int row);
	// DESCRIPTION:
	// Takes the row in working coordinates and swithces it to exportable format.
	//
	// PARAMETERS:
	// row: row in working coordinates. 
	// 
	// RETURN:
	// - Transformed row value.
	// - Specified error message if data doesnt match. 

	char setGraphicColumn(int column);
	// DESCRIPTION:
	// Takes the column in working coordinates and swithces it to exportable format.
	//
	// PARAMETERS:
	// column: column in working coordinates. 
	// 
	// RETURN:
	// - Transformed column value.
	// - Specified error message if data doesnt match.  

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

	int charToInt(char c);
	// DESCRIPTION:
	// Transforms the value of a char into an integer, in order to fit the specified format of board exports.
	//
	// PARAMETERS:
	// c: the char to transform. 
	// 
	// RETURN:
	// - The value of the char in an int variable.
	// - Specified error message if data doesnt match.

	bool operator==(const ChessPosition& a) const;
	// DESCRIPTION:
	// Compares two positions.
	//
	// PARAMETERS:
	// a: auxillry position to compare;. 
	// 
	// RETURN:
	// - TRUE: The two positions are equal.
	// - FALSE: The two positions aren't equal. 

private:
	int m_posX; //Column
	int m_posY; //Row

};

ChessPosition::ChessPosition(string pos)
{
	const char* str = pos.c_str();

	char column = str[0];

	char row = str[1];

	m_posX = setWorkingColumn(column);

	int nRow = charToInt(row);

	m_posY = setWorkingRow(nRow);
}

int ChessPosition::setWorkingRow(int row)
{
	int f;// = -1;

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
		break;
	}

	return f;
}

int ChessPosition::setWorkingColumn(char column)
{
	int c;//= -1;

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

int ChessPosition::setGraphicRow(int row)
{
	int f;//= 0;

	switch (row)
	{
	case 7: f = 1;
		break;
	case 6: f = 2;
		break;
	case 5: f = 3;
		break;
	case 4: f = 4;
		break;
	case 3: f = 5;
		break;
	case 2: f = 6;
		break;
	case 1: f = 7;
		break;
	case 0: f = 8;
		break;
	default: cout << "Invalid row input in file. Check file content and try again." << endl;
		break;
	}

	return f;
}

char ChessPosition::setGraphicColumn(int column)
{
	char c;//= '0';

	switch (column)
	{
	case 0: c = 'a';
		break;
	case 1: c = 'b';
		break;
	case 2: c = 'c';
		break;
	case 3: c = 'd';
		break;
	case 4: c = 'e';
		break;
	case 5: c = 'f';
		break;
	case 6: c = 'g';
		break;
	case 7: c = 'h';
		break;
	default: cout << "Invalid column input in file. Check file content and try again." << endl;
		break;
	}

	return c;
}

char ChessPosition::intToChar(int i)
{
	char c;//= '0';

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

int ChessPosition::charToInt(char c)
{
	int i;//= 0;

	switch (c)
	{
	case '1': i = 1;
		break;
	case '2': i = 2;
		break;
	case '3': i = 3;
		break;
	case '4': i = 4;
		break;
	case '5': i = 5;
		break;
	case '6': i = 6;
		break;
	case '7': i = 7;
		break;
	case '8': i = 8;
		break;
	default: cout << "Number is out of board range." << endl;
		break;
	}

	return i;
}

bool ChessPosition::operator==(const ChessPosition& a) const
{
	bool equal = false;

	if ((m_posX == a.getPositionX()) && (m_posY == a.getPositionY()))
		equal = true;

	return equal;
}

ostream& operator<<(ostream& output, ChessPosition pos);
// DESCRIPTION:
// Prints out the position of a Piece in the graphic-styled coordinates.
//
// PARAMETERS:
// pos: position of the piece, in working coordinates. 
// 
// RETURN:
// Graphic-styled coordinates, printed. 


ostream& operator<<(ostream& output, ChessPosition pos)
{
	//Funcio per test caronte
	char column = pos.setGraphicColumn(pos.getPositionX());
	char row = pos.intToChar(pos.setGraphicRow(pos.getPositionY()));
	string position;
	position.append(1, column);
	position.append(1, row);
	output << position;
	return output;
}

#endif /* ChessPosition_hpp */
