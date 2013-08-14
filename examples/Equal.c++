// ---------
// Equal.c++
// ---------

#include <algorithm> // equal
#include <cassert>   // assert
#include <list>      // list
#include <iostream>  // cout, endl

bool equal_1 (int* b, int* e, int* c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

template <typename II1, typename II2>
bool equal_2 (II1 b, II1 e, II2 c) {
    while (b != e) {
        if (*b != *c)
            return false;
        ++b;
        ++c;}
    return true;}

int main () {
    using namespace std;
    cout << "Equal.c++" << endl;

    int a[] = {2, 3, 4};
    int b[] = {2, 3, 4, 5};

    assert(equal_1(a, a + 3, b));
    assert(equal_2(a, a + 3, b));
    assert(equal  (a, a + 3, b));

    list<int> x(a, a + 3);
    list<int> y(b, b + 4);

    assert(equal  (x.begin(), x.end(), y.begin()));
//  assert(equal_1(x.begin(), x.end(), y.begin())); // error: cannot convert ‘std::_List_iterator<int>’ to ‘int*’ for argument ‘1’ to ‘bool equal_1(int*, int*, int*)’
    assert(equal_2(x.begin(), x.end(), y.begin()));

    cout << "Done." << endl;
    return 0;}
