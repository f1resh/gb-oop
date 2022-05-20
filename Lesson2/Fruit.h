#pragma once
#include <string>
using namespace std;

class Fruit {
protected:
	string m_name;
	string m_color;
public:
	Fruit(string _color) : m_color(_color){};
	string getName() {return m_name;}
	string getColor() {return m_color;}
};


class Apple : public Fruit
{
public:
	Apple(string _color = "green") : Fruit(_color) {
		m_name = "Apple";
	}
};

class Banana : public Fruit
{
public:
	Banana(string _color = "yellow") : Fruit(_color){
		m_name = "Banana";
	}
};

class GrannySmith : public Apple{
public:
	GrannySmith() : Apple()
	{
		m_name = "Granny Smith apple";
	}
	GrannySmith(string _color) : Apple(_color)
	{
		m_name = "Granny Smith apple";
	}
};
