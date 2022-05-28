#pragma once
#include <string>
#include <iostream>
using namespace std;

class Car {
protected:
    string company;
    string model;
public:
    Car(string _company, string _model) : company(_company), model(_model) {
        cout << "Car created. Model: " << model << ", Company: " << company << endl;
    }
    virtual ~Car() {}
};

class PassengerCar : virtual public Car{
public:
    PassengerCar(string _company, string _model) : Car(_company,_model) {
        cout << "PassengerCar created. Model: " << model << ", Company: " << company << endl;
    }
};

class Bus : virtual public Car{
public:
    Bus(string _company, string _model) : Car(_company,_model) {
        cout << "Bus created. Model: " << model << ", Company: " << company << endl;
    }
};

class Minivan : public PassengerCar, public Bus {
public:
    Minivan(string _company, string _model) : PassengerCar(_company,_model), Bus(_company,_model), Car(_company,_model) {
        cout << "Minivan created. Model: " << model << ", Company: " << company << endl;
    }
};

