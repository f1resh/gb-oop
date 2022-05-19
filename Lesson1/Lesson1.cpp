#include <iostream>
#include "Power.h"
#include "RGBA.h"
#include "Stack.h"

int main() {

	Power p1;
	p1.Calculate();

	Power p2;
	p2.Set(-4,5);
	p2.Calculate();

	p2.Set(3, -5);
	p2.Calculate();

	p2.Set(-3, -5);
	p2.Calculate();

	p2.Set(1.21, 4);
	p2.Calculate();

	RGBA r1;
	r1.print();

	RGBA r2(240,24);
	r2.print();


	Stack stack;
	stack.reset();
	stack.print();

	stack.push(3);
	stack.push(7);
	stack.push(5);
	stack.print();

	stack.pop();
	stack.print();

	stack.pop();
	stack.pop();
	stack.print();
	stack.pop();
	return 0;
}
