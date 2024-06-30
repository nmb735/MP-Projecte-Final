#pragma once
#pragma once
//
//  Piece.hpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#ifndef Piece_hpp
#define Piece_hpp

#include "ChessPosition.hpp"
#include "Piece.hpp"
#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>

using namespace std;

typedef enum {
    CPT_King,
    CPT_Queen,
    CPT_Rook,
    CPT_Bishop,
    CPT_Knight,
    CPT_Pawn,
    CPT_EMPTY
} ChessPieceType;

typedef enum {
    CPC_Black,
    CPC_White,
    CPC_NONE
} ChessPieceColor;

class Piece {

public:
    //Constructors and Destructors
    Piece() { m_color = CPC_NONE; m_type = CPT_EMPTY; m_firstMove = true; };
    Piece(ChessPieceColor color, ChessPieceType type) { m_color = color; m_type = type; m_firstMove = true; };
    ~Piece() {};

    //Getters and Setters
    ChessPieceType getPieceType() const { return m_type; };
    ChessPieceColor getPieceColor() const { return m_color; };
    void setType(ChessPieceType type) { m_type = type; };
    void setColor(ChessPieceColor color) { m_color = color; };

    //Working methods
    bool            printColor(char& c);
    // DESCRIPTION:
    // Determines the color of the selected piece in order to fit the format of export.
    //
    // PARAMETERS:
    // c: color of the piece. 
    // 
    // RETURN:
    // - TRUE: If there is a color/piece assigned.
    // - FALSE: There is no piece assigned to that space. 

    bool            printType(char& t);
    // DESCRIPTION:
    // Determines the type of the selected piece in order to fit the format of export.
    //
    // PARAMETERS:
    // t: type of the piece. 
    // 
    // RETURN:
    // - TRUE: If there is a type/piece assigned.
    // - FALSE: There is no piece assigned to that space. 

    string          pieceToString();
    // DESCRIPTION:
    // Uses other functions to transform the value of a piece into a string, following the specified format.
    //
    // PARAMETERS:
    // -
    // 
    // RETURN:
    // String with piece information in the format. 

    bool            checkIfEmpty();
    // DESCRIPTION:
    // Checks if the space is empty or not.
    //
    // PARAMETERS:
    // -
    // 
    // RETURN:
    // - TRUE: If there is a piece assigned to that space.
     // - FALSE: There is no piece assigned to that space.

private:
    //Attributes
    ChessPieceType  m_type;
    ChessPieceColor m_color;
    bool m_firstMove;
};

bool Piece::printColor(char& c)
{
    bool empty = false;

    if (m_color == CPC_NONE)
        empty = true;
    else
    {
        if (m_color == CPC_Black)
            c = 'b';
        else
            c = 'w';
    }

    return empty;
}

bool Piece::printType(char& t)
{
    bool empty = false;

    if (m_type == CPT_EMPTY)
        empty = true;

    else
    {
        switch (m_type)
        {
        case CPT_King: t = 'R';
            break;
        case CPT_Bishop: t = 'A';
            break;
        case CPT_Knight: t = 'C';
            break;
        case CPT_Pawn: t = 'P';
            break;
        case CPT_Queen: t = 'D';
            break;
        case CPT_Rook: t = 'T';
            break;
        default: cout << "Error en la transformacio. No es detecta el tipus de peça" << endl;
            break;
        }
    }

    return empty;
}

string Piece::pieceToString()
{
    char colorChar;
    string positionStatus;
    char typeChar;
    bool empty = printColor(colorChar);

    if (empty)
        positionStatus = "__";

    else
    {
        empty = printType(typeChar);
        positionStatus.push_back(colorChar);
        positionStatus.push_back(typeChar);
    }

    return positionStatus;
}

bool Piece::checkIfEmpty()
{
    //Per poder utilitzar-se en bool de ValidMove i les seves restriccions.
    bool empty = false;

    if ((m_type == CPT_EMPTY) && (m_color == CPC_NONE))
        empty = true;

    return empty;
}

#endif /* Piece_hpp */
