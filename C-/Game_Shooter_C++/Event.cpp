#include "Event.h"


Event::Event()
{
    this->nrOfEvents = 2;
}

Event::~Event()
{

}


void Event::generateEvent(Character& character, dArr<Enemy>& enemies)
{
    int i = rand() % this->nrOfEvents;
	switch (i)
	{
	case 0:
		//Enemy encounter
		enemyEncounter(character, enemies);
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
void Event::enemyEncounter(Character& character, dArr<Enemy>& enemies)
{

	bool playerTurn = false;
	int choice = 0;

	//Coin toss for turn 
	int coinToss = rand() % 2 + 1;

	if (coinToss == 1)
	{
		playerTurn = true;
	}
	else
		playerTurn = false;

	//End conditions
	bool escape = false;
	bool playerDefeated = false;
	bool enemiesDefeated = false;

	//enemies 
	int nrOfEnemies = rand() % 5 + 1;

	for (size_t i = 0; i < nrOfEnemies; i++)
	{
		enemies.push(Enemy(character.getLevel()));
	}

	//Battle variables 
	int attackRoll = 0;
	int defendRoll = 0;
	int damage = 0;
	int gainExp = 0;


	while (!escape && !playerDefeated && !enemiesDefeated)
	{
		if (playerTurn && !playerDefeated)
		{
			//Menu
			//system("cls");
			cout << "= BATTLE MENU =" << "\n\n";

			cout << "0: Escape" << "\n";
			cout << "1: Attack" << "\n";
			cout << "2: Defend" << "\n";
			cout << "3: Use Item" << "\n";
			cout << "\n";
			cout << "Choice: ";

			cin >> choice;

			while (cin.fail() || choice >= 3 || choice < 0)
			{
				system("cls");
				cout << "Faulty input" << "\n";
				cin.clear();
				cin.ignore(100, '\n');
				cout << "= BATTLE MENU =" << "\n\n";

				cout << "0: Escape" << "\n";
				cout << "1: Attack" << "\n";
				cout << "2: Defend" << "\n";
				cout << "3: Use Item" << "\n";
				cout << "\n";
				cout << "Choice: ";
				cin >> choice;;
			}

			cin.ignore(100, '\n');
			cout << "\n";

			//Moves

			switch (choice)
			{
			case 0: //Escape
				escape = true;
				break;

			case 1: //Attack

				//Select enemy
				cout << "= Select Enemy" << "\n\n";

				for (size_t i = 0; i < enemies.size(); i++)
				{
					cout << i << ": " << "Level: " << enemies[i].getLevel() << "-" << "HP: " << enemies[i].getHp()
						<< "/" << enemies[i].getHpMax() << "\n";
				}

				cout << "\n";
				cout << "Choice: ";

				cin >> choice;

				while (cin.fail() || choice >= enemies.size() || choice < 0)
				{
					cout << "Faulty input" << "\n";
					cin.clear();
					cin.ignore(100, '\n');


					cout << "= Select Enemy" << "\n\n";
					cout << "Choice: ";
					cin >> choice;;
				}

				cin.ignore(100, '\n');
				cout << "\n";
				attackRoll = rand() % 100 + 1;

				if (attackRoll > 50) //Hit
				{
					cout << "HIT! " << "\n\n";
					damage = character.getDamage();
					enemies[choice].takeDamage(damage);

					cout << "Damage: " << damage << "!" << "\n\n";

					if (!enemies[choice].isAlive())
					{
						cout << "Enemy Defeated! " << "\n\n";
						gainExp = enemies[choice].getExp();
						character.gainExp(gainExp);
						cout << "EXP GAINED: " << gainExp << "\n\n";
						enemies.remove(choice);
					}
				}
				else //Miss
				{
					cout << "Miss!" << "\n\n";
				}
				
				break;

			case 2: //Defend

				break;

			case 3: //Item

				break;

			default:
				break;
			}

			//Leave turn
			playerTurn = false;
		}

		else if(!playerTurn && !escape && !enemiesDefeated)
		{
			//Enemy attack

			for (size_t i = 0; i < enemies.size(); i++)
			{

			}

			//End turn 
			playerTurn = true;
		}
			//Conditions


			if (!character.isAlive())
			{
				playerDefeated = true;
			}

			else if (enemies.size() <= 0)
			{
				enemiesDefeated = true;
			}
	}
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
