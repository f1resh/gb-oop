#pragma once
#include <iostream>
#include <stdexcept>
using namespace std;

#define STACK_SIZE 10


class Stack
{
private:
    int array[10];
    size_t length = 0;
public:
    void reset(){
        length = 0;
        for (int i = 0; i<length; ++i){
            array[i]=0;
        }
    }
    bool push(int _value){
        if (length>=STACK_SIZE) return false;
        array[length++] = _value;
        return true;
    }
    int pop(){
        if (length==0) {
            cout << "Stack is empty!" << endl;
            return 0;
            //throw std::runtime_error("Error: stack is empty!"); -- Is this far more better, than return 0?
        }
        int result = array[length-1];
        array[length-1]=0;
        length--;
        return result;
    }
    void print(){
        cout << "(";
        for (int i = 0; i<length; i++){
            cout << " " << array[i];
        }
        cout << " )" << endl;
    }
};