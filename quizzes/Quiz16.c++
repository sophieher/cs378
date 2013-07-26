/*
CS378: Quiz #16 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
 1. How many times does the function g() get instantiated in the
    following?
    And for each time, specify the value of BF.
    (9 pts)

int (*) (int, int)
plus_2<int>
multiplies_2<int>
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename BF, typename T>
T g (BF f, const T& x, const T& y, const T& z) {
    return f(f(x, y), z);}

template <typename T>
T plus_1 (T x, T y) {
    return x + y;}

template <typename T>
T multiplies_1 (T x, T y) {
    return x * y;}

template <typename T>
struct plus_2 {
    T operator () (const T& x, const T& y) const {
        return x + y;}};

template <typename T>
struct multiplies_2 {
    T operator () (const T& x, const T& y) const {
        return x * y;}};

int main () {
    assert(g(plus_1<int>,       2, 3, 4) ==  9);
    assert(g(multiplies_1<int>, 2, 3, 4) == 24);

    assert(g(plus_2<int>(),       2, 3, 4) ==  9);
    assert(g(multiplies_2<int>(), 2, 3, 4) == 24);

    cout << "Done." << endl;
    return 0;}
