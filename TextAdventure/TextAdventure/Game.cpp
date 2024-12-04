#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "CommandsLibrary.h"
#include "Game.h"

Game::Game() {
    isRunning = true;
}

void Game::Awake()
{

}

void Game::Start()
{
    std::function<void(const std::string)> InteractFunc = std::bind(&Game::Interact, this, std::placeholders::_1);
    ActionMap currentActionMap = SettingCommands(InteractFunc);

    OptionSelection(currentActionMap, commandA, commandB);

    if (isRunning) {
        std::cout << "Game Description...\n";
        system("pause");
    }
}

void Game::Update() {

    if (isRunning)
    {
        std::cout << "IsRunning\n";
    }
}

void Game::Interact(const std::string& Item)
{
    std::cout << "Interacting with " << Item << "!" << std::endl;
}
