#include <iostream>
#include "Fruit.h"
#include "Person.h"



int main() {
	cout << "Task 1\n--------------------------------------------" << endl;
	Student s1{"Anna",18,50,Gender::Female};
	Student *s2 = new Student("Ivan",20,65,Gender::Male,3);
	
	s1.printInfo();
	s2->printInfo();
	{
		Student s3(1);
		s3.printInfo();
		cout << "Number of students = " << s1.count << endl;
		delete s2;
		cout << "Number of students = " << s1.count << endl;
	}
	cout << "Number of students = " << Student::count << endl;

	cout << endl << "Task 2\n--------------------------------------------" << endl;
	Apple a("red");
	Banana b;
	GrannySmith c;

	std::cout << "My " << a.getName() << " is " << a.getColor() << ".\n";
	std::cout << "My " << b.getName() << " is " << b.getColor() << ".\n";
	std::cout << "My " << c.getName() << " is " << c.getColor() << ".\n";
	return 0;
}
