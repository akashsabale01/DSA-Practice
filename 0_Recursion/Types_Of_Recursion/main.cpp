/*
Types of Recursion:-
1. Head
2. Tail
3. Tree
*/

#include <iostream>

using namespace std;


void TailRecursion(int n)
{
    // Base Case
    if(n<1)
        return;
    // Every operation performed on at Calling Phase,
    // i.e. call is after operations in function
    cout<< n <<" ";
    TailRecursion(n-1);
}

void HeadRecursion(int n)
{
    // Base Case
    if(n<1)
        return;
    HeadRecursion(n-1);
    // Every operation performed on at Retruning Phase,
    // i.e. call is before operations in function
    cout<< n <<" ";
}

// Tree Recursion to get n'th Fibonacci number of fibonacci series
int Fib(int n)
{
    // Base Case
    if(n<=1)
        return n;

    // here function call itself more than one time
    return Fib(n-2) + Fib(n-1);
}

int main()
{
    cout << "Tail Recursion: ";
    TailRecursion(5);

    cout <<endl<< "Head Recursion: ";
    HeadRecursion(5);

    cout <<endl<< "Tree Recursion to get n'th Fibonacci number : "<< Fib(5);

    return 0;
}
