#include <iostream>
using namespace std;

// Function to modify values
// ref → passed by reference (alias of original variable)
// value → passed by value (copy of original variable)
void modifyValue(int &ref, int value)
{
    ref = 10;     // This WILL change the original variable (because it's a reference)
    value = 10;   // This will NOT affect the original variable (it's just a copy)

    // Print memory address of ref
    // This is actually the SAME address as the original variable passed in
    cout << &ref << endl;

    // Print memory address of value
    // This is a DIFFERENT address (local copy inside the function)
    cout << &value << endl;
}

int main()
{
    int a = 5;
    int x = 5;

    // Print address of a
    cout << &a << endl;
    cout << "Before call a is: " << a << endl;

    // Print address of x
    cout << &x << endl;
    cout << "Before call x is: " << x << endl;

    // Function call
    // a → passed by reference → will change
    // x → passed by value → will NOT change
    modifyValue(a, x);

    // After function call
    cout << "After call a is: " << a << endl; // becomes 10
    cout << "After call x is: " << x << endl; // remains 5

    return 0;
}