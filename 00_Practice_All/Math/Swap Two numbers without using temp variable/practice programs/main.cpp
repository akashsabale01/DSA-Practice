#include <iostream>

using namespace std;

bool isPalindrome(int num)
{
    int revNum = 0; // 2
    int remainder = 0, originalNum = num;

    while (num != 0)
    {
        remainder = num % 10;             // 2, 1, 2
        revNum = revNum * 10 + remainder; // 2, 21, 212
        num = num / 10;                   // 21, 2, 0
    }

    return (revNum == originalNum);
}

int oddSumUptoN(int n)
{
    if (n <= 0)
        return -1;

    int oddSum = 0;

    for (int i = 1; i <= n; i++)
    {
        if (i % 2 != 0)
            oddSum += i;
    }
    return oddSum;
    /*  till 10, 1+3+5+7+9 = 25 */
}

int main()
{
    // int num = 213;
    // string result = (isPalindrome(num)) ? "Yes" : "No";
    // cout << result << endl;

    int num = 10;

    int result = oddSumUptoN(num);
    cout << result << endl;

    return 0;
}