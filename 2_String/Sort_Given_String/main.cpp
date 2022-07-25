#include <iostream>

using namespace std;

string sortString(string str)
{
    int strSize = str.size();
    for (int i = 0; i < strSize - 1; i++)
    {
        for (int j = i + 1; j < strSize; j++)
        {
            if (str[i] >= str[j])
            {
                char temp = str[i];
                str[i] = str[j];
                str[j] = temp;
            }
        }
    }

    return str;
}

int main()
{
    string str = "CcbBaA";

    string result = sortString(str);

    cout << result;

    return 0;
}
