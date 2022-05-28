#pragma once

#define _USE_MATH_DEFINES
#include <cmath>
#include <iostream>

class Figure {
public:
    Figure() {};
    virtual float area() = 0;
};

class Parallelogram : public Figure{
protected:
    float a,b;
    float angle;
public:
    Parallelogram(float _a, float _b, float _angle) : a(_a), b(_b), angle(_angle) {}
    float area() {
        return a*b*sin(angle*M_PI/180);
    }
};

class Circle : public Figure{
private:
    float R;
public:
    Circle(float _R) : R(_R) {}
    float area(){
        return M_PI * R * R /2;
    }
};

class Rectangle : public Parallelogram{
public:
    Rectangle(float _a, float _b) : Parallelogram(_a,_b,90) {}
};

class Square : public Parallelogram{
    
public:
    Square(float _a) : Parallelogram(_a,_a,90) {}
};

class Rhombus : public Parallelogram{
public:
    Rhombus(float _a, float _angle) : Parallelogram(_a,_a,_angle) {}
};