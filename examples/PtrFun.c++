// ----------
// PtrFun.c++
// ----------

#include <algorithm>  // equal, transform
#include <cassert>    // assert
#include <functional> // bind2nd, binary_function, pointer_to_binary_function, ptr_fun
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

template <typename X, typename Y, typename R>
class my_pointer_to_binary_function : public std::binary_function<X, Y, R> {
/*
    public:
        typedef X first_argument_type;
        typedef Y second_argument_type;
        typedef R result_type;
*/
    private:
        R (*_f)(X, Y);

    public:
        explicit my_pointer_to_binary_function (R (*f)(X, Y)) :
                _f (f)
            {}

        R operator () (const X&  x, const Y& y) const {
            return _f(x, y);}};

template <typename X, typename Y, typename R>
my_pointer_to_binary_function<X, Y, R> my_ptr_fun (R (*f)(X, Y)) {
    return my_pointer_to_binary_function<X, Y, R>(f);}

int my_plus1 (int x, int y) {
    return x + y;}

template <typename T>
T my_plus2 (T x, T y) {
    return x + y;}

int main () {
    using namespace std;
    cout << "PtrFun.c++" << endl;

    typedef int (*FP) (int, int);

    const int a[] = {2, 3, 4};
    const int b[] = {4, 5, 6};
    const int s   = sizeof(a) / sizeof(a[0]);

    {
    assert(my_plus1(2, 3) == 5);
    assert(my_plus2(2, 3) == 5);
    }

    {
    assert(ptr_fun(my_plus1)     (2, 3) == 5);
    assert(ptr_fun(my_plus2<int>)(2, 3) == 5);
    }

    {
    int x[s];
    transform(a, a + s, x, bind2nd(ptr_fun(my_plus1), 2));
    assert(equal(x, x + s, b));
    FP p = my_plus1;
    pointer_to_binary_function<int, int, int> q(p);
    binder2nd< pointer_to_binary_function<int, int, int> > r(q, 2);
    transform(a, a + s, x, r);
    assert(equal(x, x + s, b));
    }

    {
    int x[s];
    transform(a, a + s, x, bind2nd(ptr_fun(my_plus2<int>), 2));
    assert(equal(x, x + s, b));
    FP p = my_plus2;
    pointer_to_binary_function<int, int, int> q(p);
    binder2nd< pointer_to_binary_function<int, int, int> > r(q, 2);
    transform(a, a + s, x, r);
    assert(equal(x, x + s, b));
    }

    {
    int x[s];
    transform(a, a + s, x, bind2nd(my_ptr_fun(my_plus1), 2));
    assert(equal(x, x + s, b));
    FP p = my_plus1;
    my_pointer_to_binary_function<int, int, int> q(p);
    binder2nd< my_pointer_to_binary_function<int, int, int> > r(q, 2);
    transform(a, a + s, x, r);
    assert(equal(x, x + s, b));
    }

    {
    int x[s];
    transform(a, a + s, x, bind2nd(my_ptr_fun(my_plus2<int>), 2));
    assert(equal(x, x + s, b));
    FP p = my_plus2;
    my_pointer_to_binary_function<int, int, int> q(p);
    binder2nd< my_pointer_to_binary_function<int, int, int> > r(q, 2);
    transform(a, a + s, x, r);
    assert(equal(x, x + s, b));
    }

    cout << "Done." << endl;
    return 0;}
