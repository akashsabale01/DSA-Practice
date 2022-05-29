#include <iostream>

using namespace std;

int getLength(string name)
{
    int len = 0;

    for(int i=0; i<int(name.size()); i++)   // this works
        len++;

//    for(int i=0; name[i]!='\0'; i++) // this also works
//        len++;

    return len;
}

int stringLength(char ct[])
{
    // iterate string till '\0' character is found
    int i; // using i for counting length
    for(i=0; ct[i]!='\0'; i++){}

    return i;
}

int main()
{
    string name = "Akash";
    cout<<"Length of "<<name<<" = "<<getLength(name)<<endl;

    char city[] = "Akash";
    stringLength(city);
    cout<<"Length of "<<city<<" = "<<getLength(city)<<endl;

    return 0;
}
