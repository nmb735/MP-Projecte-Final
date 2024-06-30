//
//  CurrentGame.cpp
//  LearnChess
//
//  Created by Enric Vergara on 21/2/22.
//

#include "CurrentGame.hpp"
#include "GameInfo.h"
#include "../GraphicManager.h"


CurrentGame::CurrentGame()
{

}


void CurrentGame::init(GameMode mode, const string& intitialBoardFile, const string& movementsFile)
{
}


void CurrentGame::end()
{

}

bool CurrentGame::updateAndRender(int mousePosX, int mousePosY, bool mouseStatus) 
{
    //TODO 1: Interactuar amb la crida per dibuixar gr�fics (sprites).
    // 	      Dibuixar a pantalla el gr�fic amb el tauler buit.
    //--------------------------------------------------------------

    //TODO 1.1 Afegir l'include de GraphicManager --> #include "../GraphicManager.h"
    //TODO 1.2 Fer la crida de dibuixar un sprite --> GraphicManager::getInstance()->drawSprite(image, posX, posY);
    //	    Per comen�ar podem cridar el drawSprite amb els params --> (IMAGE_BOARD,0,0)




    //TODO 1.3: Dibuixar a pantalla el gr�fic amb el tauler i un pe� blanc a la posici� (0,0) de la pantalla
 


    //TODO 1.3: Dibuixar a pantalla el gr�fic amb el tauler i un pe� blanc a la casella (0,0) del tauler
 



    //TODO 1.4: Dibuixar a pantalla el gr�fic amb el tauler i un pe� blanc a la casella (posX, posY) del tauler
 
 




    //TODO 2: Interacci� amb el mouse
    //------------------------------------------
    // TODO 2.1: Dibuixar el pe� a sobre del tauler nom�s si estem pressionant el bot� esquerre del mouse
    //          Si no l'estem pressionant nom�s s'ha de dibuixar el tauler sense el pe�

 




    // TODO 2.2 Dibuixar el pe� a sobre del tauler nom�s si estem pressionant el bot� esquerre del mouse dins dels l�mits del tauler
    //          Si no l'estem pressionant o l'estem pressionant fora dels l�mits del tauler nom�s s'ha de dibuixar el tauler sense el pe�





    // TODO 2.3 Dibuixar el pe� a sobre del tauler nom�s si estem pressionant el bot� esquerre del mouse dins dels l�mits del tauler
    //          S'ha de dibuixar el pe� a la casella sobre la que estem clicant amb el ratol�
    //          Si no l'estem pressionant o l'estem pressionant fora dels l�mits del tauler nom�s s'ha de dibuixar el tauler sense el pe�
 





    //TODO 3: Imprimir text per pantalla
    //------------------------------------------
    // TODO 3.1: Imprimir les coordenades de la posici� actual del ratol� a sota del tauler







    //TODO 4: Mostrar l�estat inicial del joc amb totes les peces col�locades a la seva posici� inicial
    //------------------------------------------
 



    return false;

}

