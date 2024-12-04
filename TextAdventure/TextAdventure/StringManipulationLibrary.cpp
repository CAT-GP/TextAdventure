#include "StringManipulationLibrary.h"

std::string Trim(const std::string& str)
{
	size_t first = str.find_first_not_of(" \t\n\r\f\v");
	size_t last = str.find_last_not_of(" \t\n\r\f\v");

	if (first == std::string::npos || last == std::string::npos)
	{
		return "";
	}

	return str.substr(first, last - first + 1);
}

void SplitString(const std::string& str, std::string& commandA, std::string& commandB)
{
	size_t spacePosition = str.find(' ');

	if (spacePosition != std::string::npos)
	{
		commandA = str.substr(0, spacePosition);
		commandB = str.substr(spacePosition + 1);
	}
	else
	{
		commandA = str;
		commandB = "";
	}
}

bool StringAreEqual(const std::string& strA, const std::string& strB)
{
	return strA == strB;
}
