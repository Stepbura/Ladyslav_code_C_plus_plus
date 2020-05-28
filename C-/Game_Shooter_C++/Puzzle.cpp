#include "Puzzle.h"


Puzzle::Puzzle(std::string fileName)
{

	this->correctAnswers = 0;	
	std::ifstream inFile(fileName);

	std::string answer = "";
	int nrOfAns = 0;
	int correctAns = 0;

	if (inFile.is_open())
	{
		std::getline(inFile, this->question);
		inFile >> nrOfAns;
		inFile.ignore();

		for (size_t i = 0; i < nrOfAns; i++)
		{
			std::getline(inFile, answer);
			this->answers.push_back(answer);
		}

		inFile >> correctAns;
		this->correctAnswers = correctAns;
		inFile.ignore();

	}
	else
		throw("Could not open puzzle!");

	inFile.close();
}

Puzzle::~Puzzle()
{

}

std::string Puzzle::getAsString()
{
	std::string answers = "";

	for (rsize_t i = 0; i < this->answers.size(); i++)
	{
		answers += std::to_string(i) + ": " + this->answers[i] + "\n";
	}

	
	//return this->question + "\n" + "\n" + this->answers + "\n";

	return this->question + "\n" + "\n" + answers + "\n" + std::to_string(this->correctAnswers) + "\n";
}
