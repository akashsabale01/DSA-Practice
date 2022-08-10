#include <iostream>
using namespace std;

class Hero
{
private:
    int health;

public:
    string name;

    Hero()
    {
        cout << "constructor called" << endl;
    }

    Hero(string name)
    {
        this->name = name;
        // cout << "this -> " << this << endl;// have same address similar to current object
    }

    // Copy constructor
    Hero(Hero &temp)
    {
        cout << "Inside Copy Constructor" << endl;
        this->name = temp.name;
    }

    void whoAmI()
    {
        cout << "I am " << name << endl;
    }
};

int main()
{
    // Hero obj1("ramesh");
    // obj1.whoAmI();

    // Hero *obj2 = new Hero("John");

    // cout << "obj address -> " << obj2 << endl; // obj2 and this points to same object

    Hero obj2("Thor");
    obj2.whoAmI();

    Hero obj3(obj2);
    obj3.whoAmI();

    return 0;
}