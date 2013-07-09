// ---------
// Pairs.c++
// ---------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <utility>  // pair

#include "Pair.h"

template <typename P1, typename P2>
void pairs (
        const typename P1::first_type&  v1,
        const typename P1::second_type& v2,
        const typename P2::first_type&  w1,
        const typename P2::second_type& w2) {

    {
    const P1 x;
    assert(x.first  == 0);
    assert(x.second == 0);
    }

    {
    const P1 x(v1, v2);
    assert( x.first  == v1);
    assert( x.second == v2);
    assert(&x.first  != &v1);
    assert(&x.second != &v2);
    }

    {
    const P1 x(v1, v2);
    const P2 y = x;
    assert(y.first  == v1);
    assert(y.second == v2);
    }

    {
    const P1 x(v1, v2);
          P2 y(w1, w2);
    y = x;
    assert(y.first  == v1);
    assert(y.second == v2);
    }

    {
    assert(my_make_pair(v1, v2).first  == v1);
    assert(my_make_pair(v1, v2).second == v2);
    }}

int main () {
    using namespace std;
    cout << "Pairs.c++" << endl;

    pairs<    pair<int, int>,    pair<double, double> >(2, 3, 4.5, 6.7);
    pairs< my_pair<int, int>, my_pair<double, double> >(2, 3, 4.5, 6.7);

    int i = 2;
    int j = 3;
//  pair<int&, int&> p(i, j); // error: forming reference to reference type 'int&'

    cout << "Done." << endl;
    return 0;}
