#include <iostream>
#include "Date.h"
#include <memory>
using namespace std;

//for raw pointers
Date* laterDate(Date* date1,Date* date2) {
    if (date1->getYear() > date2->getYear()) return date1;
    if (date2->getYear() > date1->getYear()) return date2;
    if (date1->getMonth() > date2->getMonth()) return date1;
    if (date2->getMonth() > date1->getMonth()) return date2;
    if (date1->getDay() > date2->getDay()) return date1;
    if (date2->getDay() > date1->getDay()) return date2;
    return date1;
}

//for shared smart pointers
shared_ptr<Date> laterDate(shared_ptr<Date> date1, shared_ptr<Date> date2) {
    if (date1->getYear() > date2->getYear()) return date1;
    if (date2->getYear() > date1->getYear()) return date2;
    if (date1->getMonth() > date2->getMonth()) return date1;
    if (date2->getMonth() > date1->getMonth()) return date2;
    if (date1->getDay() > date2->getDay()) return date1;
    if (date2->getDay() > date1->getDay()) return date2;
    return date1;
}

void swapDate(shared_ptr<Date>& date1, shared_ptr<Date>& date2) {
    shared_ptr<Date> tmp = move(date1);
    date1 = move(date2);
    date2 = move(tmp);
}

int main()
{
    //Task1
    unique_ptr<Date> today(new Date(5, 6, 2022));
    unique_ptr<Date> date;
    cout << "today(class methods): " <<  today->getDay() << " " << today->getMonthName() << " " << today->getYear() << endl;
    cout << "today(overloaded operator): " << * today;
    cout << "today address: " << today.get() << endl;
    cout << "date address: " << date.get() << endl << endl;
    date = move(today);
    cout << "After moving today->date" << endl;
    cout << "today address: " << today.get() << endl;
    cout << "date address: " << date.get() << endl;


    //Task2
    cout << endl << endl << "Task 2" << endl;
    //today = new Date(6, 6, 2022);
    shared_ptr<Date> sptr1(new Date(3, 6, 2023));
    shared_ptr<Date> sptr2(new Date(5, 6, 2022));

    Date* ptr1 = sptr1.get();
    Date* ptr2 = sptr2.get();

    shared_ptr<Date> sptr3 = laterDate(sptr1, sptr2);
    Date* ptr4 = laterDate(ptr1, ptr2);

    cout << *sptr3 << " " << sptr3.use_count() << " times used" << endl;;
    cout << *ptr4 << endl;

    cout << endl << "Swap pointers!" << endl;

    cout << "shared pointer 1: " << * sptr1 << endl;
    cout << "shared pointer 2: " << *sptr2 << endl;
    swapDate(sptr1, sptr2);
    cout << "SWAP!" << endl;
    cout << "shared pointer 1: " << *sptr1 << endl;
    cout << "shared pointer 2: " << *sptr2 << endl;
}
