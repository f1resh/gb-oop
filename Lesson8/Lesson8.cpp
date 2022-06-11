#include <iostream>
#include <exception>
#include "Ex.h"
#include "Robot.h"
using namespace std;

template<typename T,typename U>
auto div_my(T a, U b) {
    if (b == 0) throw "Division by Zero";
    return a / b;
}

int main()
{
    //Task 1
    try {
        cout << div_my(3, 5) << endl;
    }
    catch (const char* error_message) {
        cout << error_message << endl;
    }

    //Task 2
    Bar b(50);
    int n = -1;
    while (n != 0) {
        try {

            cout << "Enter n: ";
            cin >> n;
            if (cin.fail()) {
                n = -1;
                cin.clear();
                cin.ignore(32767, '\n');
                throw invalid_argument("This is not integer");
            }
            b.set(n);
        }
        catch (Ex& ex) {
            cout << ex.what() << endl;
        }
        catch (exception ex) {
            cout << ex.what() << endl;
        }
    }
    

    //Task 3
    try {
        Robot R(0, 0);
        string input = "";
        while (input != "quit") {
                cout << "Enter command (up,down,left,right): ";
                cin >> input;
                if (cin.fail()) {
                    cin.clear();
                    cin.ignore(32767, '\n');
                    throw invalid_argument("This is not correct input!");
                }
                R.move(input);
        }
    }
    catch (GameException& ex) {
        cout << ex.what() << endl;
    }
    catch (exception& ex) {
        cout << ex.what() << endl;
    }
}


