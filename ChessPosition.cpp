//
//  ChessPosition.cpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#include <iostream>
#include <vector> 
#include <cstring>
#include "ChessPosition.hpp"

/* Coordinate system:
	Y (rows)
  . ^
  . |  ***Black***
  4 |
  3 |
  2 |
  1 |  ***White***
 (0,0)----------> X (cols)
	  a b c ...
*/

using namespace std;

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
	int f = -1;

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
	int c = -1;

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
	int f = 0;

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
	char c = '0';

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
	char c = '0';

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
	int i = 0;

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

ostream& operator<<(ostream& output, ChessPosition pos)
{
	//Funcio per test caronte
	char column = pos.setGraphicColumn(pos.getPositionX());
	char row = pos.intToChar(pos.setGraphicRow(pos.getPositionY()));
	string position;
	position.append(1,column);
	position.append(1,row);
	output << position;
	return output;
}	
