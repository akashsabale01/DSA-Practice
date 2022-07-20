#include <iostream>
#include <vector>

using namespace std;

void printWordsContainingChar(string greet, char ch)
{
    int n = greet.length();
    bool found = false;

    vector<string> res;

    for(int i=0,j=0; j<n; j++)
    {
        if(greet[j] == ch)
            found = true;

        if(greet[j+1]==' ' || j==n-1)
        {
            if(found)
            {
                res.push_back(greet.substr(i,j+1));
                found = false;
            }
            j = j + 1;
            i = j + 1;
        }
    }

    // Print res
    int vSize = res.size();
    for(int k=0; k<vSize; k++)
        cout<<res[k]<<endl;
}


int main()
{
    string greeting = "welcome to the world of coding";
    char inpChar = 'w';

    printWordsContainingChar(greeting, inpChar);


    return 0;
}

//    int i=0,j=0;
//    while(j < n)
//    {
//        if(greet[j] == ch)
//        {
//            found = true;
//            j++;
//        }
//
//        else if(greet[j+1]==' ' || j==n-1)
//        {
//            if(found)
//            {
//                res.push_back(greet.substr(i,j+1));
//                found = false;
//            }
//            j = j + 2;
//            i = j;
//        }
//        else
//            j++;    // Char Not Matching then go for next iteration
//    }
