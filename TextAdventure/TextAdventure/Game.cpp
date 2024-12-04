#include <functional>
#include <iostream>
#include <algorithm>
#include <map>
#include <string>

#include "Game.h"
#include "StringManipulationLibrary.h"
#include "CommandsLibrary.h"

Game::Game() {
    isRunning = true;
}

void Game::Awake()
{
   InteractLinkFunction = std::bind(&Game::Interact, this, std::placeholders::_1);
}

void Game::Start()
{
    ActionMap actionMap = SettingCommands(InteractLinkFunction);
    OptionSelection(actionMap, commandA, commandB);

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

void Game::Interact(const std::string Item)
{
}
