#include <iostream>
#include <unordered_map>

using namespace std;

int countOfUniqueElements(int arr[], int n)
{
    unordered_map<int, int> freq;

    for (int i = 0; i < n; i++)
        freq[arr[i]]++;

    int uniqueElementCount = 0;

    for (auto element : freq)
    {
        if (element.second == 1)
        {
            cout << element.first << " " << element.second << endl;
            uniqueElementCount++;
        }
    }
    return uniqueElementCount;
}

int main()
{
    int arr[] = {1, 1, 3, 4, 4, 6, 7, 7, 8};
    int n = sizeof(arr) / sizeof(arr[0]);

    int result = countOfUniqueElements(arr, n);

    cout << "count Of Unique Elements = " << result << endl;

    return 0;
}