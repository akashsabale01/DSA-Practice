#include <iostream>

using namespace std;

class car
{
    int x;
    static int count; // only one copy of static variable for all objects of current class

public:
    car()
    {
        count++;
    }
    static int getCount() // it can only access static varible
    {
        return count;
    }
};

// Initialize static variable
int car::count = 0;

int main()
{
    cout << car::getCount() << endl;

    car obj;
    car obj1;
    car obj2;

    cout << car::getCount() << endl;

    return 0;
}