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
	Puzzle p("lel.txt");
	std::cout << p.getAsString() << "\n";
}

//Functions 

void Game::mainMenu()
{
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
	cout << endl;

	switch (choice)
	{
	case 0:
		playing = false;
		break;
	case 1:
		Travel();

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