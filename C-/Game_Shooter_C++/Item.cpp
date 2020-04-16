#include "Item.h"


Item::Item(std::string name, int level, int buyValue, int sellValue, int rarity)
{
	this->name = name;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->rarity = rarity;
	this->level = level;
}



Item::~Item()
{
	
}