//
//  Piece.cpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#include "Piece.hpp"
#include <fstream>
#include <string>
#include <iostream>
using namespace std;

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
    //To be used as a bool condition in GetValidMoves.

    bool empty = false;

    if ((m_type == CPT_EMPTY) && (m_color == CPC_NONE))
        empty = true;

    return empty;
}

void Piece::render(const int& posX, const int& posY) const
{
	switch (m_type)
	{
	case CPT_King:
		if (m_color == CPC_Black)
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KING_BLACK, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
		
		else
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KING_WHITE, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H));
		break;

	case CPT_Queen:
		if (m_color == CPC_Black)
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_QUEEN_BLACK, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
		else
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_QUEEN_WHITE, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
		break;

	case CPT_Rook:
		if (m_color == CPC_Black)
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ROOK_BLACK, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
		else
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_ROOK_WHITE, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
        break;

	case CPT_Bishop:
		if (m_color == CPC_Black)
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BISHOP_BLACK, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
		else
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_BISHOP_WHITE, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
        break;

	case CPT_Knight:
		if (m_color == CPC_Black)
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KNIGHT_BLACK, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 

		else
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_KNIGHT_WHITE, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
        break;

	case CPT_Pawn:
		if (m_color == CPC_Black)
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PAWN_BLACK, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
		else
			GraphicManager::getInstance()->drawSprite(IMAGE_PIECE_PAWN_WHITE, CELL_INIT_X + (posX * CELL_W), CELL_INIT_Y + (posY * CELL_H)); 
       break;
		
	default: 
        break;
	}
}

bool Piece::isItKing() const
{
    bool k = false;

    if (m_type == CPT_King)
    {
        k = true;
    }

    return k;
}

bool Piece::isItBlack() const
{
    bool b = false;

    if (m_color == CPC_Black)
    {
        b = true;
    }

    return b;
}

bool Piece::isItWhite() const
{
    bool w = false;

    if (m_color == CPC_White)
    {
        w = true;
    }

    return w;
}
