#pragma once

#include"Item.h"

class Inventory
{
public:
	Inventory();
	virtual ~Inventory();

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
	void initialize(const int from);
	int capacity;
	int nOfItems;
	Item** itemArr;


};
