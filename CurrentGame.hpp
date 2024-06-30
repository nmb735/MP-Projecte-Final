//
//  CurrentGame.hpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#ifndef CurrentGame_hpp
#define CurrentGame_hpp

#include <stdio.h>
#include <stdlib.h>
#include <string>
#include "GameInfo.h"
#include "Chessboard.hpp"
#include <queue>
#include <fstream>
#include "Piece.hpp"

using namespace std;

class Node
{
public:
    Node() : m_next(nullptr), m_prev(nullptr) {};
    ~Node() {};
    Node(const string& valor) : m_valor(valor), m_next(nullptr), m_prev() {}
    Node* getNext() { return m_next; }
    void setNext(Node* next) { m_next = next; }
    Node* getPrev() { return m_prev; }
    void setPrev(Node* prev) { m_prev = prev; }
    string getValor() { return m_valor; }
    void setValor(const string& valor) { m_valor = valor; }
private:
    string m_valor;
    Node* m_next;
    Node* m_prev;
};

class QueueMovements
{
public:
    void push(const string& move);
    void pop();
    string& front() const;
    string& back() const;
    bool empty() const;

private:
    Node* m_first;
    Node* m_last;
};

class CurrentGame {

public:
    CurrentGame();

    void            init(GameMode mode, const string& intitialBoardFile, const string& movementsFile);
    bool			updateAndRender(int mousePosX, int mousePosY, bool mouseStatus);
    void            end();
    void            fullRender();
    void            turnChange();
    void            update();
    void            reset();
    void            displayMovements(const int& posX, const int& posY);
    void            searchAndUpdate(const ChessPosition& movePos);
    void            obtainPositions(ChessPosition& orig, ChessPosition& dest, const string& currentMove);
    void            checkWin(const ChessPosition& movePos);
    void            updateQueue(ChessPosition dest);


private:
    Chessboard m_gameBoard;
    QueueMovements m_movements;
    bool m_turn; // blanques 0, negres 1
    GameMode m_gameMode; //0=replay, 1=normal
    string m_movementFileName;
    VecOfPositions m_printablePos;
    ChessPosition m_selectedPos;
    bool m_firstClick;
    bool m_win;
};

#endif /* CurrentGame_hpp */
