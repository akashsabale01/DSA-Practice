#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
/*
    // vector of size zero but can grow
    vector <int> arr;

    // with some elements but can grow
    vector <int> arr = {2,4,6,7,8,9};

    // Fill constructor
    // vector of size 10 created having all values as zero
    vector <int> arr(10,0);

    // Add to end of vector
    arr.push_back(12);
    arr.push_back(2);
    arr.push_back(5);
    arr.push_back(34);
    arr.push_back(86);

    // remove last element of vector
    arr.pop_back();

    // print vector
    cout<<"Vector arr = ";
    for(int i=0;i<int(arr.size());i++)
        cout<<arr[i]<<" ";

    for(int number: arr)
        cout<<number<<" ";
    cout<<endl;

    // return length i.e. no of elements present
    cout<<"size = "<<arr.size()<<endl;

    // return actual allocated memory of vector
    cout<<"capacity = "<<arr.capacity()<<endl;

*/

//
//    // 2D Vector
//    vector< vector<int> > arr = {
//        {4,6,7},
//        {88,99,33,86},
//        {2,5},
//        {34,15,32}
//    };
//
//    // update any element
//    arr[0][1] = 33;
//
//    // print
////    for(int i=0;i<int(arr.size());i++)
////    {
////        for(int number : arr[i])
////            cout<< number <<" ";
////        cout<<endl;
////    }
//
//    // arr.size() returns no of rows in vector
//    // arr[i].size()retuns no of columns present at i'th row vector
//    for(int i=0;i<int(arr.size());i++)
//    {
//        for(int j=0;j<int(arr[i].size());j++)
//            cout<< arr[i][j] <<" ";
//        cout<<endl;
//    }



// Searching in vector
//
//    vector <int> v = {10,24,6,7,8,2,78,42};
//    int key;
//    cout<<"key= ";
//    cin>>key;
//
//    // include <algorithm> for using inbuilt seach function
//
//    // find() - internally uses linear search
//    // iterator is like pointer to vector
//    vector<int>::iterator itr = find(v.begin(),v.end(),key);
//
//    // index = Address - Base Address
//    // index = itr - v.begin(); here v.begin() is also iterator which return address
//
//    if(itr!=v.end())
//        cout<<"Key present at = "<<itr - v.begin() <<endl;
//    else
//        cout<<"not found";
//


    return 0;
}
