/*
    Simple Interest = (p*r*t)/100

    Compound Interest:
        A = p * (1 + (r / 100))^ t
        Compound Interest = A - p

    A	=	final amount
    P	=	initial principal balance
    r	=	interest rate
    n	=	number of times interest applied per time period
    t	=	number of time periods elapsed


*/

#include <iostream>
#include <math.h>

using namespace std;

int main()
{

    // float p, r, t, A, compoundInterest;
    // p = 15000, r = 5, t = 2;

    // A = p * pow((1 + (r / 100)), t);

    // compoundInterest = A - p;

    // cout << "Compound Interest = " << compoundInterest << endl;

    float p = 1000, r = 5, t = 2;

    float simpleInterest = (p * r * t) / 100;

    cout << "simple Interest = " << simpleInterest << endl;

    return 0;
}