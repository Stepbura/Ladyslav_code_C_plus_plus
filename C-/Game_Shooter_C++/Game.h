
#pragma once
#include "Functions.h"
#include "Character.h"
#include <ctime>
#include <vector>
#include <fstream>
#include "Event.h"
#include <sstream>

using namespace std;

class Game
{
private:
	int choice;
	bool playing;

	//Character related
	int activeCharacter;
	std::vector<Character> characters;
	std::string fileName;

	//Enemies
	dArr<Enemy> enemies;

public:
	Game();
	virtual ~Game();

	//operators 

	//Functions
	void mainMenu();
	void Travel();
	void initGame();
	void levelUpCharacter();
	void createNewCharacter();
	void saveCharacters();
	void loadCharacters();
	void selectCharacter();

	//Accessors
	inline bool getPlaying() const { return  this->playing; }

	//Modifiers
};
