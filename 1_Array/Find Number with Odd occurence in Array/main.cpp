#include <bits/stdc++.h>

using namespace std;

// Approach 1 - Using Unordered Map TC= O(N) SC= O(N)
int oddOccurenceNum(vector<int> arr)
{
    unordered_map<int, int> umap;

    for (int i = 0; i < arr.size(); i++)
        umap[arr[i]]++;

    for (auto ele : umap)
    {
        if (ele.second % 2 == 1)
            return ele.first;
    }

    return -1;
}

// Approach 2 - Using Xor TC= O(N) SC= O(1)
int oddOccurenceNum(vector<int> arr)
{
    int res = 0;

    for (int i = 0; i < arr.size(); i++)
        res = res ^ arr[i];

    return res;
}

int main()
{
    vector<int> a = {1, 2, 3, 2, 3, 1};

    cout << "num = " << oddOccurenceNum(a);

    return 0;
}
