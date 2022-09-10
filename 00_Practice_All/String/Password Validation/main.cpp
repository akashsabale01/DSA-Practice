#include <iostream>
#include <string>

using namespace std;

bool isDigit(char ch)
{
    return (ch >= '0' && ch <= '9');
}

bool isCapitalAlphabet(char ch)
{
    return (ch >= 'A' && ch <= 'Z');
}

bool isLowerAlpabet(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

// bool isSpecialChar(char ch)
// {
//     return (ch == '@' && ch <= '');
// }

bool checkPassword(string password, int n, int minLen)
{
    if (n < minLen)
        return false;

    if (password[0] == isDigit(password[0]))
        return false;

    int numCount = 0, capAlphaCount = 0, specialCount = 0;

    for (int i = 0; i < n; i++)
    {
        if (password[i] == '+' || password[i] == ' ')
            return false;

        if (isDigit(password[i]))
            numCount++;
        else if (isCapitalAlphabet(password[i]))
            capAlphaCount++;
        else if (!isCapitalAlphabet(password[i]) && !isLowerAlpabet(password[i]) && !isDigit(password[i]))
            specialCount++; // then it is special character - it is not alphabet & not digit
    }

    if (numCount > 0 && capAlphaCount > 0 && specialCount > 0)
        return true;
    else
        return false;
}

int main()
{
    // string password = "User@122";
    // int Size = password.size();
    // int minLen = 8;

    // string password = "aB1_72&";
    // int Size = password.size();
    // int minLen = 5;

    string password = "c281 pbY012";
    int Size = password.size();
    int minLen = 2;

    string result = (checkPassword(password, Size, minLen)) ? "Valid Password" : "Invalid Password";

    cout << result << endl;

    return 0;
}