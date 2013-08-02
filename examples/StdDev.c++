// ----------
// StdDev.c++
// ----------

#include <algorithm>  // distance, transform
#include <cassert>    // assert
#include <cmath>      // sqrt
#include <functional> // bind2nd, minus, unary_function
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <vector>     // vector

template <typename II, typename T>
T mean (II b, II e, T v) {
    v = std::accumulate(b, e, v);
    if (v == 0)
        return 0;
    return v / std::distance(b, e);}

template <typename T>
struct sqre : std::unary_function<T, T> {
    T operator () (const T& v) {
        return v * v;}};

// square root of the mean of the squares of the differences with the mean
template <typename II, typename T>
T std_dev_1 (II b, II e, T v) {
    std::vector<T> x(std::distance(b, e));
    std::transform(b, e, x.begin(), std::bind2nd(std::minus<int>(), mean(b, e, v)));
    std::transform(x.begin(), x.end(), x.begin(), sqre<int>());
    T msdm = mean(x.begin(), x.end(), v);
    return sqrt(msdm);}

// square root of the mean of the squares minus the square of the mean
template <typename II, typename T>
T std_dev_2 (II b, II e, T v) {
    std::vector<T> x(std::distance(b, e));
    std::transform(b, e, x.begin(), sqre<int>());
    T ms = mean(x.begin(), x.end(), v);
    T sm = sqre<T>()(mean(b, e, v));
    return std::sqrt(ms - sm);}

int main () {
    using namespace std;
    cout << "StdDev.c++" << endl;

    int a[] = {2, 3, 4};

    assert(std_dev_1(a, a,     0.0) == sqrt(0.0));
    assert(std_dev_1(a, a + 1, 0.0) == sqrt(0.0));
    assert(std_dev_1(a, a + 2, 0.0) == sqrt((0.5 + 0.5)       / 2));
    assert(std_dev_1(a, a + 3, 0.0) == sqrt((1.0 + 0.0 + 1.0) / 3));

    assert(std_dev_2(a, a,     0.0) == sqrt(0.0));
    assert(std_dev_2(a, a + 1, 0.0) == sqrt(0.0));
    assert(std_dev_2(a, a + 2, 0.0) == sqrt((13.0 / 2) - 6.25));
    assert(std_dev_2(a, a + 3, 0.0) == sqrt((29.0 / 3) - 9.0));

    cout << "Done." << endl;
    return 0;}
