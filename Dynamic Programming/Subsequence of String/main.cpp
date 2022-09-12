#include <iostream>
#include <vector>

using namespace std;

void solve(vector<string> &ans, string str, string output, int index)
{
    // Base case
    if (index >= str.length())
    {
        if (output.length() > 0) // ignore " " subsequence
            ans.push_back(output);
        return;
    }

    // Exclude char
    solve(ans, str, output, index + 1);

    // Include char
    char element = str[index];
    output.push_back(element);
    solve(ans, str, output, index + 1);
}

vector<string> printSubsets(string str)
{
    vector<string> ans;
    string output = "";
    int index = 0;

    solve(ans, str, output, index);

    return ans;
}

void subsequence(string processed, string unprocessed, vector<string> &ans)
{
    if (unprocessed.empty())
    {
        if (processed.length() > 0)
            ans.push_back(processed);
        return;
    }

    // Include
    // Take ch character from unprocessed & Ignore 0th char from processed
    char ch = unprocessed[0];
    subsequence(processed + ch, unprocessed.substr(1), ans);

    // Exlude
    // Ignore ch character from unprocessed & Ignore 0th char from p rocessed
    subsequence(processed, unprocessed.substr(1), ans);
}

vector<string> getSubsequence(string str)
{
    vector<string> ans;
    string processed = "";
    string unprocessed = str;

    subsequence(processed, unprocessed, ans);

    return ans;
}

int main()
{
    string str = "abc";

    // vector<string> res = getSubsequence(str);
    vector<string> res = printSubsets(str);

    for (auto ele : res)
        cout << ele << " ";

    return 0;
}

// https://www.youtube.com/watch?v=V0IgCltYgg4
// https://youtu.be/gdifkIwCJyg