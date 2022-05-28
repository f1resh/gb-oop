#include <iostream>
#include "Figure.h"
#include "Car.h"
#include "Fraction.h"
#include "Card.h"
using namespace std;


int main() {
	//================================================
	cout << "===============================================\nFigures" << endl;
	Parallelogram par(1, -2, 30);
	cout << "Parallelogram area = " << par.area() << endl;

	Rectangle rec(4, 5);
	cout << "Rectangle area = " << rec.area() << endl;

	Square sq(4.54f);
	cout << "Square area = " << sq.area() << endl;

	Rhombus rhomb(5, 90);
	cout << "Rhombus area = " << rhomb.area() << endl;

	Circle circ(1);
	cout << "Circle area = " << circ.area() << endl;

	Figure* fig = new Circle(1);
	cout << fig->area() << endl;
	//=================================================
	cout << "===============================================\nCars" << endl;
	Minivan minvan("Ford", "Tx");
	Bus bus("MAN", "A");
	PassengerCar pasCar("BMW", "M5");
	Car car("Lada", "Kalina");

	//=================================================
	cout << "===============================================\nFraction" << endl;
	Fraction f1{ 1,3 };
	Fraction f2{-3, 5};
	Fraction f3 = f2;
	cout << f1 << " + " << f2 << " = " << (f1+f2) << endl;
	cout << f1 << " - " << f2 << " = " << (f1-f2) << endl;
	cout << f1 << " * " << f2 << " = " << (f1*f2) << endl;
	cout << f1 << " / " << f2 << " = " << (f1/f2) << endl;
	cout << boolalpha << f1 << ">" << f2 << " is " << (f1>f2) << endl;
	cout << boolalpha << f1 << "<" << f2 << " is " << (f1<f2) << endl;
	cout << boolalpha << f1 << "==" << f2 << " is " << (f1==f2) << endl;
	cout << boolalpha << f2 << "==" << f3 << " is " << (f2==f3) << endl;
	cout << boolalpha << f1 << "!=" << f2 << " is " << (f1!=f2) << endl;
	cout << boolalpha << f2 << "!=" << f3 << " is " << (f2!=f3) << endl;
	cout << boolalpha << f1 << "<=" << f2 << " is " << (f1<=f2) << endl;
	cout << boolalpha << f1 << ">=" << f2 << " is " << (f1>=f2) << endl;
	cout << boolalpha << f2 << "<=" << f3 << " is " << (f2<=f3) << endl;
	Fraction f4(6,18);
	cout << boolalpha << f1 << "==" << f4 << " is " << (f1==f4) << endl;
	Fraction f5(4,0);
	//==================================================
	cout << "===============================================\nCards" << endl;
	Card first(Suit::Clubs,Rank::Ace);
	Card second(Suit::Spades,Rank::Queen);
	Card third(Suit::Hearts,Rank::King,true);
	Card fourth(Suit::Diamonds,Rank::Seven);
	cout << "First card is Ace of Clubs. Value = "<< first.GetValue() << endl;
	cout << "Second card is Queen of Spades. Value = " << second.GetValue() << endl;
	cout << "Third card is King of Hearts. Value = " << third.GetValue() << endl;
	cout << "Fourth card is Sevend of Diamonds. Value = " << fourth.GetValue() << endl;

	return 0;
}
