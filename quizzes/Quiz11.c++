/*
CS378: Quiz #11 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?

A(int)

A() A()
=(A) =(A)
~A() ~A()

A(A) A(A)
~A() ~A()

~A()
*/

#include <iostream> // cout, endl
#include <cstddef>  // size_t
#include <vector>   // vector

using namespace std;

struct A {
    A             ()         {cout << "A() ";}                  // default constructor
    A             (int)      {cout << "A(int) ";}               // int constructor
    A             (const A&) {cout << "A(A) ";}                 // copy constructor
    ~A            ()         {cout << "~A() ";}                 // destructor
    A& operator = (const A&) {cout << "=(A) "; return *this;}}; // copy assignment operator

int main () {
    {
    const std::size_t s = 2;
    const A           v = 3;
    cout << endl << endl;

    {
    A* a = new A[s];
    cout << endl;
    fill(a, a + s, v);
    cout << endl;
    delete [] a;
    cout << endl;
    }
    cout << endl;

    {
    vector<A> x(s, v);
    cout << endl;
    }
    cout << endl << endl;
    }
    cout << endl;

    return 0;}
