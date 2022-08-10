#include <iostream>
using namespace std;

class Human
{
private:
    int age;

protected:
    int height;

public:
    int weight;

    int getAge()
    {
        return this->age;
    }

    void setHeight(int height)
    {
        this->height = height;
    }
};

class Male : private Human
{
public:
    string color;

    void WhoAmI()
    {
        cout << "I am Male" << endl;
    }

    void getHeight()
    {
        cout << "My name is " << this->height << endl;
    }
};

int main()
{
    Male m1;

    cout << m1.weight << endl;

    return 0;
}