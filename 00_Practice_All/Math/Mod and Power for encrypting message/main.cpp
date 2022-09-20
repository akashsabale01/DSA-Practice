#include <iostream>
#include <math.h>

// #define modby 1000000007; // 10^9+7

using namespace std;

int fastPower(int a, int b)
{
    if (b == 0)
        return 1;

    int subProb = fastPower(a, b / 2);
    int subProbSq = subProb * subProb;

    if (b & 1)
        return a * subProbSq;
    else
        return subProbSq;
}

// Not Working
int getMessage(int s, int n, int m)
{
    int modby = 1000000007;

    cout << s << " " << n << " " << m << endl;

    // int s_raised_to_n = pow(s, n);
    int s_raised_to_n = fastPower(s, n);

    cout << "s_raised_to_n " << s_raised_to_n << endl;

    int inner_term = (s_raised_to_n % 10);
    cout << "inner_term " << inner_term << endl;

    // int s_and_m = pow(inner_term, m);
    int s_and_m = fastPower(inner_term, m);
    cout << "s_and_m " << s_and_m << endl;

    int res = (s_and_m % modby);

    return res;
}

int main()
{
    // int S = 2, N = 3, M = 4;
    int S = 3, N = 1000000007, M = 4;

    int encryptMessage = getMessage(S, N, M);

    cout << "encryptMessage = " << encryptMessage << endl;

    return 0;
}

/*
https://www.faceprep.in/c/encrypt-the-code-using-two-key-values/
https://medium.com/@PlacementSeason/wipro-elite-national-level-test-coding-4923a2adfcd0
https://www.geeksforgeeks.org/modulo-1097-1000000007/
https://discuss.codechef.com/t/how-to-use-modulo-1000000007-in-question-where-you-have-to-use-pow-x-n-basically-power-of-number/47493
https://stackoverflow.com/questions/23016535/math-h-pow-giving-wrong-result


*/