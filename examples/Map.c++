// -------
// Map.c++
// -------

#include <algorithm> // transform
#include <cassert>   // assert
#include <iostream>  // cout, endl

template <typename T>
T sqre_1 (T x) {
    return x * x;}

template <typename T>
struct sqre_2 {
    T operator () (const T& x) const {
        return x * x;}};

template <typename T>
T cube_1 (T x) {
    return x * x * x;}

template <typename T>
struct cube_2 {
    T operator () (const T& x) const {
        return x * x * x;}};

int* transform_1 (const int* b, const int* e, int* x, int (*f) (int)) {
    while (b != e) {
        *x = f(*b);
        ++b;
        ++x;}
    return x;}

template <typename II, typename OI, typename UF>
OI transform_2 (II b, II e, OI x, UF f) {
    while (b != e) {
        *x = f(*b);
        ++b;
        ++x;}
    return x;}

int main () {
    using namespace std;
    cout << "Map.c++" << endl;

    const int a[] = {2,  3,  4};
    const int b[] = {4,  9, 16};
    const int c[] = {8, 27, 64};
    const int s   = sizeof(a) / sizeof(a[0]);

    int x[s];

    transform_1(a, a + s, x, sqre_1);
    assert(equal(x, x + s, b));
    transform_1(a, a + s, x, cube_1);
    assert(equal(x, x + s, c));

    transform_2(a, a + s, x, sqre_1<int>);
    assert(equal(x, x + s, b));
    transform_2(a, a + s, x, cube_1<int>);
    assert(equal(x, x + s, c));

    transform(a, a + s, x, sqre_1<int>);
    assert(equal(x, x + s, b));
    transform(a, a + s, x, cube_1<int>);
    assert(equal(x, x + s, c));

//  transform_1(a, a + s, x, sqre_2<int>()); // error: cannot convert 'sqre_2' to 'int (*)(int)' for argument '4' to 'int* transform_1(const int*, const int*, int*, int (*)(int))'
//  assert(equal(x, x + s, b));
//  transform_1(a, a + s, x, cube_2<int>()); // error: cannot convert 'cube_2' to 'int (*)(int)' for argument '4' to 'int* transform_1(const int*, const int*, int*, int (*)(int))'
//  assert(equal(x, x + s, c));

    transform_2(a, a + s, x, sqre_2<int>());
    assert(equal(x, x + s, b));
    transform_2(a, a + s, x, cube_2<int>());
    assert(equal(x, x + s, c));

    transform(a, a + s, x, sqre_2<int>());
    assert(equal(x, x + s, b));
    transform(a, a + s, x, cube_2<int>());
    assert(equal(x, x + s, c));

    cout << "Done." << endl;
    return 0;}
