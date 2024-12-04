#include <filesystem>
#include "DataManager.h"
#include "StringManipulationLibrary.h"

void LoadGameData(GameData& gameData)
{
	std::string fileName = "TextAdventureGeneratorData.txt";

	std::ifstream file;

	std::filesystem::path path = std::filesystem::current_path();

	file.open(path.append("TextAdventureGeneratorData.txt"));

	if (!file) { std::cerr << "Error: Could not open file " << fileName << std::endl; return; }

	LoadGameDataItems("[ITEM LIST]", gameData.itemList, file);
	LoadGameDataItems("[ENEMY]", gameData.enemyList, file);
}

void LoadGameDataItems(std::string tag, std::vector<std::string>& gameDataItems, std::ifstream& file)
{
	gameDataItems.clear();

	std::string line;

	bool insideTagSection = false;

	while (std::getline(file, line))
	{
		line = Trim(line);

		if (line.empty()) continue;

		if (line == tag)
		{
			insideTagSection = true;
			continue;
		}


		if (insideTagSection && line[0] == '[' && line.back() == ']') break;

		if (!insideTagSection) continue;

		gameDataItems.push_back(line);
	}

	file.seekg(0, std::ios::beg);

	for (std::string data : gameDataItems)
	{
		std::cout << data << std::endl;
	}

	std::cout << std::endl;
}
