#include <iostream>
#include "Pairs.h"
#include <string>
using namespace std;

int main()
{
	Pair1<int> p1(6, 9);
	cout << "Pair: " << p1.first() << ' ' << p1.second() << '\n';

	const Pair1<double> p2(3.4, 7.8);
	cout << "Pair: " << p2.first() << ' ' << p2.second() << '\n';

	Pair<int, double> t1(6, 7.8);
	cout << "Pair: " << t1.first() << ' ' << t1.second() << '\n';

	const Pair<double, int> t2(3.4, 5);
	cout << "Pair: " << t2.first() << ' ' << t2.second() << '\n';

	StringValuePair<int> svp("Amazing", 7);
	std::cout << "Pair: " << svp.first() << ' ' << svp.second() << '\n';

	return 0;

	return 0;
}

