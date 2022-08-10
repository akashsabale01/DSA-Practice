#include <bits/stdc++.h>
using namespace std;

// this is same as gfg roll string
string rollTheString(string s, vector<int> roll)
{
    int n = (int)roll.size();
    int sSize = (int)s.size();

    vector<int> p(sSize + 1, 0);
    for (int i = 0; i < n; i++)
    {
        p[0]++;
        p[roll[i]]--;
    }

    for (int i = 1; i < sSize; i++)
    {
        p[i] += p[i - 1];
    }

    for (int i = 0; i < sSize; i++)
    {
        int c = s[i] - 'a';
        c = (c + p[i]) % 26;
        s[i] = char('a' + c);
    }

    return s;
}

int main()
{
    string s = "zcza";

    // roll array
    vector<int> roll = {1, 1, 3, 4};

    string res = rollTheString(s, roll);

    cout << endl
         << res << endl;

    return 0;
}
