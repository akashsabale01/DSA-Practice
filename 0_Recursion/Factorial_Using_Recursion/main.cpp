/*
Factorial

    fact(5) = 5*4*3*2*1
    fact(5) = 5*fact(4)

    => fact(n) = n * fact(n-1)

    we know fact(0) = fact(1) = 1
    base condition = if(n<=1) return 1
*/

#include <iostream>

using namespace std;

int Factorial(int n)
{
    if(n==0 || n==1)
        return 1;

    return n * Factorial(n-1);
}

int main()
{
    cout<<"Factorial of 5 = "<<Factorial(5);

    return 0;
}
