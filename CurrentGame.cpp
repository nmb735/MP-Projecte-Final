//
//  CurrentGame.cpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#include "CurrentGame.hpp"
#include "GameInfo.h"
#include "../GraphicManager.h"
#include <fstream>
#include "Piece.hpp"
#include <cstring>


using namespace std;

const int TEXT_POS_X = 62;

const int TEXT_POS_Y = 626;

const int SIZE = 5;

/*QueueMovements::QueueMovements()
{
    m_first = nullptr;
    m_last = nullptr;
}

QueueMovements::~QueueMovements()
{
    while (m_first != nullptr)
        pop();
}*/

bool QueueMovements::empty() const
{
    return (m_first == nullptr);
}

string& QueueMovements::front() const
{
    string s = m_first->getValor();
    return s;
}

string& QueueMovements::back() const
{
    string s = m_last->getValor();
    return s;
}

void QueueMovements::push(const string& move)
{
    Node* aux = new Node;

    if (aux != nullptr)
    {
        aux->setValor(move);

        if (m_first == nullptr)
        {
            aux->setPrev(nullptr);
            aux->setNext(nullptr);
            m_first = aux;
        }
        else
        {
            if (m_last == nullptr)
            {
                aux->setPrev(m_first);
                aux->setNext(nullptr);
                m_last = aux;

            }
            else
            {
                m_last->setNext(aux);
                m_last = aux;
                m_last->setNext(nullptr);
            }
        }
    }
}

void QueueMovements::pop()
{
    Node* prev = nullptr;
    Node* next = nullptr;
    Node* aux = nullptr;

    if (m_first != nullptr)
    {
        aux = m_first->getNext();
        next = aux->getNext();
        delete m_first;
        m_first = aux;
        m_first->setNext(next);
        m_first->setPrev(prev);
    }
}

CurrentGame::CurrentGame()
{
    m_turn = 0;
    m_win = false;
}

void CurrentGame::init(GameMode mode, const string& intitialBoardFile, const string& movementsFile)
{
    m_gameMode = mode;
    m_gameBoard.LoadBoardFromFile(intitialBoardFile);
    m_movementFileName = movementsFile;
    m_firstClick = false;
    m_win = false;

    if (mode == GM_REPLAY)
    {
        ifstream file;

        file.open(m_movementFileName);
        if (file.is_open())
        {
            do
            {
                string movement;
                file >> movement;
                m_movements.push(movement);
            } while (!(file.eof()));

            string movement;

            file >> movement;

            while (!file.eof());
           
            file.close();
        }

    }

    else
    {
        if (!(m_movements.empty()))
        {
            while (!(m_movements.empty()))
            {
                m_movements.pop();
            }
        }
    }

}

void CurrentGame::fullRender()
{
    if (m_win == false)
    {
        string msg1 = "Current Turn: White";
        if (m_turn == 1)
            msg1 = "Current Turn: Black";

        string msg2 = "Game Mode: Normal Play";
        if (m_gameMode == GM_REPLAY)
        {
            msg2 = "Game Mode: RePlay";
        }

        string msg = msg2.append(" ");
        msg2 = msg.append(1, '\n');
        msg = msg2 + msg1;
        GraphicManager::getInstance()->drawFont(FONT_RED_30, TEXT_POS_X, TEXT_POS_Y, 0.8, msg);

        m_gameBoard.render();

        if (m_printablePos.size() != 0)
        {
            for (int i = 0; i < m_printablePos.size(); i++)
                GraphicManager::getInstance()->drawSprite(IMAGE_VALID_POS, (GREEN_INIT_X + (m_printablePos[i].getPositionX() * CELL_W)), (GREEN_INIT_Y + (m_printablePos[i].getPositionY() * CELL_H)));
        }
    }
    else
    {
        m_gameBoard.render();
 
        if (m_turn == 0)
           GraphicManager::getInstance()->drawFont(FONT_RED_30, TEXT_POS_X, TEXT_POS_Y, 0.8, "GUANYA BLANC");
        else
           GraphicManager::getInstance()->drawFont(FONT_RED_30, TEXT_POS_X, TEXT_POS_Y, 0.8, "GUANYA NEGRE");


    }

}

void CurrentGame::end() 
{
    if (m_gameMode == GM_NORMAL)
    {
        ofstream mFile;

        mFile.open(m_movementFileName);

        if (mFile.is_open())
        {

            string move;

            while (!(m_movements.empty()))
            {
                move = m_movements.front();

                mFile << move;

                m_movements.pop();
            }

            mFile.close();
        }
    }
}

void CurrentGame::turnChange()
{
    if (m_turn == 1)
    {
        m_turn = 0;
    }

    else
    {
        m_turn = 1;
    }
}

void CurrentGame::update()
{
    // update m_movements;
    turnChange();
    m_printablePos.resize(0);
    m_firstClick = false;
    m_selectedPos = m_gameBoard.emptyPos();
}

void CurrentGame::reset()
{
    m_printablePos.resize(0);
    m_firstClick = false;
    m_selectedPos = m_gameBoard.emptyPos();
}

void CurrentGame::displayMovements(const int &posX, const int &posY)
{
    m_selectedPos.setTot(posX, posY);
    m_printablePos = m_gameBoard.GetValidMoves(m_selectedPos);
}

void CurrentGame::searchAndUpdate(const ChessPosition &movePos)
{
    bool trobat = false;
    int j = 0;
    while ((!trobat) && (j < m_printablePos.size()))
    {
        if (m_printablePos[j] == movePos)
            trobat = true;
        else
            j++;
    }
    if (trobat)
    {
        checkWin(movePos);
        m_gameBoard.MovePiece(m_selectedPos, movePos);
        updateQueue(movePos);
        if(m_win == false)
            update();
    }
    else
    {
        reset();
    }
}

void CurrentGame::obtainPositions(ChessPosition& orig, ChessPosition& dest, const string &currentMove)
{
    char ca[5];
    strcpy(ca, currentMove.c_str());
    int aux;
    aux = orig.setWorkingColumn(ca[0]);
    orig.setPositionX(aux);
    aux = orig.setWorkingRow(orig.charToInt(ca[1]));
    orig.setPositionY(aux);

    aux = dest.setWorkingColumn(ca[3]);
    dest.setPositionX(aux);
    aux = dest.setWorkingRow(dest.charToInt(ca[4]));
    dest.setPositionY(aux);

}

void CurrentGame::updateQueue(ChessPosition dest)
{
    ChessPosition origin = m_selectedPos;
    int ox = origin.getPositionX();
    int oy = origin.getPositionY();
    string newMove = "";
    newMove.append(1, origin.setGraphicColumn(ox));
    newMove.append(1, origin.intToChar(origin.setGraphicRow(oy)));
    newMove.append(1, ' ');
    int dx = dest.getPositionX();
    int dy = dest.getPositionY();
    newMove.append(1, dest.setGraphicColumn(dx));
    newMove.append(1, dest.intToChar(dest.setGraphicRow(dy)));
    m_movements.push(newMove);
}

void CurrentGame::checkWin(const ChessPosition& movePos)
{
    int x = movePos.getPositionX();
    int y = movePos.getPositionY();
    bool win = m_gameBoard.isItKing(x, y);
    if (win)
        m_win = true;
}

bool CurrentGame::updateAndRender(int mousePosX, int mousePosY, bool mouseStatus)
{

    if (m_win == false)
    {
        if (m_gameMode == GM_NORMAL)
        {
            int posX, posY;

            fullRender();

            if (m_firstClick == true)
            {
                if ((mousePosX >= CELL_INIT_X) && (mousePosY >= CELL_INIT_Y) && (mousePosX <= (CELL_INIT_X + CELL_W * NUM_COLS)) && (mousePosY <= (CELL_INIT_Y + CELL_H * NUM_ROWS)))
                {
                    if (mouseStatus)
                    {
                        posX = (mousePosX - CELL_INIT_X) / CELL_W;
                        posY = (mousePosY - CELL_INIT_Y) / CELL_H;
                        ChessPosition movePos;
                        movePos.setTot(posX, posY);
                        ChessPieceColor c = m_gameBoard.GetPieceColorAtPos(movePos);
                        if (m_turn == 0)
                        {
                            if (c == CPC_White)
                            {
                                displayMovements(posX, posY);
                            }

                            else
                            {
                                searchAndUpdate(movePos);
                            }
                        }
                        else
                        {
                            if (c == CPC_Black)
                            {
                                displayMovements(posX, posY);
                            }

                            else
                            {
                                searchAndUpdate(movePos);
                            }
                        }

                    }
                }

            }

            else
            {
                if ((mousePosX >= CELL_INIT_X) && (mousePosY >= CELL_INIT_Y) && (mousePosX <= (CELL_INIT_X + CELL_W * NUM_COLS)) && (mousePosY <= (CELL_INIT_Y + CELL_H * NUM_ROWS)))
                {
                    if (mouseStatus)
                    {
                        m_firstClick = true;
                        posX = (mousePosX - CELL_INIT_X) / CELL_W;
                        posY = (mousePosY - CELL_INIT_Y) / CELL_H;
                        ChessPosition aux;
                        aux.setTot(posX, posY);
                        ChessPieceColor c = m_gameBoard.GetPieceColorAtPos(aux);
                        if (m_turn == 0)
                        {
                            if (c == CPC_White)
                                displayMovements(posX, posY);
                        }
                        else
                        {
                            if (c == CPC_Black)
                                displayMovements(posX, posY);
                        }
                    }

                }
            }
        }

        else
        {
            if ((mousePosX >= CELL_INIT_X) && (mousePosY >= CELL_INIT_Y) && (mousePosX <= (CELL_INIT_X + CELL_W * NUM_COLS)) && (mousePosY <= (CELL_INIT_Y + CELL_H * NUM_ROWS)))
            {
                if (mouseStatus)
                {
                    string currentMove;
                    currentMove = m_movements.front();
                    m_movements.pop();
                    ChessPosition orig;
                    ChessPosition dest;

                    obtainPositions(orig, dest, currentMove);

                    m_gameBoard.MovePiece(orig, dest);
                }
            }
        }
    }

    else
    {
        fullRender();
    }

    return m_win;
}

