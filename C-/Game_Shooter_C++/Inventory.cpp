#include "Inventory.h"

Inventory::Inventory()
{
	this->capacity = 10;
	this->nOfItems = 0;
	this->itemArr = new Item * [this->capacity];
}


Inventory::~Inventory()
{
	for (int i(0); i < this->nOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] itemArr;
}


void Inventory::expand()
{
	this->capacity *= 2;
	Item** tempArr = new Item * [this->capacity];

	for (int i(0); i < this->nOfItems; i++)
	{
		tempArr[i] = new Item(*this->itemArr[i]);
	}

	for (int i(0); i < this->nOfItems; i++)
	{
		delete this->itemArr[i];
	}
	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->nOfItems);

}

void Inventory::initialize(const int from)
{
	for (int i(from); i < this->capacity; i++)
	{
		itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item& item)
{
	if (this->nOfItems >= this->capacity)
	{
		expand();
	}

	this->itemArr[this->nOfItems++] = new Item(item);

}

void Inventory::removeItem(int index)
{

}