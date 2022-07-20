#include <iostream>

using namespace std;

// Approach 1- GCD of two number is always <= minimum number from given two number
// TC= O(min(a,b)), SC= O(1)
//int GCD(int x, int y)
//{
//    if(x==0 || y==0) return 0;
//
//    int minimum = (x<y)? x:y;
//    int res= 1;
//
//    for(int i=minimum; i>=2; i--)
//    {
//        if(x%i==0 && y%i==0)
//        {
//            res = i;
//            break;
//        }
//
//    }
//
//    return res;
//}
//

// Approach 1- Euclean GCD Alogrithm(Iterative) .. Subtract min value from max value of both numbers
// TC= O(min(x,y)), SC= O(1)
//int GCD(int x, int y)
//{
//    while(x != y)
//    {
//        if(x>y)
//            x -= y;
//        else
//            y -= x;
//    }
//    return x;
//}


// Approach 2- Euclean GCD Alogrithm(Iterative) .. Subtract min value from max value of both numbers
// TC= O(min(a,b)), SC= O(1)
//int GCD(int a, int b)
//{
//    // Everything divides 0
//    if(b==0)    return a;
//    if(a==0)    return b;
//
//    // base case
//    if(a==b)
//        return a;
//
//    // rec case
//    if (a>b)
//        return GCD(a-b, b); // A Greater
//
//    return GCD(a, b-a); // b Greater
//}
//

// Approach 3 - use modulo operator in Euclidean algorithm
// TC=  O(log(min(a,b)), SC=  O(log(min(a,b))
int GCD(int a, int b)
{
    if(b==0)
        return a;
    else
        return GCD(b, a%b);

}
int main()
{
    int a=15, b=30;

    cout<<"GCD = "<<GCD(a,b);

    return 0;
}
