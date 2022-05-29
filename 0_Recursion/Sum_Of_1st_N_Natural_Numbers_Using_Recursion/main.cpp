#include <iostream>

using namespace std;

// TC= O(N), SC= O(N)
int SumRecursive(int n)
{
    if(n==0)
        return 0;
    return SumRecursive(n-1) + n;
}

// TC= O(N), SC= O(1)
int SumIterative(int n)
{
    int sum = 0;
    for(int i=1; i<=n; i++)
        sum += i;
    return sum;
}

// TC= O(1), SC= O(1)
int SumByFormula(int n)
{
    return (n*(n+1))/2;
}

int main()
{
    cout<<"Sum of 1st 10 Natural numbers (Recursive) = "<< SumRecursive(10)<<endl;

    cout<<"Sum of 1st 10 Natural numbers (Iterative) = "<< SumIterative(10)<<endl;

    cout<<"Sum of 1st 10 Natural numbers (By Formula) = "<< SumByFormula(10)<<endl;

    return 0;
}
