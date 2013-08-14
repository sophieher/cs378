// --------------
// Functions2.c++
// --------------

#include <cassert>    // assert
#include <iostream>   // cout, endl
#include <functional> // binary_function, multiplies, plus
#include <numeric>    // accumulate, inner_product
#include <vector>     // vector

/*
namespace std {

template <typename X, typename R>
struct unary_function {
    typedef X argument_type;
    typedef R result_type;};

template <typename X, typename Y, typename R>
struct binary_function {
    typedef X first_argument_type;
    typedef Y second_argument_type;
    typedef R result_type;};

} // std
*/

int my_plus1 (int x, int y) {
    return x + y;}

template <typename T>
T my_plus2 (T x, T y) {
    return x + y;}

struct my_plus3 {
    int operator () (int x, int y) const {
        return x + y;}};

template <typename T>
struct my_plus4 {
    T operator () (const T& x, const T& y) const {
        return x + y;}};

template <typename T>
struct my_plus5 : std::binary_function<T, T, T> {
/*
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;
*/
    T operator () (const T& x, const T& y) const {
        return x + y;}};

int main () {
    using namespace std;
    cout << "Functions2.c++" << endl;

    typedef int (*FP) (int, int);

    const int a[] = {2, 3, 4};
    const int s   = sizeof(a) / sizeof(a[0]);
    assert(accumulate(a, a + s, 0)                  == 9);

    {
    assert(my_plus1(2, 3)                           == 5);
    assert(accumulate(a, a + s, 0, my_plus1)        == 9);
    const FP p = my_plus1;
    assert(p(2, 3)                                  == 5);
    assert(accumulate(a, a + s, 0, p)               == 9);
    }

    {
    assert(my_plus2(2, 3)                           == 5);
    assert(accumulate(a, a + s, 0, my_plus2<int>)   == 9);
    const FP p = my_plus2;
    assert(p(2, 3)                                  == 5);
    assert(accumulate(a, a + s, 0, p)               == 9);
    }

    {
    assert(my_plus3()(2, 3)                         == 5);
    assert(accumulate(a, a + s, 0, my_plus3())      == 9);
    my_plus3 p;
    assert(p(2, 3)                                  == 5);
    assert(accumulate(a, a + s, 0, p)               == 9);
    }

    {
    assert(my_plus4<int>()(2, 3)                    == 5);
    assert(accumulate(a, a + s, 0, my_plus4<int>()) == 9);
    my_plus4<int> p;
    assert(p(2, 3)                                  == 5);
    assert(accumulate(a, a + s, 0, p)               == 9);
    }

    {
    assert(my_plus5<int>()(2, 3)                    == 5);
    assert(accumulate(a, a + s, 0, my_plus5<int>()) == 9);
    my_plus5<int> p;
    assert(p(2, 3)                                  == 5);
    assert(accumulate(a, a + s, 0, p)               == 9);
    }

    {
    assert(plus<int>()(2, 3)                        == 5);
    assert(accumulate(a, a + s, 0, plus<int>())     == 9);
    plus<int> p;
    assert(p(2, 3)                                  == 5);
    assert(accumulate(a, a + s, 0, p)               == 9);
    }

    cout << "Done." << endl;
    return 0;}
