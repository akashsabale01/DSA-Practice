#include <iostream>
using namespace std;

int getSum(int number)
{
    int sum = 0;
    while (number != 0)
    {
        int rem = number % 10;
        sum += rem;
        number = number / 10;
    }
    return sum;
}

int main()
{
    int num = 645;

    int sum = getSum(num);
    cout << sum;

    return 0;
}