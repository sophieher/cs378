/*
CS378: Quiz #10 (10 pts) <Tom>
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

struct Integer {
    int _i;

    Integer (int i) :
            _i (i)
        {}

    Integer& operator += (const Integer& rhs) {
        _i += rhs._i;
        return *this;}};

bool operator < (const Integer& lhs, const Integer& rhs) {
    return lhs._i < rhs._i;}

bool operator <= (const Integer& lhs, const Integer& rhs) {
    return !(rhs < lhs);}

Integer operator + (Integer lhs, const Integer& rhs) {
    return lhs += rhs;}

int main () {
    assert(!(Integer(2) <= Integer(1)));
    assert(  Integer(2) <= Integer(2));
    assert(  Integer(2) <= Integer(3));

    Integer x = Integer(2) + Integer(3);
    assert(x._i == 5);

    cout << "Done" << endl;
    return 0;}

/* -----------------------------------------------------------------------
1. Define the operator<=() in terms of operator<().
   (5 pts)
*/

/* -----------------------------------------------------------------------
2. Define the operator+() in terms of operator+=().
   (4 pts)
*/
