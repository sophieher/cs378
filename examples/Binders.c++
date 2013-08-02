// -----------
// Binders.c++
// -----------

#include <algorithm>  // equal, transform
#include <cassert>    // assert
#include <functional> // binary_function, bind2nd, binder2nd, plus, unary_function
#include <iostream>   // cout, endl

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

template <typename BF>
class my_binder2nd : public std::unary_function<typename BF::first_argument_type, typename BF::result_type> {
/*
    public:
        typedef typename BF::first_argument_type argument_type;
        typedef typename BF::result_type         result_type;
*/
    private:
        BF                                _f;
        typename BF::second_argument_type _y;

    public:
        my_binder2nd (BF f, const typename BF::second_argument_type& y) :
               _f (f),
               _y (y)
           {}

        typename BF::result_type operator () (const typename BF::first_argument_type& x) const {
            return _f(x, _y);}};

template <typename BF, typename T>
my_binder2nd<BF> my_bind2nd (BF f, const T& y) {
    return my_binder2nd<BF>(f, typename BF::second_argument_type(y));}

template <typename T>
struct my_plus : std::binary_function<T, T, T> {
/*
    typedef T first_argument_type;
    typedef T second_argument_type;
    typedef T result_type;
*/
    T operator () (const T& x, const T& y) const {
        return x + y;}};

int main () {
    using namespace std;
    cout << "Binders.c++" << endl;

    const int a[] = {2, 3, 4};
    const int b[] = {4, 5, 6};
    const int s   = sizeof(a) / sizeof(a[0]);

    {
    assert(   plus<int>()(2, 3) == 5);
    assert(my_plus<int>()(2, 3) == 5);
    }

    {
    int x[s];
    transform(a, a + s, x, bind2nd(plus<int>(), 2));
    assert(equal(x, x + s, b));
    plus<int> p;
    binder2nd< plus<int> > q(p, 2);
    transform(a, a + s, x, q);
    assert(equal(x, x + s, b));
    }

    {
    int x[s];
    transform(a, a + s, x, bind2nd(my_plus<int>(), 2));
    assert(equal(x, x + s, b));
    my_plus<int> p;
    binder2nd< my_plus<int> > q(p, 2);
    transform(a, a + s, x, q);
    assert(equal(x, x + s, b));
    }

    {
    int x[s];
    transform(a, a + s, x, my_bind2nd(plus<int>(), 2));
    assert(equal(x, x + s, b));
    plus<int> p;
    my_binder2nd< plus<int> > q(p, 2);
    transform(a, a + s, x, q);
    assert(equal(x, x + s, b));
    }

    {
    int x[s];
    transform(a, a + s, x, my_bind2nd(my_plus<int>(), 2));
    assert(equal(x, x + s, b));
    my_plus<int> p;
    my_binder2nd< my_plus<int> > q(p, 2);
    transform(a, a + s, x, q);
    assert(equal(x, x + s, b));
    }

    cout << "Done." << endl;
    return 0;}
