/*
Tower of Hanoi is a mathematical puzzle where we have three rods and n disks.
The objective of the puzzle is to move the entire stack to another rod,
it obeying the following simple rules:

    1) Only one disk can be moved at a time.

    2) Each move consists of taking the upper disk from one of the stacks
    and placing it on top of another stack i.e. a disk can only be moved
    if it is the uppermost disk on a stack.

    3)No disk may be placed on top of a smaller disk.
*/

#include <iostream>

using namespace std;

// n= no of disks, a= from tower(start tower), b= to tower(result tower), c= aux tower(temp tower)
void TOH(int n, char a, char b, char c)
{
    if(n>0)
    {
        TOH(n-1, a, c, b);
        printf("Move Disk %d from tower %c to tower %c\n", n,a,c);
        TOH(n-1, b, a, c);
    }
}

int main()
{
    cout<<"Steps for moving disks between towers are : "<<endl;

    TOH(3, 'a', 'b', 'c');

    return 0;
}
