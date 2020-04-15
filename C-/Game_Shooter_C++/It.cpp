#include "Item.h"


Item::Item(std::string name = "NONE", int level = 0, int buyValue = 0, int sellValue = 0, int rarity = 0)
{
	this->name = name;
	this->buyValue = buyValue;
	this->sellValue = sellValue;
	this->level = level;
	this->rarity = rarity;

}



Item::~Item()
{

}