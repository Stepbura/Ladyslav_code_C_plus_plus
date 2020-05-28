#include "Event.h"


Event::Event()
{
    this->nrOfEvents = 2;
}

Event::~Event()
{

}


void Event::generateEvent(Character& character)
{
    int i = rand() % this->nrOfEvents;
	switch (i)
	{
	case 0:
		//Enemy encounter
		enemyEncounter(character);
		break;
	case 1:
		//Puzzle
		puzzleEncounter(character);
		break;
	case 2:
		break;
	default:
		break;
	}
}

 //Different events
void Event::enemyEncounter(Character& character)
{

}

void Event::puzzleEncounter(Character& character)
{
	bool completed = false;
	int usertAns = 0;
	int chances = 3;

	Puzzle puzzle("D:\GIT\C-\Game_Shooter_C++\Puzzles\1.txt");

	while (!completed && chances > 0) 
	{
		chances--;
		puzzle.getAsString();

		std::cout << "\nYour ANSWER: " << std::endl;
		std::cin >> usertAns;
		std::cout << "\n";

		if (puzzle.getCorrectAns() == usertAns)
		{
			completed = true;
			//Give USER EXP ETC AND CONTINUE 
		}
	}
	if (completed)
	{
		std::cout << "Gongratz you succeded! \n";
	}
	else
	{
		std::cout << "You have failed, bro! \n";
	}
}
