#include "Inventory.h"

Inventory::Inventory()
{
	this->capacity = 5;
	this->nOfItems = 0;
	this->itemArr = new Item * [this->capacity];
	this->initialize();
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
	Item** tempArr = new Item*[this->capacity];

	for (int i(0); i < this->nOfItems; i++)
	{
		tempArr[i] = this->itemArr[i];
	}

	delete[] this->itemArr;

	this->itemArr = tempArr;

	this->initialize(this->nOfItems);

}

void Inventory::initialize(const int from)
{
	for (int i(from); i < this->capacity; i++)
	{
		this->itemArr[i] = nullptr;
	}
}

void Inventory::addItem(const Item& item)
{
	if (this->nOfItems >= this->capacity)
	{
		expand();
	}

	this->itemArr[this->nOfItems++] = item.clone(); 

}

void Inventory::removeItem(int index)
{

}

Inventory::Inventory(const Inventory& obj)
{
	this->capacity = obj.capacity;
	this->nOfItems = obj.nOfItems;
	this->itemArr = new Item * [this->capacity];

	for (int i(0); i < this->nOfItems; i++)
	{
		this->itemArr[i] = obj.itemArr[i]->clone();
	}
	initialize(this->nOfItems);
}


Item& Inventory::operator[](const int index)
{
	if (index < 0 || index >= this->nOfItems)
		throw("Bad Index!");

	return *this->itemArr[index];
}