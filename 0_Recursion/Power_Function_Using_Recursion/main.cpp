/*
#Power function

 m^n = m*m*m*m*m..... for n times
 pow(m,n) = m*m*m*m*m..... for n times
 pow(m,n) = m*m*m*m*m.....*(n-1) times * m

 pow(m,n) = pow(m,n-1) * m

 Conditions:-

 pow(m,n) = 1                 --- if(n==0)
          = pow(m,n-1) * m    --- if(n>0)

*/

#include <iostream>

using namespace std;

int Power(int m, int n)
{
    if(n==0)
        return 1;

    return Power(m, n-1) * m ;
}

// Optimized
int Pow(int m, int n)
{
    if(n==0)
        return 1;

    else
    {
        if(n%2 == 0)
            return Pow(m*m, n/2);
        else
            return m * Pow(m*m, (n-1)/2);
    }
}

int main()
{
    cout << "Power of 3 for 2 = "<< Power(3,2) << endl;

    cout << "Power of 3 for 2 _Optimized = "<< Pow(3,2) << endl;

    return 0;
}
