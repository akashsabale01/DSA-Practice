/*
    C° to F°: Celsius to Fahrenheit Conversion Formula
    To convert temperatures in degrees Celsius to Fahrenheit, multiply by 1.8 (or 9/5) and add 32.
*/
#include <iostream>

using namespace std;

int main()
{

    // float celsius = 23;

    // float fahrenheit = (celsius * 1.8) + 32;

    // cout << celsius << " celsius = " << fahrenheit << " fahrenheit" << endl;

    float fahrenheit = 2;

    float celsius = (fahrenheit - 32) / 1.8;

    cout << fahrenheit << " fahrenheit = " << celsius << " celsius" << endl;

    return 0;
}