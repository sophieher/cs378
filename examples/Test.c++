// --------
// Test.c++
// --------

#include <algorithm> // swap
#include <cassert>   // assert
#include <iostream>  // cout, endl

template <typename RI>
bool palindrome (RI b, RI e) {
    --e;
    while (b < e) {
        if (*b != *e)
            return false;
        ++b;
        --e;}
    return true;}

int main () {
    using namespace std;
    cout << "Test.c++" << endl;

    const char a[] = "radar";

    assert( palindrome(a, a));      // ""
    assert( palindrome(a, a + 1));  // "r"
    assert(!palindrome(a, a + 2));  // "ra"
    assert(!palindrome(a, a + 3));  // "rad"
    assert(!palindrome(a, a + 4));  // "rada"
    assert( palindrome(a, a + 5));  // "radar"

    cout << "Done." << endl;
    return 0;}
