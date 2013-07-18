//A()
//A()
//A()
//A()
//A()
//~A()
//~A()
//~A()
//~A()
//~A()

#include <iostream>  // cout, endl
#include <vector>    // vector

using namespace std;

struct A {
    A () {                     // default constructor
        cout << "A() ";}

    A (const A&) {             // copy constructor
        cout << "A(A) ";}

    ~A () {                    // destructor
        cout << "~A() ";}

    A& operator = (const A&) { // copy assignment operator
        cout << "=(A) ";
        return *this;}};

int main () {
    {
    vector<A> x(5);
    cout << endl;
    }
    cout << endl;

    cout << "Done." << endl;
    return 0;}
