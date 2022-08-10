#include <iostream>
#include <string>
using namespace std;

bool isPalindrome(int num)
{
    // Approach 1 - Without using string
    // int rev=0, Original = num, rem;
    // while(num!=0)
    // {
    //     rem = num % 10;
    //     rev = rev*10 + rem;
    //     num = num / 10;
    // }
    
    // return (rev == Original);
    
    // Approach 2 - Using string
    string original = to_string(num);
    string rev = to_string(num);
    
    for(int i=0,j=rev.size()-1; i<j; i++,j--)
    {
        char temp = rev[i];
        rev[i] = rev[j];
        rev[j] = temp;
    }
    
    return (original == rev);
}

int main() {
    
    string result = (isPalindrome(131))? "Yes":"No";
    cout<<result;

    return 0;
}
