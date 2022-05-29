/*
    Taylor's Series

    e^x = 1 + x/1 + x^2/2! + x^3/3! + ... + x^n/n!

    e(x,4) = 1 + x/1 + x^2/2! + x^3/3! + x^4/4!
    e(x,3) = 1 + x/1 + x^2/2! + x^3/3!
    e(x,2) = 1 + x/1 + x^2/2!
    e(x,1) = (p=p*x, p=p*1, 1+p/f)
    e(x,0) = 1

*/

#include <iostream>

using namespace std;

/**< Taylor's series */
/*  no of multiplications= O(n^2)  */
int e(int x, int n)
{
    static int p=1, f=1;
    int r=1;

    if(n==0)
        return 1;
    else
    {
        r = e(x, n-1);
        p = p * x;
        f = f * n;
        return r + p/f;
    }
}

/**< Taylor's series using Honor's rule  */
/* Taking terms common from equation, to reduce no of multiplications
   no of multiplications= O(n^2)
*/

//Recursive approach
int e_byHonorsRule(int x, int n)
{
    static int s = 1;

    if(n==0)
        return s;
    else
        s = 1 + x/n*s;

    return e_byHonorsRule(x, n-1);
}

// Iterative approach
int e_byHonorsRuleItr(int x, int n)
{
    int s = 1;

    while(n>0)
    {
        s = 1 + x/n*s;
        n--;
    }

    return s;
}

int main()
{
    cout << e(2,2) << endl; // e(2,2) = 1 + 2 + 2 = 5

    cout << e_byHonorsRule(2,2) << endl;

    cout << e_byHonorsRuleItr(2,2) << endl;

    return 0;
}
