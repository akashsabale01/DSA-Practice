/*
    Fibbonacci Series
    0 1 1 2 3 5 8 13 21

*/

#include <iostream>
#include <vector>

using namespace std;

// TC = O(2^N) SC= O(N)
int fibSimple(int n)
{
    if (n <= 1)
        return n;

    else
        return fibSimple(n - 1) + fibSimple(n - 2);
}

// Using Dp Concept - Memoization ,
// Top Down Approach - It uses recursion
// TC = O(N), SC= O(N + N) for array & Recursion Stack space
// int fib(int n, vector<int> &dp)
// {
//     if (n <= 1)
//         return n;

//     // Check before calling if this subproblem is solved
//     if (dp[n] != -1)
//         return dp[n];

//     else
//         return dp[n] = fib(n - 1, dp) + fib(n - 2, dp); // storing result in dp array
// }

// Using Dp Concept - Tabulation,
// Bottom Up Approach i.e. start from base case  - It uses loops
// TC = O(N), SC= O(N) for array
int fib(int n, vector<int> &dp)
{
    if (n <= 1)
        return n;

    // Base case => asssignment
    dp[0] = 0, dp[1] = 1;

    // Bottom up dp
    for (int i = 2; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }

    return dp[n];
}

// Space Optimization
// TC = O(N), SC= O(1)
int fib(int n)
{
    if (n <= 1)
        return n;

    int prev2 = 0, prev1 = 1, curr = 0;

    for (int i = 2; i <= n; i++)
    {
        curr = prev1 + prev2;
        prev1 = curr;
        prev2 = prev1;
    }

    return curr;
}

int main()
{

    int n = 4; // 0 based indexing

    // cout << fibSimple(n) << endl;

    vector<int> dp(n + 1, -1);

    cout << fib(n, dp) << endl;

    return 0;
}

/*
---> Use below when we can't modify given Fib function & can't declare dp array outside fun

    int fibNum(int n, vector<int> &dp)
    {
        if(n <= 1)  return n;

        if(dp[n] != -1)
            return dp[n];

        return dp[n] = fibNum(n-1, dp) + fibNum(n-2, dp);
    }

    int fib(int n) {

     // Fib by memoization

        vector<int> dp(n+1, -1);

        int res = fibNum(n, dp);

        return res;

    }


*/