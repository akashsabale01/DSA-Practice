/*
Given a number N, find all prime numbers upto N ( N included )
Example:

if N = 7,

all primes till 7 = {2, 3, 5, 7}

Make sure the returned array is sorted.
*/
#include <iostream>
#include <vector>

using namespace std;

// Approach 1- Brute Force
// TC= O(n * sqrt(n), SC= O(n)

// bool isPrime(int num)
// {
//     if (num <= 1)
//         return false;

//     if (num == 2 || num == 3)
//         return true;

//     if (num % 2 == 0 || num % 3 == 0)
//         return false; // 2 is only even prime number

//     for (int i = 5; i * i <= num; i = i + 2)
//     {
//         if (num % i == 0)
//             return false;
//     }
//     return true;
// }

// void primeUptoN(int n)
// {
//     vector<int> res;

//     for (int i = 2; i <= n; i++)
//     {
//         if (isPrime(i))
//             res.push_back(i);
//     }

//     // Print
//     int sz = res.size();
//     for (int i = 0; i < sz; i++)
//         cout << res[i] << " ";
// }

// Approach 2- Sieve of Eratosthenes
TC= O(n * log(log(n)), SC= O(n)
void primeUptoN(int n)
{
    vector<bool> primeArr(n + 1);

    primeArr[0] = primeArr[1] = false;
    primeArr[2] = true; // only even prime

    for (int i = 3; i < n + 1; i += 2) // marking odd numbers as true
        primeArr[i] = true;

    for (int i = 3; i < n; i += 2)
    {
        if (primeArr[i] == true)
        {
            // if it is prime then mark its multiple as not prime
            for (int j = i * i; j < n; j += i) // note- here increment j=j+i;
                primeArr[j] = false;
        }
    }

    // print
    for (int i = 2; i < n + 1; i++)
    {
        if (primeArr[i] == true)
            cout << i << " ";
    }
}

int main()
{
    int n = 100;

    primeUptoN(n);

    return 0;
}
