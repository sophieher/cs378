// ----------------
// ArrayObjects.c++
// ----------------

#include <algorithm> // copy, equal, fill, lexicographical_compare
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t, size_t
#include <cstring>   // strcmp
#include <iostream>  // cout, endl
#include <memory>    // allocator
#include <stdexcept> // out_of_range

#include "ArrayObject1.h" // ArrayObject1
#include "ArrayObject2.h" // ArrayObject2
#include "ArrayObject3.h" // ArrayObject3

template <typename T, typename U>
void array_objects (
        const typename T::value_type& v1,
        const typename T::value_type& v2,
        const typename T::value_type& v3,
        const typename U::value_type& w) {

    {
    const T x;
    assert(x.size() == 3);
    const int a[] = {0, 0, 0};
    assert(std::equal(x.begin(), x.end(), a) == true);
    }

    {
    const T x(v1);
    assert(x.size() == 3);
    const int a[] = {v1, v1, v1};
    assert(std::equal(x.begin(), x.end(), a) == true);
    }

    {
    const int         a[] = {v1, v2, v3};
    const int         s   = sizeof(a) / sizeof(a[0]);
    const T x(a, a + s);
    assert(std::equal(x.begin(), x.end(), a) == true);
    }

    {
    const int         a[] = {v1, v2, v3};
    const int         s   = sizeof(a) / sizeof(a[0]);
    const T x(a, a + s);
    assert(x[1] == v2);
//  assert(x[3] == v3);
    try {
        assert(x.at(3) == v3);}
    catch (const std::out_of_range& e) {
        assert(strcmp(e.what(), "Array::at index out of range") == 0);}
    }

    {
    const T x(v1);
          T y = x;
    assert(x == y);
    y[1] = v2;
    assert(x[1] == v1);
    assert(y[1] == v2);
    }

    {
    const T x(v1);
          T y(v2);
    y = x;
    assert(x == y);
    y[1] = v2;
    assert(x[1] == v1);
    assert(y[1] == v2);
    }

    {
    const T x(v1);
          U y(w);
    std::copy(x.begin(), x.end(), y.begin());
    assert(std::equal(x.begin(), x.end(), y.begin()) == true);
    }

    {
    const T x(v1);
    const T y(v1);
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }}

int main () {
    using namespace std;
    cout << "ArrayObjects.c++" << endl;

    array_objects< ArrayObject1<int, 3>, ArrayObject1<double, 5> >(2, 3, 4, 5.6);
    array_objects< ArrayObject2<int, 3>, ArrayObject2<double, 5> >(2, 3, 4, 5.6);
    array_objects< ArrayObject3<int, 3>, ArrayObject3<double, 5> >(2, 3, 4, 5.6);

    cout << "Done." << endl;
    return 0;}
