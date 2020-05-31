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
	int gainExp = (chances * character.getLevel() * (rand() % 10 + 1)); 

	Puzzle puzzle("Puzzles/1.txt");


	while (!completed && chances > 0) 
	{
		std::cout << "Chances: " << chances << "\n\n";
		chances--;
		std::cout << puzzle.getAsString() << "\n";

		std::cout << "\nYour ANSWER: " << std::endl;
		std::cin >> usertAns;
		
		while (cin.fail())
		{
			cout << "Faulty input!" << "\n";
			cin.clear();
			cin.ignore(100, '\n');

			cout << "\nYour ANSWER";
			cin >> usertAns;
		}

		cin.ignore(100,'\n');
		cout << "\n";

		
		if (puzzle.getCorrectAns() == usertAns)
		{
			completed = true;
			character.gainExp(gainExp); 
			std::cout << "YOU GAINED " << gainExp << "EXP!" << "\n\n";
		}
	}
	if (completed)
	{
		std::cout << "Gongratz you succeded! \n \n";
	}
	else
	{
		std::cout << "You have failed, bro! \n \n";
	}
}
