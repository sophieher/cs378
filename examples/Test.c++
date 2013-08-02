// ------------------------
// ReserveBackInsterter.c++
// ------------------------

#include <algorithm>  // copy
#include <cassert>    // assert
#include <ctime>      // clock, clock_t, CLOCKS_PER_SEC
#include <iostream>   // cout, endl
#include <iterator>   // back_inserter
#include <vector>     // vector

int main () {
    using namespace std;
    cout << "ReserveBackInsterter.c++" << endl;

    const vector<int>                 x(1000000, 1);
    const vector<int>::const_iterator b = x.begin();
    const vector<int>::const_iterator e = x.end();

    {
    cout << "test_1" << endl;
    const clock_t cs = clock();

    vector<int> y(distance(b, e));
    copy(b, e, y.begin());

    const clock_t ct = clock();
    const clock_t cd = ct - cs;
    cout << (cd * 1000.0 / CLOCKS_PER_SEC) << " milliseconds" << endl;
    cout << endl;
    }

    {
    cout << "test_2" << endl;
    const clock_t cs = clock();

    vector<int> y;
    y.reserve(distance(b, e));
    copy(b, e, back_inserter(y));

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
