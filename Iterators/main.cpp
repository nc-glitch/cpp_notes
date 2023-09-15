#include <iostream>
#include "Vector.h"
#include <vector>

int main() {

    // Used to iterate over a collection of elements

    std::vector<int> values = { 1, 2, 3, 4, 5 };


    // For Each Loops uses iterators to function
    for(int n : values)
        std::cout << n << std::endl;
    // for( auto it = values.begin(); it != values.end(); i++)

    // must derefr iterators to access their value

    std::cout << std::endl;

    // IMPLMENTING ITERATORS

    Vector<int> vals;
    vals.EmplaceBack(9);
    vals.EmplaceBack(10);
    vals.EmplaceBack(11);

    for(int val : vals)
    {
        std::cout << val << std::endl;
    }

}
