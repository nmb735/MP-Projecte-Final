//
//  Piece.hpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#ifndef Piece_hpp
#define Piece_hpp

#include <stdio.h>
#include <vector>
#include <string>
#include "ChessPosition.hpp"
#include "GameInfo.h"

using namespace std;

typedef enum {
    CPT_King,
    CPT_Queen,
    CPT_Rook, // TORRE
    CPT_Bishop, // ALFIL
    CPT_Knight, // CABALLO
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
    Piece() { m_color = CPC_NONE; m_type = CPT_EMPTY; m_firstMove = true;};
    Piece(ChessPieceColor color, ChessPieceType type) { m_color = color; m_type = type; m_firstMove = true; };
    ~Piece() {};

    //Getters and Setters
    ChessPieceType getPieceType() const { return m_type; };
    ChessPieceColor getPieceColor() const { return m_color; };
    void setType(ChessPieceType type) { m_type = type; };
    void setColor(ChessPieceColor color) { m_color = color; };

    //Working methods
    void render(const int &posX, const int &posY) const;
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

    bool            isItKing() const;

    bool            isItBlack() const;

    bool            isItWhite() const;

private:
    //Attributes
    ChessPieceType  m_type;
    ChessPieceColor m_color;
    bool m_firstMove;
};

#endif /* Piece_hpp */
