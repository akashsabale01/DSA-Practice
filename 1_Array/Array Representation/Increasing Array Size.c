#include <stdio.h>
#include <stdlib.h>


int main(){

    // we are increasing size of array by creating new array having double size of original
    // array, and shifting elements from old to new array

    int *p,*q;

    p = (int *) malloc(5*sizeof(int));
    p[0]=21;
    p[1]=31;
    p[2]=41;
    p[3]=51;
    p[4]=61;

    q = (int *) malloc(10*sizeof(int));

    // copy elements of p to q
    int i;
    for(i=0; i<5; i++){
        q[i] = p[i];
    }

    free(p);
    p = q;
    q = NULL;

    // p array
    for(i=0;i<5;i++){
        prinf('%d \n',p[i]);
    }

//    cout<<sizeof(p);

    return 0;
}
