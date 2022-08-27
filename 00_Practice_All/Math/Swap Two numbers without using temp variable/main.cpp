#include <iostream>

using namespace std;

void Swap(int &a, int &b)
{
    // Using Arithmetic operators
    // a = a + b; // 100
    // b = a - b; // 30
    // a = a - b; // 70

    // Using Bitwise Xor Operator
    a = a ^ b; // 8^4 = 1000 ^ 0100 = 1100 =>12
    b = a ^ b; // 12^4 = 1100 ^ 0100 = 1000 =>8
    a = a ^ b; // 12^8 = 1100 ^ 1000 = 0100 =>4
}

int main()
{
    int num1 = 8, num2 = -4;

    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    Swap(num1, num2);

    cout << endl;
    cout << "num1 = " << num1 << endl;
    cout << "num2 = " << num2 << endl;

    return 0;
}