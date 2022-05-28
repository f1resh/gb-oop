#pragma once
#include <iostream>
using namespace std;

class Fraction {
private:
    int numerator;
    int denumerator;
    int nod(int x, int y) {
        if (y == 0)
            return x;
        return nod(y, x % y);
    };
public:
    Fraction(int _numerator, int _denumerator) : numerator(_numerator), denumerator(_denumerator) {
        if (_denumerator==0){
            cout << "Denumerator can't bt 0" << endl;
            numerator = 0;
            denumerator = 0;
            //Throw exception?
        }
        if (_denumerator<0){
            numerator *= -1;
            denumerator = (-1) * _denumerator;
        }
    }
    void print(){
        cout <<  numerator << "/" << denumerator << endl;
    };


    friend ostream& operator<< (ostream& c_out, Fraction f);

    void reduction() {
        int _nod = abs(nod(numerator, denumerator));
        numerator /= _nod;
        denumerator /= _nod;
    }
    Fraction operator- () const{
        return Fraction(-1 * numerator,denumerator);
    };
    friend Fraction operator+ (const Fraction &f1, const Fraction &f2);
    friend Fraction operator- (const Fraction &f1, const Fraction &f2);
    friend Fraction operator* (const Fraction &f1, const Fraction &f2);
    friend Fraction operator/ (const Fraction &f1, const Fraction &f2);

    bool operator== (const Fraction &f) {
        Fraction f1(numerator,denumerator);
        Fraction f2(f.numerator, f.denumerator);
        f1.reduction();
        f2.reduction();
        return (f1.numerator == f2.numerator) && (f2.denumerator == f2.denumerator);
    }

    friend bool operator!= (Fraction& f1, Fraction& f2);

    bool operator> (const Fraction f2) {
        return (numerator * f2.denumerator) > (f2.numerator * denumerator);
    }
    bool operator< (const Fraction f2) {
        return (numerator * f2.denumerator) < (f2.numerator * denumerator);
    }
    friend bool operator>= (Fraction& f1,Fraction& f2);
    friend bool operator<= (Fraction& f1,Fraction& f2);

};

Fraction operator+(const Fraction &f1, const Fraction &f2)
{
    Fraction res(f1.numerator * f2.denumerator + f2.numerator * f1.denumerator, f1.denumerator*f2.denumerator);
    res.reduction();
    return res;
};

Fraction operator-(const Fraction &f1, const Fraction &f2)
{
    return ( - f2) + f1;
}

Fraction operator* (const Fraction& f1, const Fraction& f2) 
{
    Fraction res(f1.numerator * f2.numerator, f1.denumerator * f2.denumerator);
    res.reduction();
    return res;
}

Fraction operator/ (const Fraction& f1, const Fraction& f2)
{
    Fraction res(f1.numerator * f2.denumerator, f1.denumerator * f2.numerator);
    res.reduction();
    return res;
}
inline bool operator!=(Fraction& f1, Fraction& f2)
{
    return !(f1 == f2);
}

bool operator>= (Fraction& f1,Fraction& f2)
{
    return !(f1 < f2);
};


bool operator<= (Fraction& f1,Fraction& f2)
{
    return !(f1 > f2);
};

ostream& operator<< (ostream& c_out, Fraction f) 
{
   c_out << f.numerator << "/" << f.denumerator;
   return c_out;
};
