#include <filesystem>
#include "DataManager.h"

void LoadGameData(GameData& gameData)
{
	std::string fileName = "TextAdventureGeneratorData.txt";

	std::ifstream file;

	std::filesystem::path path = std::filesystem::current_path();

	file.open(path.append("TextAdventureGeneratorData.txt"));

	if (!file) { std::cerr << "Error: Could not open file " << fileName << std::endl; return; }
	LoadGameDataItems("[ITEM LIST]", gameData.itemList, file);
}

void LoadGameDataItems(std::string tag, std::vector<std::string>& gameDataItems, std::ifstream& file)
{
	std::string line;
	int i = 0;
	while (std::getline(file, line))
	{
		
	}
}
