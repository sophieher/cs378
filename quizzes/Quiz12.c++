/*
CS378: Quiz #12 (9 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

4
8
4
*/

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <memory>   // allocator

using namespace std;

int main () {
    assert(sizeof(int)    == 4);
    assert(sizeof(double) == 8);

    allocator<int> x;
    cout << sizeof(*x.allocate(1)) << endl;

    allocator<int>::rebind<double>::other y;
    cout << sizeof(*y.allocate(1)) << endl;

    allocator<double>::rebind<int>::other z;
    cout << sizeof(*z.allocate(1)) << endl;

    return 0;}
