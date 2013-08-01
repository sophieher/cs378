// -------------
// MapReduce.c++
// -------------

#include <algorithm>  // transform
#include <cassert>    // assert
#include <ctime>      // clock, clock_t, CLOCKS_PER_SEC
#include <functional> // multiplies, plus
#include <iostream>   // cout, endl
#include <iterator>   // back_inserter
#include <numeric>    // accumulate
#include <vector>     // vector

template <typename T>
struct sqre {
    T operator () (const T& x) const {
        return x * x;}};

template <typename T>
struct cube {
    T operator () (const T& x) const {
        return x * x * x;}};

template <typename II, typename T, typename UF, typename BF>
T map_reduce_1 (II b, II e, T v, UF f, BF g) {
    while (b != e) {
        v = g(v, f(*b));
        ++b;}
    return v;}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_2 (II b, II e, T v, UF f, BF g) {
    std::vector<T> x(std::distance(b, e));
    std::transform(b, e, x.begin(), f);
    return std::accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_3 (II b, II e, T v, UF f, BF g) {
    std::vector<T> x;
    x.reserve(std::distance(b, e));
    std::transform(b, e, std::back_inserter(x), f);
    return std::accumulate(x.begin(), x.end(), v, g);}

int main () {
    using namespace std;
    cout << "MapReduce.c++" << endl;

    {
    const int a[] = {2, 3, 4};
    const int s   = sizeof(a) / sizeof(a[0]);

    assert(map_reduce_1(a, a + s, 0, sqre<int>(), plus<int>())       ==    29);
    assert(map_reduce_1(a, a + s, 0, cube<int>(), plus<int>())       ==    99);
    assert(map_reduce_1(a, a + s, 1, sqre<int>(), multiplies<int>()) ==   576);
    assert(map_reduce_1(a, a + s, 1, cube<int>(), multiplies<int>()) == 13824);

    assert(map_reduce_2(a, a + s, 0, sqre<int>(), plus<int>())       ==    29);
    assert(map_reduce_2(a, a + s, 0, cube<int>(), plus<int>())       ==    99);
    assert(map_reduce_2(a, a + s, 1, sqre<int>(), multiplies<int>()) ==   576);
    assert(map_reduce_2(a, a + s, 1, cube<int>(), multiplies<int>()) == 13824);

    assert(map_reduce_3(a, a + s, 0, sqre<int>(), plus<int>())       ==    29);
    assert(map_reduce_3(a, a + s, 0, cube<int>(), plus<int>())       ==    99);
    assert(map_reduce_3(a, a + s, 1, sqre<int>(), multiplies<int>()) ==   576);
    assert(map_reduce_3(a, a + s, 1, cube<int>(), multiplies<int>()) == 13824);
    }

    const int         s = 1000000;
    const int         v = 1;
    const vector<int> x(s, v);
    cout << endl;

    {
    cout << "map_reduce_1" << endl;
    const clock_t cs = clock();

    assert(map_reduce_1(x.begin(), x.end(), 0, sqre<int>(), plus<int>())       == s);
    assert(map_reduce_1(x.begin(), x.end(), 0, cube<int>(), plus<int>())       == s);
    assert(map_reduce_1(x.begin(), x.end(), 1, sqre<int>(), multiplies<int>()) == v);
    assert(map_reduce_1(x.begin(), x.end(), 1, cube<int>(), multiplies<int>()) == v);

    const clock_t ct = clock();
    const clock_t cd = ct - cs;
    cout << (cd * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;
    }

    {
    cout << "map_reduce_2" << endl;
    const clock_t cs = clock();

    assert(map_reduce_2(x.begin(), x.end(), 0, sqre<int>(), plus<int>())       == s);
    assert(map_reduce_2(x.begin(), x.end(), 0, cube<int>(), plus<int>())       == s);
    assert(map_reduce_2(x.begin(), x.end(), 1, sqre<int>(), multiplies<int>()) == v);
    assert(map_reduce_2(x.begin(), x.end(), 1, cube<int>(), multiplies<int>()) == v);

    const clock_t ct = clock();
    const clock_t cd = ct - cs;
    cout << (cd * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;
    }

    {
    cout << "map_reduce_3" << endl;
    const clock_t cs = clock();

    assert(map_reduce_3(x.begin(), x.end(), 0, sqre<int>(), plus<int>())       == s);
    assert(map_reduce_3(x.begin(), x.end(), 0, cube<int>(), plus<int>())       == s);
    assert(map_reduce_3(x.begin(), x.end(), 1, sqre<int>(), multiplies<int>()) == v);
    assert(map_reduce_3(x.begin(), x.end(), 1, cube<int>(), multiplies<int>()) == v);

    const clock_t ct = clock();
    const clock_t cd = ct - cs;
    cout << (cd * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;
    }

    cout << "Done." << endl;
    return 0;}

/*
Target: i686-apple-darwin11
gcc version 4.2.1 (Based on Apple Inc. build 5658) (LLVM build 2336.11.00)

MapReduce.c++

map_reduce_1
137.156 milliseconds

map_reduce_2
277.218 milliseconds

map_reduce_3
349.918 milliseconds

Done.
*/
