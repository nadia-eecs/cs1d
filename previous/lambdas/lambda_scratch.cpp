/* Examples below are taken from Arthur O'Dwyer's Cppcon Lecture
https://www.youtube.com/watch?v=3jCOwajNch0
*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// here's a regular function
int plusOne(int x) {
    return x+1;
}

double plusOne(double x) {
    return x+1;
}

// templated
template<typename T>
T plus1(T x) {
    return x+1;
}

// here's a member function in a class
class PlusOnev1 {
    int x;
    public:
        PlusOnev1(int x) : x(x) {}
        int plus1(int x) const {
            return x+1;
        }
};

// here's an overloaded parentheses operator
class PlusOnev2 {
    int x;
    public:
        PlusOnev2(int x) : x(x) {}
        int operator()(int x) const {
            return x+1;
        }
};

class PlusVal {
    int val;
    public:
        PlusVal(int val) : val(val) {}
        int operator()(int x) const {
            return x+val;
        }
};
struct Book {
    std::string title;
    std::string author;
    int year;
};

// ========= Significance of the different capture types: =========
// In C++, a closure is a function object that has access to variables from its 
// enclosing scope. These variables are captured by the lambda function and can be
// used inside its body. The way these variables are captured can affect how they 
// are used and modified.

// Book Title function example
bool containsTitle(const std::vector<Book>& shelf, const std::string& title) {
    // ====== capture title by value/copy: [t=title] =====
    // This lambda function captures the title variable by value, meaning it creates
    // a copy of title and assigns it to t. Any changes made to t inside the lambda
    // function will not affect the original title variable.

    // auto hasTitle = [t=title](const Book& b) {
    //     return b.title == t; 
    // };

    // ===== alternative: capture title by pointer: [ptr=&title] =====
    // This lambda function captures the title variable by pointer. It creates a pointer
    // ptr that points to the title variable. This allows the lambda function to access
    // the original title variable, but it also means that if the original title variable
    // goes out of scope or is destroyed, the pointer will become invalid.

    // auto hasTitle = [ptr=&title](const Book& b) {
    //     return b.title == *ptr;
    // };

    // ===== alternative: capture title by reference: [&t=title] =====
    // This lambda function captures the title variable by reference. It creates a reference
    // t to the title variable. This allows the lambda function to access and modify the original
    // title variable. However, like with the pointer, if the original title variable goes out of
    // scope or is destroyed, the reference will become invalid.

    // auto hasTitle = [&t=title](const Book& b) {
    //     return b.title == t;
    // };

    // ===== alternative: capture title by move: [t=std::move(title)] =====
    // This lambda function captures the title variable by moving it. It uses std::move to transfer
    // ownership of title to t, which can be more efficient for large objects. However, after the move,
    // the original title variable should not be used, as its state is considered to be valid but unspecified.

    // auto hasTitle = [t=std::move(title)](const Book& b) {
    //     return b.title == t;
    // };

    // ===== alternative: capture only what is needed by reference: [&] =====
    // This lambda function captures all variables used in its body by reference. This can be convenient
    // when the lambda function uses many variables from its enclosing scope, but it can also lead to
    // unintended side effects if the lambda function modifies these variables.

    // auto hasTitle = [&] (const Book& b) {
    //     return b.title == title;
    // };

    // ===== alternative: capture only what is needed by value: [=] =====
    // This lambda function captures all variables used in its body by value. This can be convenient
    // when the lambda function uses many variables from its enclosing scope, but it can also lead to
    // unintended side effects if the lambda function modifies these variables.

    auto hasTitle = [=] (const Book& b) {
        return b.title == title;
    };


    return shelf.end() != std::find_if(shelf.begin(), shelf.end(), hasTitle);
}
int main() {
    // calling each type of function and printing output

    // vanilla function
    int x = 5, y = 7;
    std::cout << "plusOne(x) = " << plusOne(x) << std::endl;
    std::cout << "plusOne(y) = " << plusOne(y) << std::endl;

    // templated function
    float a = 5.0;
    double b = 7.0;

    std::cout << "plus1(a) = " << plus1(a) << std::endl;
    std::cout << "plus1(b) = " << plus1(b) << std::endl;

    // call member function of a class
    PlusOnev1 myObj1(5); // calling constructor
    std::cout << "myObj1.plus1(x) = " << myObj1.plus1(x) << std::endl;  // calling member function

    // call overloaded parentheses operator
    PlusOnev2 myObj2(5); // calling constructor
    std::cout << "myObj2(x) = " << myObj2(x) << std::endl; // calling overloaded parentheses operator

    // call plusVal
    PlusVal myObj3(5); // calling constructor
    int w = 7;
    std::cout << "myObj3(w) = " << myObj3(w) << std::endl; // calling overloaded parentheses operator

    // call lambda
    auto plusval = [w=7](int x) { return x+1; };

    // Using example of finding a book title in a vector of books on a shelf
    std::vector<Book> shelfObj;
    Book book1 = {"The C++ Programming Language", "Bjarne Stroustrup", 1985};
    Book book2 = {"Effective Modern C++", "Scott Meyers", 2014};
    Book book3 = {"Effective C++", "Scott Meyers", 1992};
    Book book4 = {"C++ Primer", "Stanley Lippman", 1998};

    shelfObj.push_back(book1);
    shelfObj.push_back(book2);
    shelfObj.push_back(book3);
    shelfObj.push_back(book4);

    std::string mytitle = "Effective Modern C++";

    std::cout << "shelfObj contains book1: " << containsTitle(shelfObj, mytitle) << std::endl;

    return 0;
}