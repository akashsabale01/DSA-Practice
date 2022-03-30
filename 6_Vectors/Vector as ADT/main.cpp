#include <iostream>
#include "vector.h"

using namespace std;

int main()
{
    Vector<char> vc(5);
    vc.Push_back('a');
    vc.Push_back('k');
    vc.Push_back('a');
    vc.Push_back('s');
    vc.Push_back('h');
    vc.Push_back('S');
    vc.Pop_back();

    for(int i=0;i<vc.Size();i++)
        cout<<vc[i]<<" ";

    cout<<endl;

//    v.Push_back(2);
//    v.Push_back(6);
//    v.Push_back(8);
//    v.Push_back(5);
//    v.Push_back(9);
//    v.Push_back(33);
//    v.Pop_back();

//    cout<< v.Front()<<endl;
//    cout<< v.Back()<<endl;

//    cout<< v.At(2)<<endl;

//    cout<< v.Size()<<endl;
//    cout<< v.Capacity()<<endl;

//    cout<<"Vector = ";
//    for(int i=0;i<v.Size();i++)
//        cout<<v[i]<<" ";


    return 0;
}
