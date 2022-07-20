/*/%

Given a Integer array A[] of n elements. Your task is to complete the function PalinArray. Which will return 1 if all the elements of the Array are palindrome otherwise it will return 0.

Example:
Input:
2
5
111 222 333 444 555
3
121 131 20

Output:
1

https://practice.geeksforgeeks.org/problems/palindromic-array-1587115620/1?page=1&status[]=bookmarked&sortBy=submissions
/*/

#include<iostream>
#include<string.h>
using namespace std;


// } Driver Code Ends
/*Complete the function below*/

class Solution {
public:

    int reverseNum(int n)
    {
        int rev = 0;
        while(n!=0)
        {
            int rem = n % 10;
            rev = rev*10 + rem;
            n = n / 10;
        }
        return rev;
    }

    int PalinArray(int a[], int n)
    {
    	int palindrome = 0;

    	for(int i=0; i<n; i++)
    	{
    	    if(a[i] != reverseNum(a[i]))
    	        return 0;
    	    else
    	        palindrome = 1;

    	}

    	return palindrome;
    }
};

//{ Driver Code Starts.

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n];
		for(int i = 0; i < n; i++)
			cin>>a[i];
		Solution obj;
		cout<<obj.PalinArray(a,n)<<endl;
	}
}
// } Driver Code Ends
