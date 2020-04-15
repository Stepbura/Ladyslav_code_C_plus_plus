#pragma once

#include <string>
#include <iostream>
#include <iomanip>


class Item
{

public:
	Item(std::string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0);
	virtual ~Item();

	inline std::string debugPrint() const
	{
		return this->name;
	};
private:

	std::string name;
	int sellValue;
	int buyValue;
	int level;
	int rarity;
};
