// --------
// Find.c++
// --------

#include <algorithm> // find, find_if
#include <cassert>   // assert
#include <cstring>   // strlen
#include <iostream>  // cout, endl

const char* find_1 (const char* b, const char* e, char v) {
    while (b != e) {
        if (*b == v)
            return b;
        ++b;}
    return e;}

template <typename II, typename T>
II find_2 (II b, II e, const T& v) {
    while (b != e) {
        if (*b == v)
            return b;
        ++b;}
    return e;}

const char* find_if_1 (const char* b, const char* e, bool (*f) (char)) {
    while (b != e) {
        if (f(*b))
            return b;
        ++b;}
    return e;}

template <typename II, typename UP>
II find_if_2 (II b, II e, UP f) {
    while (b != e) {
        if (f(*b))
            return b;
        ++b;}
    return e;}

bool my_isupper (char c) {
    return (c >= 'A') && (c <= 'Z');}

int main () {
    using namespace std;
    cout << "Find.c++" << endl;

    const char a[] = "abCbA";
    const int  s   = strlen(a);

    typedef bool (*CUP) (char);
    const CUP p = my_isupper;

    assert(find(a, a + s, 'b') == a + 1);
    assert(find(a, a + s, 'd') == a + s);

    assert(find_1(a, a + s, 'b') == a + 1);
    assert(find_1(a, a + s, 'd') == a + s);

    assert(find_2(a, a + s, 'b') == a + 1);
    assert(find_2(a, a + s, 'd') == a + s);

    assert(find_if(a, a + s, my_isupper) == a + 2);
    assert(find_if(a, a + s, p)          == a + 2);

    assert(find_if_1(a, a + s, my_isupper) == a + 2);
    assert(find_if_1(a, a + s, p)          == a + 2);

    assert(find_if_2(a, a + s, my_isupper) == a + 2);
    assert(find_if_2(a, a + s, p)          == a + 2);

    cout << "Done." << endl;
    return 0;}
