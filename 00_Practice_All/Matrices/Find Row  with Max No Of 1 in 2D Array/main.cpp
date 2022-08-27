/*
    Find Row with Max No Of 1 in 2D Array

    input 2d array
        0 1 1 1
        0 0 1 1
        1 1 1 1
        0 0 0 0

    Note- array elements are sorted, Assume it is square matrix

*/

#include <iostream>
#include <vector>

using namespace std;

// 1st Approach
// Time Complexity:  O(m*n)
// Space Complexity:  O(1)
int getMax1Count(vector<vector<int>> arr)
{
    int arrSize = arr.size();
    int maxCountOf1 = 0, rowIndexofMax1 = -1;

    for (int i = 0; i < arrSize; i++)
    {
        int currCountOf1 = 0;
        for (int j = 0; j < arrSize; j++)
        {
            if (arr[i][j] == 1)
                currCountOf1++;
        }

        if (currCountOf1 > maxCountOf1)
        {
            maxCountOf1 = currCountOf1;
            rowIndexofMax1 = i;
        }
    }

    return rowIndexofMax1;
}

// 2nd Approach

// int getMax1Count(vector<vector<int>> arr)
// {
//     int arrSize = arr.size();

//     int maxCountOf1 = 0, j = arrSize - 1;

//     for (int i = 0; i < arrSize; i++)
//     {
//         while (j >= 0 && arr[i][j] == 1)
//             for (int j = 0; j < arrSize; j++)
//             {
//                 if (arr[i][j] == 1)
//                     currCountOf1++;
//             }

//         maxCountOf1 = (currCountOf1 > maxCountOf1) ? currCountOf1 : maxCountOf1;
//     }
//     return maxCountOf1;
// }

int main()
{

    vector<vector<int>> inputArr = {
        {0, 1, 1, 1},
        {0, 0, 1, 1},
        {1, 1, 1, 1},
        {0, 0, 0, 0},
    };

    int result = getMax1Count(inputArr);
    cout << result << endl;

    return 0;
}

// https://www.geeksforgeeks.org/find-the-row-with-maximum-number-1s/