#include <iostream>
#include <vector>
using namespace std;

vector<int> getPair(string exp, int &k, int &l, int &r)
{
    while (k < exp.size())
    {
        if (l == -1 && exp[k] == '#')
            l = k;
        k++;
        if (l != -1 && exp[k] == '#')
        {
            r = k;
            break;
        }
    }
    return {k, l, r};
}

bool isLower(char ch)
{
    return (ch >= 'a' && ch <= 'z');
}

int getCount(string exp, int &k, int &l, int &r)
{
    if (l == -1 || r == -1)
        return 0;

    int cnt = 0;
    for (int i = l + 1; i < r - 1; i++)
    {
        if (exp[i] == '!' && isLower(exp[i + 1]))
            cnt++;
    }
    return cnt;
}

int escapeCount(string exp)
{
    int resCount = 0;
    vector<int> tuple{0, -1, -1}; // k,l,r;
    while (tuple[0] < exp.size())
    {
        tuple = getPair(exp, tuple[0], tuple[1], tuple[2]);

        int pairCount = getCount(exp, tuple[0], tuple[1], tuple[2]);
        if (pairCount == 0)
        {
            tuple[0] = tuple[2] + 1;
            tuple[1] = -1;
            tuple[2] = -1;
        }
        else
            resCount += pairCount;
    }

    return resCount;
}

int main()
{
    string exp = "#ab!c#de!f";
    // string exp = "##!b#po#";

    int count = escapeCount(exp);
    cout << endl;
    cout << "Escape count = " << count << endl;

    return 0;
}
