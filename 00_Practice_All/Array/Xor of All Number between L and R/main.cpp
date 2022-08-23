#include <iostream>

using namespace std;

// Time Complexity: O(1)
// Auxiliary Space: O(1)
int xorFromZero(int num)
{
    if (num % 4 == 0)
        return num;
    else if (num % 4 == 1)
        return 1;
    else if (num % 4 == 2)
        return num + 1;
    else
        return 0;
}

int xorOfRange(int left, int right)
{
    // It gives TLE for Large Numbers
    // int res = 0;
    // for (int i = left; i <= right; i++)
    //     res = res ^ i;
    // return res;

    // 2nd method
    // Range  xor of a,b = xor(b) ^ xor(a-1);
    // here xor(a-1) nullify first xor(a-1) from 0

    int ans = xorFromZero(right) ^ xorFromZero(left - 1);
    return ans;
}

int main()
{
    int l = 4, r = 8;

    int res = xorOfRange(l, r);

    cout << res << endl;

    return 0;
}