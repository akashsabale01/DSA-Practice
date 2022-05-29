#include <iostream>

using namespace std;

// Iterative method
int fib_iterative(int n)
{
    int t0=0 , t1=1, next_term;

    if(n<=1)
        return n;

    for(int i=2; i<=n; i++)
    {
        next_term = t0 + t1;
        t0 = t1;
        t1 = next_term;
    }

    return next_term;
}

// 1st method - fib using Recursion
int fibR(int n)
{
    if(n<=1)
        return n;

    else
        return fibR(n-2) + fibR(n-1);
}


// 2nd Method - fib using Recursion by Memoization

/*  storing result in temp array and using it when required,
    which avoids going again to that call
*/

int arr[20];

int fib_by_Memoization(int n)
{
    if(n<=1)
    {
        arr[n] = n;
        return n;
    }
    else
    {
        if(arr[n-2] == -1)
            arr[n-2] = fib_by_Memoization(n-2);

        if(arr[n-1] == -1)
            arr[n-1] == fib_by_Memoization(n-1);

        arr[n] = arr[n-2] + arr[n-1];
        return  arr[n];
    }
}

int main()
{
   /**
    *  Fibonacci Series = 0 1 1 2 3 5 8 13 21 34...
    *  f0 = 0, f1 = 1, f2= f0+f1 = 0+1 = 1
    *  f3 = f1+f2 = 1+2 =3
    *  i.e. f(n) = f(n-2) + f(n-1)
    */

    int n;
    cout<<"Enter n = ";
    cin>>n;

    for(int i=0; i<n+1; i++){
        arr[i] = -1;
    }

    cout<< n << "'th fibonacci number Iterative = " << fib_iterative(n);

    cout<< n << "'th fibonacci number = " << fibR(n);

    cout<< n << "'th fibonacci number = " << fib_by_Memoization(n);

    return 0;
}
