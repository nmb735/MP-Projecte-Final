#include <iostream>
#include "ChessPosition.hpp"
#include "Piece.hpp"
#include "Chessboard.hpp"
#include <iostream>
#include <algorithm>
#include <sstream>
#include <fstream>

using namespace std;


int main()
{
	ChessPosition cp;

	string x = "b6";

	cp = ChessPosition(x); //Comprobamos constructor necesario para Caronte

	cout << "Column: " << cp.getPositionX() << endl;
	cout << "Row: " << cp.getPositionY() << endl;

	cp.setTot(3, 5); //Comporobamos "setTot"

	cout << "Column: " << cp.setGraphicColumn(cp.getPositionX()) << endl;
	cout << "Row: " << cp.setGraphicRow(cp.getPositionY()) << endl; 
	//Comprobamos resto de funciones ChessPosition

	ChessPosition cp3;

	cp3.setTot(3, 5);

	//Comprobamos sobrecarga escritura
	cout << "Position 1:" << cp << endl;

	cout << "Position 2:" << cp3 << endl;

	//Comprobamos sobrecarga igualdad
	if (cp == cp3)
		cout << "TRUE" << endl;
	else
		cout << "FALSE" << endl;

	Piece bking, wknight, emp;

	bking = Piece(CPC_Black, CPT_King); //Comprobamos constructor necesario para Caronte

	wknight.setColor(CPC_White); //Comprobamos funciones

	wknight.setType(CPT_Knight);

	cout << "Piece 1:" << endl;
	cout << "		Color: " << bking.getPieceColor() << endl;
	cout << "		Type : " << bking.getPieceType() << endl;
	cout << "		Code : " << bking.pieceToString() << endl;
	//Comprobamos funciones

	cout << "Piece 2:" << endl;
	cout << "		Color: " << wknight.getPieceColor() << endl;
	cout << "		Type : " << wknight.getPieceType() << endl;
	cout << "		Code : " << wknight.pieceToString() << endl;
	//Comprobamos funciones

	cout << "Piece 3:" << endl;
	cout << "		Color: " << emp.getPieceColor() << endl;
	cout << "		Type : " << emp.getPieceType() << endl;
	cout << "		Code : " << emp.pieceToString() << endl;
	//Comprobamos funciones

	Chessboard gameboard1, gameboard2, gameboard3; 

	gameboard1.LoadBoardFromFile("tauler_1.txt"); //Comprobamos funciones

	gameboard2.LoadBoardFromFile("tauler_2.txt"); //Comprobamos funciones

	gameboard3.LoadBoardFromFile("tauler_3.txt"); //Comprobamos funciones

	string s1 = gameboard1.ToString(); //Comprobamos funciones

	string s2 = gameboard2.ToString(); //Comprobamos funciones

	string s3 = gameboard3.ToString(); //Comprobamos funciones

	cout << "Board 1:" << endl; //Comprobamos funciones
	cout << s1 << endl;
	cout << endl;


	cout << "Board 2:" << endl; //Comprobamos funciones
	cout << s2 << endl;
	cout << endl;

	cout << "Board 3:" << endl; //Comprobamos funciones
	cout << s3 << endl;
	cout << endl;

	Chessboard gameboard4;

	string s4 = gameboard4.ToString(); //Comprobamos funciones

	cout << "Board 4:" << endl;
	cout << s4 << endl;
	cout << endl;

	gameboard4.setPiece(5, 5, bking); //Comprobamos funciones: Añadimos pieza (Un Rey Negro) a la posicion 5,5 de un tablero vacio.

	string s5 = gameboard4.ToString(); 

	cout << "Board 5:" << endl;
	cout << s5 << endl;
	cout << endl; //Imprimimos el tablero.

	ChessPosition pos = ChessPosition(5, 5); //Declaramos la posicion de la pieza del Rey Negro.

	ChessPieceColor c = gameboard4.GetPieceColorAtPos(pos); //Comprobamos funcion para el Caronte.

	ChessPieceType t = gameboard4.GetPieceTypeAtPos(pos); //Comprobamos funcion para el Caronte.

	cout << "Color: " << c << endl; 

	cout << "Type: " << t << endl;

	VecOfPositions v = gameboard4.GetValidMoves(pos); //Comprobamos funcion "Get Valid Moves" --> NO FUNCIONA

	int n = v.size();

	for (int i = 0; i < n; i++)
		cout << v[i] << endl; //Imprimimos --> NO FUNCIONA

	return 0;
}
