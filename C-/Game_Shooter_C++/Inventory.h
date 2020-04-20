#pragma once

#include "Armor.h"
#include "Weapon.h"

class Inventory
{
public:
	Inventory();
	~Inventory();
	Inventory(const Inventory& obj);
	inline int size()const { return this->nOfItems; };
	Item& operator[](const int index);

	void addItem(const Item& item);
	void removeItem(int index);
	inline void debugPrint()const
	{
		for (int i(0); i < this->nOfItems; i++)
		{
			std::cout << itemArr[i]->debugPrint() << std::endl;
		}
	}

private:
	void expand();
	void initialize(const int from = 0);
	int capacity;
	int nOfItems;
	Item** itemArr;
};
