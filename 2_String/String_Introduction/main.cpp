#include <iostream>
#include <string>

using namespace std;

int main()
{

   // char
//    char gender = 'a';
//    printf("%c",gender);
//    printf("%d",gender); // prints ASCII of it
//    cout<<gender<<endl;

    // character array
//    char arr[5] = {'a','b','c','d'};
//    char arr1[] = {'a','b','c','d'};
//    char arr2[] = {97,98,99,100}; // this is same as arr1 only ascii used

    // Print character array
//    int sz = sizeof(arr1)/sizeof(arr1[0]);
//    for(int i=0; i<sz; i++)
//        cout<<arr1[i]<<" ";

//     String
//     here \0 is delimiter i.e. string terminator
//     difference between string & char array is that string contains '\0',
//     whereas char array does not contains '\0'

//    creating string
//    char name[] = {'J','h','o','n','\0'};
//    char name1[] = "Dom";

    // Print string
//    cout<<name<<endl;
//    cout<<name1<<endl;

//    Taking String from User Input
//    char FullName1[15];
//    char FullName2[15];


// Using Scanf()
//    printf("Enter your Full name = ");
//    scanf("%s",FullName1);
//    printf("By scanf() Fullname is %s\n",FullName1);

//Using cin
//    cout<<"Enter your Full name = ";
//    cin>>FullName1;
//    cout<<"By cin Full name = "<<FullName1;

// scanf() and cin takes input string upto space , So output is first name only


// gets(StringName) is used to take input string with space, So output is both first & lastname

//Using gets(StringName)
//    cout<<"Enter your Full name = ";
//    gets(FullName1);
//    cout<<"Full name = "<<FullName1;

//When you write
//char stack[] = "hello";
//you are creating a new auto ("stack") variable of type "6-element array of char" (size is taken from  the length of the string literal), and the contents of the string literal "hello" are copied to it.

//When you write
//char *heap = "hello";
//you are creating a new auto ("stack") variable of type "pointer to char", and the address of the string literal "hello" is copied to it.

    return 0;
}
