#pragma once
#include <stdlib.h>
#include "Puzzle.h"
#include "Character.h"
#include "dArr.h"

using namespace std;

class Event
{
private:
	int nrOfEvents;

public:
	Event();
	virtual ~Event();
	void generateEvent(Character& character, dArr<Enemy>& enemies);

	//Events
	void enemyEncounter(Character& character, dArr<Enemy>& enemies);
	void puzzleEncounter(Character& character);
};
