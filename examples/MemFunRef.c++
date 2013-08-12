// -------------
// MemFunRef.c++
// -------------

#include <algorithm>  // equal, transform
#include <cassert>    // assert
#include <functional> // bind2nd, binary_function, const_mem_fun1_ref_t, mem_fun1_ref_t, mem_fun_ref
#include <iostream>   // cout, endl

/*
namespace std {

template <typename X, typename Y, typename R>
struct binary_function {
    typedef X first_argument_type;
    typedef Y second_argument_type;
    typedef R result_type;};

} // std
*/

template <typename R, typename T, typename A>
class my_mem_fun1_ref_t : public std::binary_function<T, A, R> {
/*
    public:
        typedef T first_argument_type;
        typedef A second_argument_type;
        typedef R result_type;
*/
    private:
        R (T::*_m)(A);

    public:
        explicit my_mem_fun1_ref_t (R (T::*m)(A)) :
                _m (m)
            {}

        R operator () (T& x, A y) const {
            return (x.*_m)(y);}};

template <typename R, typename T, typename A>
my_mem_fun1_ref_t<R, T, A> my_mem_fun_ref (R (T::*m)(A)) {
    return my_mem_fun1_ref_t<R, T, A>(m);}

template <typename R, typename T, typename A>
class my_const_mem_fun1_ref_t : public std::binary_function<T, A, R> {
/*
    public:
        typedef T first_argument_type;
        typedef A second_argument_type;
        typedef R result_type;
*/
    private:
        R (T::*_m)(A) const;

    public:
        explicit my_const_mem_fun1_ref_t (R (T::*m)(A) const) :
                _m (m)
            {}

        R operator () (const T& x, A y) const {
            return (x.*_m)(y);}};

template <typename R, typename T, typename A>
my_const_mem_fun1_ref_t<R, T, A> my_mem_fun_ref (R (T::*m)(A) const) {
    return my_const_mem_fun1_ref_t<R, T, A>(m);}

template <typename T>
class A {
    public:
        T v;

    public:
        A (const T& v = 0) :
                v (v)
            {}

        bool operator == (const A& that) const {
            return v == that.v;}

        A plus (A that) const {
            return v + that.v;}};

int main () {
    using namespace std;
    cout << "MemFunRef.c++" << endl;

    typedef A<int> (A<int>::*MP) (A<int>) const;

    const A<int> a[] = {2, 3, 4};
    const A<int> b[] = {4, 5, 6};
    const int    s   = sizeof(a) / sizeof(a[0]);

    {
    assert(A<int>(2).plus(3) == 5);
    }

    {
    assert(mem_fun_ref(&A<int>::plus)(2, 3) == 5);
    }

    {
    A<int> x[s];
    transform(a, a + s, x, bind2nd(mem_fun_ref(&A<int>::plus), 2));
    assert(equal(x, x + s, b));
    MP p = &A<int>::plus;
    const_mem_fun1_ref_t< A<int>, A<int>, A<int> > q(p);
    binder2nd< const_mem_fun1_ref_t< A<int>, A<int>, A<int> > > r(q, 2);
    transform(a, a + s, x, r);
    assert(equal(x, x + s, b));
    }

    {
    A<int> x[s];
    transform(a, a + s, x, bind2nd(my_mem_fun_ref(&A<int>::plus), 2));
    assert(equal(x, x + s, b));
    MP p = &A<int>::plus;
    my_const_mem_fun1_ref_t< A<int>, A<int>, A<int> > q(p);
    binder2nd< my_const_mem_fun1_ref_t< A<int>, A<int>, A<int> > > r(q, 2);
    transform(a, a + s, x, r);
    assert(equal(x, x + s, b));
    }

    cout << "Done." << endl;
    return 0;}
