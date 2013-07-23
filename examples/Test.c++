// ---------
// David.c++
// ---------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <list>     // list

struct mammal         {};
struct tiger : mammal {};

int main () {
    using namespace std;
    cout << "Test.c++" << endl;

    // The quick, but somewhat obtuse, answer to your question is that
    // containers in C++ are not covariant.

    // That is, if tiger is a child of mammal, that does NOT make list<tiger>
    // a child of list<mammal>.

    // This is legal, because tiger is a child of mammal.
    tiger   x;
    mammal* p = &x;

    // This is not legal, because list<tiger> is NOT a child of list<mammal>;
    list<tiger>   y;
//  list<mammal>* q = &y; // error: cannot convert ‘std::list<tiger>*’ to
                          // ‘std::list<mammal>*’ in initialization

    // Casting makes it compile, but it's not reasonable.
    list<mammal>* q = (list<mammal>*)(&y);

    // Why is it not reasonable?

    // Consider the following attempt to add a tiger to a list<tiger>.
    // That's reasonable.
    list<tiger> z;
    z.push_back(tiger());

    // Now consider the following attempt to add a mammal to a list<tiger>.
    // That's NOT reasonable.
//  z.push_back(mammal()); // error: no matching function for call to
                           // ‘std::list<tiger>::push_back(mammal)’

    // It's not reasonable, because list<tiger> contains only tigers.
    // And we're trying to add a mammal.
    // All mammals are not tigers.

    // The reason your original code doesn't compile, is to prevent this mistake.
    // If you force the issue with a cast, it will compile, but list<tiger> will still
    // only contain tigers, and you'll then be forcing it to accepts mammals.
    q->push_back(mammal());

    // Really, what you've facilitated is this, which doesn't compile.
    mammal m;
//  tiger  t = m; // error: conversion from ‘mammal’ to non-scalar type ‘tiger’ requested

    cout << "Done." << endl;
    return 0;}
