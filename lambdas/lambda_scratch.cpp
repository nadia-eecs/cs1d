/* Examples below are taken from Arthur O'Dwyer's Cppcon Lecture
https://www.youtube.com/watch?v=3jCOwajNch0
*/

#include <iostream>

// here's a regular function
int plus1(int x) {
    return x+1;
}

double plus1(double x) {
    return x+1;
}

// templated
template<typename>
T plus1(T x) {
    return x+1;
}

// here's a member function in a class


int main() {
    // calling each type of function and printing output

    return 0
}