#include <iostream>
#include <utility>  // for pair
#include <string>

using namespace std;

int main()
{
    // ********** Pairs *********

    /*
        Pair is used to combine together two values that may be different in type.
        It is basically used if we want to store tuples.

        The pair container is a simple container defined in <utility> header consisting of two data elements or objects.
        The first element is referenced as ‘first’ and the second element as ‘second’ and the order is fixed (first, second).

        To access the elements, we use variable name followed by dot operator followed by the keyword first or second.

        Syntax:
                pair (data_type1, data_type2) Pair_name

    */

//    pair<int, int> p = {2,3};
    pair<int , string> d = {21,"akash"};

    // prints 2 3
//    cout<<p.first<<" "<<p.second<<endl;


    cout<<d.first<<" "<<d.second<<endl;






    return 0;
}
