#include <iostream>
#include <vector>

using namespace std;

// Approach 1 - Reverse Number Without using string
bool isPalindromeNum(int num)
{
    int res=0, oNum=num, rem;

    while(num > 0)
    {
        rem = num % 10;
        res = res*10 + rem;
        num = num / 10;
    }

    return (res == oNum);
}

// Approach 2 - Reverse Number Using string
//bool isPalindromeNum(int num)
//{
//    string oNum = to_string(num);
//    string rev = to_string(num);
//
//    for(int i=0,j=rev.size()-1; i<j; i++,j--)
//    {
//        char temp = rev[i];
//        rev[i] = rev[j];
//        rev[j] = temp;
//    }
//
//    if(oNum == rev)
//        return true;
//
//    return false;
//}
//

void PalindromeRes(int arr[], int arrSize)
{
    vector<int> result;

    for(int i=0; i<arrSize; i++)
    {
        if(isPalindromeNum(arr[i]))
            result.push_back(arr[i]);
    }

    // Print
    int vSize = result.size();
    for(int i=0; i<vSize; i++)
        cout<<result[i] << " ";
}


//void push(int res[], int &length, int resSize, int element)
//{
//    if(length < resSize)
//    {
//        res[length++] = element;
//    }
//}
//
//void PalindromeRes(int arr[], int arrSize)
//{
//    int result[arrSize]={0};
//    int resSize = sizeof(result)/sizeof(result[0]);
//    int resLength=0;
//
//    for(int i=0; i<arrSize; i++)
//    {
//        if(isPalindromeNum(arr[i]))
//            push(result, resLength, resSize, arr[i]);
//    }
//
//    // Print
//    for(int i=0; i<resLength; i++)
//        cout<<result[i] << " ";
//}
//


int main()
{
    int arr[]= {11,48,121,420,205,505,66,91,123,212};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    PalindromeRes(arr, arrSize);

    return 0;
}
