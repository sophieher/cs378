/*
CS378: Quiz #15 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

1 1
2 1
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

struct A {
    int i;

    struct B {
        A*  q;
        int j;

        B (A* p) {q = p; j = 0;}
        void g () {++q->i; ++j;}};

    A () {i = 0;}
    B f () {return B(this);}};

int main () {
    A x;

    A::B y = x.f();
    y.g();
    cout << x.i << " ";
    cout << y.j << endl;

    y = x.f();
    y.g();
    cout << x.i << " ";
    cout << y.j << endl;

    return 0;}
