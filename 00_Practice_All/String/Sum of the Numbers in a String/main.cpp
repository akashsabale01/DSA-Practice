/*

 Given a string, calculate the sum of numbers in a string (multiple consecutive digits are considered one number)

Example 1:
Input: string = “123xyz”
Output: 123

Example 2:
Input: string = “1xyz23”
Output: 24

*/

#include <iostream>
#include <string>

using namespace std;

int getSum(string str)
{
    string temp = "";
    int resSum = 0, n = str.size();

    for (int i = 0; i < n; i++)
    {
        if (str[i] >= '0' && str[i] <= '9')
            temp.push_back(str[i]);
        else if (temp != "") // only add when temp!=""
        {
            resSum += stoi(temp);
            temp = "";
        }
    }

    // if Last digit is Number then add to resSum
    if (str[n - 1] >= '0' && str[n - 1] <= '9')
        resSum += stoi(temp);

    return resSum;
}

int main()
{

    string str = "1abc23";

    cout << getSum(str);

    return 0;
}

// https://takeuforward.org/data-structure/sum-of-the-numbers-in-a-string/