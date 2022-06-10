#pragma once
#include <iostream>
#include "Card.h"
#include "Hand.h"
#include "Players.h"
#include "Deck.h"
#include "Game.h"
using namespace std;

size_t getNumberOfPlayers() {
	size_t n = 0;
	while (n < 1 || n > 7) {
		std::cout << "Please, enter number of players (1-7): ";
		if (cin.fail()) {
			std::cin.clear();
			std::cin.ignore(32767, '\n');
			std::cout << std::endl << "Error! You entered not integer!" << std::endl;
		}
		std::cin >> n;
	}
	return n;
}

std::string getPlayerName(const size_t N) {
	std::string name;
	std::cout << "Please enter the name of the " << N << " player: ";
	std::cin >> name;
	return name;
}

bool continueGame() {
	cout << "One more play? (Y / N) : ";
	char response;
	cin >> response;
	return (response == 'y' || response == 'Y');
}
int main()
{
	size_t playerNumber = getNumberOfPlayers();
	vector<std::string> players(playerNumber);
	for (size_t i = 0; i < playerNumber; ++i) {
		players[i] = getPlayerName(i+1);
	}
	
	bool gameContinue = true;
	while (gameContinue) {
		Game* game = new Game(players);
		game->play();
		delete game;
		gameContinue = continueGame();
	}



	return 0;
}


