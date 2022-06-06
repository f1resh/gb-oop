#include <iostream>
#include <string>

using namespace std;

bool IsInt(string v) {
    for (int i = 0; i < v.length(); i++)
        if (isdigit(v[i]) == false)
            return false;
    return true;
}

ostream& endll(ostream& out)
{
    out << "\r\n";
    out << "\r\n";
    out << flush;
    return out;
}

int main()
{
    //Task 1
    string input;
    int number;
   do {
        if (!IsInt(input) && !input.empty()) {
            cin.clear();
            cin.ignore(32767, '\n');
            cout << "Error! You entered not integer!" << endl;
        }
        cout << "Please enter integer: ";
        cin >> input;
    } while (!IsInt(input) && !input.empty());

    number = stoi(input);
    cout << "You entered: " << number << endll;


    //Task 2
    cout << "Hello, this is new manipulator" << endll << "called endll" << endll;

    return 0;

}


