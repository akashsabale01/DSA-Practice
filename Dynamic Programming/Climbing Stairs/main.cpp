/*

You are climbing a staircase. It takes n steps to reach the top.

Each time you can either climb 1 or 2 steps. In how many distinct ways can you climb to the top?

Input: n = 3
Output: 3
Explanation: There are three ways to climb to the top.
1. 1 step + 1 step + 1 step
2. 1 step + 2 steps
3. 2 steps + 1 step


I understood this as : to reach the nth stair, you find out the ways to reach the (n-1)th stair (from where you take 1 step to reach nth stair) and the ways to reach the (n-2)th stair (from where you take 2 steps to reach the nth stair), and sum them to get total no. of ways.

*/

#include <iostream>
#include <vector>

using namespace std;

// Function to count number of ways to reach the nth stair.

/*  Its Fibonacci series that starts with 1 & 2 */

// Approach 1 - Recursive
int countWays(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1 || n == 2) // Fibonacci series that starts with 1 & 2
        return n;

    return countWays(n - 1) + countWays(n - 2);
}

// Approach 2 - Top Down dp - Memoization + Recursion
int countWaysByDP(int n, vector<int> &dp) // helper function for countWays
{
    if (n <= 0)
        return 0;

    if (n == 1 || n == 2)
        return n;

    // Check if already calculated or not
    if (dp[n] != -1)
        return dp[n];

    return dp[n] = countWaysByDP(n - 1, dp) + countWaysByDP(n - 2, dp);
}
int countWays(int n)
{
    vector<int> dp(n + 1, -1);
    int res = countWaysByDP(n, dp); // helper function for using dp array
    return res;
}

// Approach 3 - Bottom up dp - Tabulation + loop
int countWays(int n)
{
    if (n <= 0)
        return 0;

    if (n == 1 || n == 2)
        return n;
    vector<int> dp(n + 1, -1);

    dp[0] = 1;
    dp[1] = 2;

    for (int i = 3; i <= n; i++)
    {
        dp[i] = dp[i - 1] + dp[i - 2];
    }
    return dp[n];
}

// Approach 4 - Space optimized Dp - i.e. Using Iterative

// int countWays(int n)
// {
//     if (n <= 0)
//         return 0;

//     if (n == 1 || n == 2)
//         return n;

//     int prev2 = 1, prev1 = 2, curr = 0;

//     for (int i = 3; i <= n; i++)
//     {
//         curr = (prev2 + prev1);
//         prev2 = prev1;
//         prev1 = curr;
//     }

//     return curr;
// }

int main()
{
    int n = 4;
    cout << countWays(n) << endl;

    return 0;
}

// https://www.youtube.com/watch?v=RrFg9SZ8VoM

// https://www.youtube.com/watch?v=mLfjzJsN8us&list=PLgUwDviBIf0qUlt5H_kiKYaNSqJ81PMMY&index=3

// https://leetcode.com/problems/climbing-stairs/discuss/25299/Basically-it's-a-fibonacci.

// https://www.geeksforgeeks.org/find-all-combinations-that-adds-upto-given-number-2/