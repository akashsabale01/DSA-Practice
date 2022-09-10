#include <iostream>

using namespace std;

bool isValid(int num)
{
    int currSum = 0;
    while (num > 0)
    {
        int rem = num % 10; // taking digit one by one from last
        currSum += rem;     // Adding to currSum
        num = num / 10;
    }

    return (currSum % 2 == 0);
}

int madNumberCount(int n)
{
    int madNumCount = 0;
    for (int i = 2; i <= n; i++)
    {
        if (isValid(i))
            madNumCount++;
    }
    return madNumCount;
}

int main()
{
    int n = 30;

    int result = madNumberCount(n);

    cout << result << endl;

    return 0;
}