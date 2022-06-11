#pragma once
#include <exception>
#include <string>
using namespace std;

#define DIMENSION 9

class GameException {
protected:
	int x;
	int y;
	string command;
public:
	GameException(int _x, int _y, string _command) : x(_x), y(_y), command(_command) {};
	virtual ~GameException() {};
	virtual const string what() = 0;
};

class OffTheField : public GameException {
public:
	using GameException::GameException;
	virtual const string what() {
		return "Off the field! Position is (" + to_string(x) + "," + to_string(y) + "). Entered command is " + command;
	}
};

class IllegalCommand : public GameException {
public:
	using GameException::GameException;	virtual const string what() {
		return "Illegal command! Position is (" + to_string(x) + "," + to_string(y) + "). Entered command is " + command;
	}
};

class Robot {
private:
	int x;
	int y;
	bool isOffField(int new_x, int new_y) {
		return (new_x < 0 || new_x > DIMENSION || new_y < 0 || new_y > DIMENSION);
	}
public:
	Robot(int _x = 0, int _y = 0) {
		if (isOffField(_x,_y)) throw invalid_argument("Initial position of robot is incorrect. X,Y coordinates should be in 0...9 range!");
		x = _x;
		y = _y;
	};
	void move(string command) {
		if (command != "up" && command != "down" && command != "left" && command != "right") throw IllegalCommand(x, y, command);
		if (command == "up") {
			if (isOffField(x, y + 1)) throw OffTheField(x, y, command);
			++y;
		}
		if (command == "down") {
			if (isOffField(x, y - 1)) throw OffTheField(x, y, command);
			--y;
		}
		if (command == "left") {
			if (isOffField(x-1, y)) throw OffTheField(x, y, command);
			--x;
		}
		if (command == "right") {
			if (isOffField(x+1, y)) throw OffTheField(x, y, command);
			++x;
		}
		cout << "Robot moved! New position is: (" << x << "," << y << ")." << endl;
	}

};


