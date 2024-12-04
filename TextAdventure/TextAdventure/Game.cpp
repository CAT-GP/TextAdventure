#include <functional>
#include <iostream>
#include <map>
#include <string>

#include "CommandsLibrary.h"
#include "DataManager.h"
#include "Game.h"


Game::Game() {
    isRunning = true;
}

void Game::Awake()
{
    LoadGameData(GameData);
}

void Game::Start()
{
    std::function<void(const std::string)> InteractFunc = std::bind(&Game::Interact, this, std::placeholders::_1);
    ActionMap currentActionMap = SettingCommands(InteractFunc);

    OptionSelection(currentActionMap, commandA, commandB);
}

void Game::Update() 
{
    std::string w;
    if (isRunning)
    {
        std::cin >> w;
    }
}

void Game::Interact(const std::string& item)
{
    for(std::string gameItem : GameData.itemList)
    {
        if (StringAreEqual(gameItem, item))
        {
            std::cout << "Interacted with " << item << ". " << item << " added to inventory" << std::endl;
            GameData.inventory.push_back(item);
            return;
        }
    }
    
    std::cout << "There are no " << item << " in the room!" << std::endl;

}
