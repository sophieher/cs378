// ----------
// Vector1.c++
// ----------

#include <cstddef>   // size_t
#include <iostream>  // cout, endl
#include <memory>    // allocator

#include "Memory.h"  // my_destroy, my_uninitialized_fill

template <typename T, typename A = std::allocator<T> >
class my_vector {
    private:
        A                 _x;
        const std::size_t _s;
        T*    const       _a;

    public:
        my_vector (std::size_t s = 0, const T& v = T(), const A& x = A()) :
                _x (x),
                _s (s),
                _a (_x.allocate(s)) {
            my_uninitialized_fill(_x, _a, _a + _s, v);}

        ~my_vector () {
            my_destroy(_x, _a, _a + _s);
            _x.deallocate(_a, _s);}};

int main () {
    using namespace std;
    cout << "Vector1.c++" << endl;

    {
    my_vector<int> x;
    my_vector<int> y(10);
    my_vector<int> z(10, 2);
    }

    {
    my_vector<int, allocator<int> > x;
    my_vector<int, allocator<int> > y(10);
    my_vector<int, allocator<int> > z(10, 2);
    }

    cout << "Done." << endl;
    return 0;}
