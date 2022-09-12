#include <iostream>

using namespace std;

// int getPosition(string str1, string str2)
// {
//     return str1.find(str2);
// }

int getPosition(string str, string substring)
{

    string temp = "";

    int n1 = str.size(), n2 = substring.size();
    int position = -1;

    for (int i = 0; i < n2; i++)
    {
        for (int j = 0; j < n1; j++)
        {
            if (substring[i] == str[j])
            {
                if (j + n2 <= n1)
                {
                    position = j;
                    string temp = str.substr(j, n2);
                    cout << temp << endl;

                    if (temp == substring)
                        return position;
                }
            }
        }
    }

    return position;
}

int main()
{
    // string str1 = "takeuforward", str2 = "forward";
    string str1 = "hello", str2 = "az";

    cout << getPosition(str1, str2);

    return 0;
}

// https://takeuforward.org/data-structure/find-the-position-of-a-substring-within-a-string/