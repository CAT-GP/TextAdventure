#pragma once
#include <vector>
#include <string>
#include <iostream>
#include <fstream>  

struct GameData
{
	std::vector<std::string> itemList;
	std::vector<std::string> inventory;
};

void LoadGameData(GameData& gameData);
void LoadGameDataItems(std::string tag, std::vector<std::string>& gameDataItems, std::ifstream& file);