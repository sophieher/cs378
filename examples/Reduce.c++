// ----------
// Reduce.c++
// ----------

#include <cassert>    // assert
#include <functional> // multiplies, plus
#include <iostream>   // cout, endl
#include <numeric>    // accumulate

template <typename T>
T plus_1 (T x, T y) {
    return x + y;}

template <typename T>
struct plus_2 {
    T operator () (const T& x, const T& y) const {
        return x + y;}};

template <typename T>
T multiplies_1 (T x, T y) {
    return x * y;}

template <typename T>
struct multiplies_2 {
    T operator () (const T& x, const T& y) const {
        return x * y;}};

int accumulate_1 (const int* b, const int* e, int v, int (*f) (int, int)) {
    while (b != e) {
        v = f(v, *b);
        ++b;}
    return v;}

template <typename II, typename T, typename BF>
T accumulate_2 (II b, II e, T v, BF f) {
    while (b != e) {
        v = f(v, *b);
        ++b;}
    return v;}

int main () {
    using namespace std;
    cout << "Reduce.c++" << endl;

    const int a[] = {2, 3, 4};
    const int s   = sizeof(a) / sizeof(a[0]);

    assert(accumulate_1(a, a + s, 0, plus_1)       ==  9);
    assert(accumulate_1(a, a + s, 1, multiplies_1) == 24);

    assert(accumulate_2(a, a + s, 0, plus_1<int>)       ==  9);
    assert(accumulate_2(a, a + s, 1, multiplies_1<int>) == 24);

    assert(accumulate(a, a + s, 0, plus_1<int>)       ==  9);
    assert(accumulate(a, a + s, 1, multiplies_1<int>) == 24);

//  assert(accumulate_1(a, a + s, 0, plus_2<int>())       ==  9); // error: cannot convert 'plus_2' to 'int (*)(int, int)' for argument '4' to 'int accumulate_1(const int*, const int*, int, int (*)(int, int))'
//  assert(accumulate_1(a, a + s, 1, multiplies_2<int>()) == 24); // error: cannot convert 'multiplies_2' to 'int (*)(int, int)' for argument '4' to 'int accumulate_1(const int*, const int*, int, int (*)(int, int))'

    assert(accumulate_2(a, a + s, 0, plus_2<int>())       ==  9);
    assert(accumulate_2(a, a + s, 1, multiplies_2<int>()) == 24);

    assert(accumulate(a, a + s, 0, plus_2<int>())       ==  9);
    assert(accumulate(a, a + s, 1, multiplies_2<int>()) == 24);

//  assert(accumulate_1(a, a + s, 0, plus<int>())       ==  9); // error: cannot convert 'std::plus<int>' to 'int (*)(int, int)' for argument '4' to 'int accumulate_1(const int*, const int*, int, int (*)(int, int))'
//  assert(accumulate_1(a, a + s, 1, multiplies<int>()) == 24); // error: cannot convert 'std::multiplies<int>' to 'int (*)(int, int)' for argument '4' to 'int accumulate_1(const int*, const int*, int, int (*)(int, int))'

    assert(accumulate_2(a, a + s, 0, plus<int>())       ==  9);
    assert(accumulate_2(a, a + s, 1, multiplies<int>()) == 24);

    assert(accumulate(a, a + s, 0, plus<int>())       ==  9);
    assert(accumulate(a, a + s, 1, multiplies<int>()) == 24);

    cout << "Done." << endl;
    return 0;}
