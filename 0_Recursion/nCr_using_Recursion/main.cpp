/*
            n!
    nCr = --------
          r!(n-r)!

*/

#include <iostream>

using namespace std;

int fact(int n)
{
    if(n==0)
        return 1;

    return n * fact(n-1);
}

// Simple function for nCr
int nCr(int n, int r)
{
    int nume,deno;

    nume = fact(n);
    deno = fact(r) * fact(n-r);

    return nume / deno;
}

// Recursive function for nCr using Pascal Triangle
int NCR(int n, int r)
{
    if(n==r || r==0)
        return 1;

    return NCR(n-1, r-1) + NCR(n-1, r);
}

int main()
{
    cout << nCr(4,2) << endl;

    cout << NCR(4,2) << endl;

    return 0;
}
