#include "Game.h"

Game::Game()
{
	this->choice = 0;
	this->playing = true;
	this->activeCharacter = 0;
	this->fileName = "characters.txt";
}

Game::~Game()
{

}

void Game::initGame()
{
	createNewCharacter();
}

//Functions 

void Game::mainMenu()
{
	cout << "ENTER to countinue... " << "\n";
	cin.get();
	system("cls");

	if (this->characters[activeCharacter].getExp() >= 
		this->characters[activeCharacter].getExpNext())
	{
		std::cout << "LEVEL UP AVAILABLE! \n\n";
	}

	std::cout << "= MAIN MENU" << std::endl << std::endl;
	cout << "0: Quit" << endl;
	cout << "1: Travel" << endl;
	cout << "2: Shop" << endl;
	cout << "3: Level up" << endl;
	cout << "4: Rest" << endl;
	cout << "5: Character sheet" << endl;
	cout << "6: Create new character" << endl;
	cout << "7: Save characters" << endl;
	cout << "8: Load characters" << endl;

	cout << endl;

	cout << endl << "Choice:  " << endl;
	cin >> choice;
	
	while (cin.fail())
	{
		cout << "Faulty input" << "\n";
		cin.clear();
		cin.ignore(100, '\n');

		cout << endl << "Choice: ";
		cin >> choice;;
	}

	cin.ignore(100, '\n');
	cout << endl;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	case 1:
		Travel();

		break;
	case 3:
		this->characters[activeCharacter].leveleUp();

		break; 

	case 5:
		characters[activeCharacter].printStats();
		break;

	case 6:
		cin.ignore();
		createNewCharacter();
		saveCharacters();

		break;
	case 7:
		saveCharacters();
		break;

	case 8:
		loadCharacters();
		break;

	default:
		break;

	}
}

void Game::createNewCharacter()
{
	std::string name; 
	cout << "Character name: ";
	std::getline(std::cin, name);

	characters.push_back(Character());
	activeCharacter = this->characters.size() - 1;
	this->characters[activeCharacter].initialize(name);
}

void Game::loadCharacters()
{
	ifstream inFile(fileName);

	//this->characters.clear();

	string name = "";
	int distanceTravelled = 0;
	int gold = 0;
	int	level = 0;
	int exp = 0;
	int strength = 0;
	int vitality = 0;
	int dexterity = 0;
	int intelligence = 0;
	int hp = 0;
	int stamina = 0;
	int statPoints = 0;
	int skillPoints = 0;

	string line = "";
	stringstream str;

	if (inFile.is_open())
	{
		while (getline(inFile,line))
		{
			str.str(line);
			str >> name;
			str >> distanceTravelled;
			str >> gold;
			str >> level;
			str >> exp;
			str >> strength;
			str >> vitality;
			str >> dexterity;
			str >> intelligence;
			str >> hp;
			str >> stamina;
			str >> statPoints;	
			str >> skillPoints;

			Character temp(name, distanceTravelled, gold, level,
				exp, strength, vitality, dexterity, intelligence, hp, stamina, statPoints, skillPoints);
			
			this->characters.push_back(Character(temp)); 

			cout << "Character " << name << " loaded!\n";
			str.clear();
		}
	}

	inFile.close();

	if (this->characters.size() <= 0)
	{
		throw " ERROR! NO CHARACTERS FOUND OR EMPTY FILE!";
	}
}

void Game::saveCharacters()
{
	ofstream outFile(fileName);

	if (outFile.is_open())
	{
		for (size_t i = 0; i < characters.size(); i++)
		{
			outFile << characters[i].getAsSrting() << "\n";
		}
	}

	outFile.close();
}


void Game::Travel()
{
	this->characters[activeCharacter].travel();
	Event ev;
	ev.generateEvent(this->characters[activeCharacter]); 
}