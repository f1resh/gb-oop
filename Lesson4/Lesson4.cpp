#include <iostream>
#include <vector>
#include <set>
#include <random>
#include <iomanip>
#include <array>
#include "ArrayInt.h"
#include "MySort.h"
using namespace std;

size_t GetNumberOfUnique(const vector<int>& vec) {
    if (vec.size() <= 1) return vec.size();
    int length = vec.size();

    int* array = new int[length]();
    for (size_t i = 0; i < length; i++)
    {
        array[i] = vec[i];
    }


    mySort::advancedQSort(array, 0, length-1);
    int counter = 1;

    for (size_t i = 0; i < length -1; i++)
    {
        if (array[i] != array[i + 1]) counter++;
    }

    return counter;
}

size_t GetNumberOfUnique_Set(const vector<int>& vec) {
    set<int> uniqSet(vec.begin(), vec.end());
    return uniqSet.size();
}


int main()
{
    //Task 1
    cout << "==================================================\nTask 1" << endl;
    ArrayInt A1;
    ArrayInt A2(10);

    A1.resize(6);
    for (size_t i = 0; i < A1.size(); i++)
    {
        A1[i] = i;
    }
    A1.print("A1");
    cout << A1.pop_back() << endl;
    A1.print("A1");
    cout << A1.pop_front() << endl;
    A1.print("A1");
    cout << A1.pop(2) << endl;
    A1.print("A1");
    
    for (size_t i = 0; i < A2.size(); i++)
    {
        A2[i] = rand() % 100;
    }
    A2.print("A2");
    A2.sort();
    A2.print("A2 sorted");

    //Task 2
    cout << "==================================================\nTask 2" << endl;
    srand(time(NULL));
    vector<int> Vector(1000000);
    cout << "Vector of size " <<Vector.size() << ": " << endl;
    for (auto &elem : Vector) {
        elem = rand() % 100000;
        //cout << elem << " ";
    }
    cout << endl;

    clock_t start, end;

    start = clock();
    ios_base::sync_with_stdio(false);
    cout << "My. Number of unique values is : " << GetNumberOfUnique(Vector) << endl;
    end = clock();
    double time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time of execution : " << fixed << time_taken << setprecision(5) << endl;

    start = clock();
    ios_base::sync_with_stdio(false);
    cout << "Set. Number of unique values is : " << GetNumberOfUnique_Set(Vector) << endl;
    end = clock();
    time_taken = double(end - start) / double(CLOCKS_PER_SEC);
    cout << "Time of execution : " << fixed << time_taken << setprecision(5) <<  endl;



    return 0;
}

