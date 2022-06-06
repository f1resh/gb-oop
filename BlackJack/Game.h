#pragma once
#include "Deck.h"
#include "Players.h"

class Game
{
private:
	Deck deck;
	House house;
	std::vector<Player> players;
public:
	Game(const std::vector<string>& _playerNames);
	~Game();
	void play();
};

Game::Game(const std::vector<string>& _playerNames) {
	deck.Shuffle();
	for (const auto pName : _playerNames) {
		players.push_back(Player(pName));
	}
}

Game::~Game() {};

void Game::play()
{
	for (auto& player : this->players) {
		deck.Deal(player);
		deck.Deal(player);
		std::cout << player << std::endl;
	}
	
	deck.Deal(house);
	house.FlipFirstCard();
	std::cout << house << std::endl;

	for (auto& player : players) {
		deck.AdditionalCards(player);
	}

	house.FlipFirstCard();
	std::cout << house << std::endl;
	deck.AdditionalCards(house);
	
	if (house.IsBusted()) {
		for (auto& player : players) {
			if (!player.IsBusted()) player.Win();
		}
	}
	else {
		for (auto& player : players) {
			if (!player.IsBusted()) {
				if (player.GetTotal() > house.GetTotal()) player.Win();
				else if (player.GetTotal() < house.GetTotal()) player.Lose();
				else player.Push();
			}
		}
	}

}
