#pragma once
#include <stdlib.h>
#include <string>


class Enemy
{
private:
	int hp;
	int hpMax;
	int level;
	int damageMin;
	int damageMax;
	float dropChance;
	int defence;
	int accuracy;

public:
	Enemy(int level = 0);
	virtual ~Enemy();

	inline bool isAlive() { return this->hp > 0; }
	void takeDamage(int damage);
	std::string getAsString() const;

	inline int getDamage() const { return rand() % this->damageMax + this->damageMin;}
	inline int getExp() const { return this->level * 100; }
	inline int getHp() const { return this->hp; }
	inline int getHpMax() const { return this->hpMax; }
	inline int getLevel() const { return this->level; } 


};

