#include <iostream>

#include "DataManager.h"
#include "Game.h"

int main(int argc, char* argv[]) {

    Game* currGame = new Game();

    currGame->Awake();
    /*currGame->Start();

    while (currGame->isRunning) {
        currGame->Update();
    }*/

    std::cout << "THE END";
    return 0;


}