#include <iostream>
#include <vector>

using namespace std;

int digitSum(int n)
{
    int dsum = 0;
    while (n != 0)
    {
        int rem = n % 10;
        dsum += rem;
        n /= 10;
    }
    return dsum;
}

vector<int> getResultArr(vector<int> arr)
{
    vector<int> res;

    for (int ele : arr)
    {
        int dsum = digitSum(ele);
        res.push_back(dsum);
    }
    return res;
}

int main()
{
    vector<int> arr = {15, 23, 55, 20, 43};

    vector<int> res = getResultArr(arr);

    for (int ele : arr)
        cout << ele << " ";
    cout << endl;

    for (int ele : res)
        cout << ele << " ";
    cout << endl;

    return 0;
}