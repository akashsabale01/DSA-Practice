#include <iostream>
using namespace std;

int main(){

    // we are increasing size of array by creating new array having double size of original
    // array, and shifting elements from old to new array

    int *p,*q;

    p = new int[5];
    p[0]=21;
    p[1]=31;
    p[2]=41;
    p[3]=51;
    p[4]=61;

    q = new int[10];

    // copy elements of p to q
    for(int i=0; i<5; i++){
        q[i] = p[i];
    }

    delete []p;
    p = q;
    q = NULL;

    // p array
    for(int i=0;i<5;i++){
        cout<<p[i]<<endl;
    }

    cout<<sizeof(p);

    return 0;
}
