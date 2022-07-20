#include <iostream>
#include <vector>

using namespace std;

// Reverse Number Without using string
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

// Reverse Number Using string

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
    // 121
    // modulo by 10 for getting last digit
    // divide by 10 for updating num i.e. 12 then 1
    // we have to reverse number

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


int main()
{
    int arr[]= {11,48,121,420,205,505,66,91,123,212};
    int arrSize = sizeof(arr)/sizeof(arr[0]);

    PalindromeRes(arr, arrSize);

    return 0;
}
