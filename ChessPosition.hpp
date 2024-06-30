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

#endif /* ChessPosition_hpp */

ostream& operator<<(ostream& output, ChessPosition pos);
// DESCRIPTION:
// Prints out the position of a Piece in the graphic-styled coordinates.
//
// PARAMETERS:
// pos: position of the piece, in working coordinates. 
// 
// RETURN:
// Graphic-styled coordinates, printed. 
