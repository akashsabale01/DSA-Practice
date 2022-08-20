//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
//User function template in C++

class Solution{
    public:
    //Function to return the count of number of elements in union of two arrays.
    int doUnion(int a[], int n, int b[], int m)  {
        // Approach 1 -
        
        sort(a, a+n);
        sort(b, b+m);
        
        int ans[m+n];
        
        int i=0,j=0,k=0;
        
        while(i<n && j<m)
        {
            if(a[i] < b[j])
            {
                if(k!=0 && a[i] == ans[k-1])
                    i++;
                else
                    ans[k++] = a[i++];
            }
                
            else if(b[j] < a[i])
            {
                if(k!=0 && b[j] == ans[k-1])
                    j++;
                else
                    ans[k++] = b[j++];
            }
                
            // else if(a[i] == b[j])
            // {
            //     ans[k++] = a[i];
            //     i++,j++;
            // }
        }
        
        // Add elements if remaining
        while(i < n)
        {
            if(k!=0 && a[i] == ans[k-1])
                i++;
            else
                ans[k++] = a[i++];
        }
            
        while(j < m)
        {
            if(k!=0 && b[j] == ans[k-1])
                    j++;
            else
                ans[k++] = b[j++];
        }
        
        return k;
        
        // Approach 2 - Using set
        // set<int> st;
        // for(int i=0 ; i<n;i++)
        // st.insert(a[i]);
        
        // for(int j=0;j<m;j++)
        // st.insert(b[j]);
        
        // return st.size();
        
    }
};

//{ Driver Code Starts.

int main() {
	
	int t;
	cin >> t;
	
	while(t--){
	    
	    int n, m;
	    cin >> n >> m;
	    int a[n], b[m];
	   
	    for(int i = 0;i<n;i++)
	       cin >> a[i];
	       
	    for(int i = 0;i<m;i++)
	       cin >> b[i];
	    Solution ob;
	    cout << ob.doUnion(a, n, b, m) << endl;
	    
	}
	
	return 0;
}
// } Driver Code Ends







