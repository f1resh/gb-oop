#pragma once
#include <string>
using namespace std;

enum class Gender{
	Male ='m',
	Female = 'f',
	NotSet = '-'
};

class Person{
protected:
	string name;
	size_t age;
	float weight;
	Gender gender;
public:
	Person(string _name = "n/a", size_t _age = 0,float _weight = 0,Gender _gender = Gender::NotSet) : name(_name), age(_age), weight(_weight), gender(_gender) {};
	void setName(string _name){name = _name;}
	bool setAge(size_t _age)
	{
		if (_age <=0) return false; 
		age = _age;
		return true;
	}
	bool setWeight(float _weight)
	{
		if (_weight <=0) return false; 
		weight = _weight;
		return true;
	}
	bool setGender(Gender _gender)
	{
		gender = _gender;
		return true;
	}
};



class Student : public Person{
private:
	size_t year;
public:
	static size_t count;
	Student(string _name, size_t _age,float _weight,Gender _gender,size_t _year = 0) : Person(_name,_age,_weight,_gender), year(_year) {
		count++;
	};
	Student(size_t _year = 0) : Person(), year(_year){
		count++;
	};
	~Student(){
		count--;
	};
	bool setYear(size_t _year)
	{
		if (_year <=0 || _year > 6) return false; 
		year = _year;
		return true;
	}
	bool incYear()
	{
		if (year==6) return false;
		year++;
		return true;
	}
	void printInfo() const{
		cout << "Student name: " << name << endl <<
				"Age: " << age << endl <<
				"Gender: " << (char)gender << endl <<
				"Weight: " << weight << endl <<
				"Year: " << year << endl;
	}
};

size_t Student::count = 0;
