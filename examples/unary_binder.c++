
// ---------------- 
// unary_binder.c++ 
// ---------------- 

#include <algorithm> //distance, transform
#include <cassert>   // assert
#include <cmath> 	 // sqrt
#include <functional> // bind2nd, minus, unary_function
#include <iostream>   // cout, endl
#include <numeric>    // accumulate
#include <vector>     // vector

#include "StdDev.h"


/*
create a binder to bind two unary functions and return a result of the second unary function
in this particular instance of standard deviation, we attempt to combine the result of 
std::bind2nd(...) with sqre<int>(), to complete only one pass of std::transform()

// square root of the mean of the squares of the differences with the mean
template <typename II, typename T>
T std_dev_1 (II b, II e, T v) {
    std::vector<T> x(std::distance(b, e));
    std::transform(b, e, x.begin(), std::bind2nd(std::minus<int>(), mean(b, e, v)));
    std::transform(x.begin(), x.end(), x.begin(), sqre<int>());
    T msdm = mean(x.begin(), x.end(), v);
    return sqrt(msdm);}
*/

template <typename UF1, typename UF2>
class unary_binder : std::unary_function<typename UF1::argument_type, typename UF2::result_type> {

	private:
		// hold on to both functions
		UF1								_f1;
		UF2								_f2;


	public:
		unary_binder (UF1 f1, UF2 f2) :
			_f1(f1), 
			_f2(f2)
			{}

		typename UF2::result_type operator () (typename UF1::argument_type x)  {
			typename UF1::result_type y = _f1(x);
			_f2(y);
		}

};

template<typename UF1, typename UF2>
unary_binder<UF1, UF2> unary_bind (UF1 f1, UF2 f2) {
	return unary_binder<UF1, UF2>(f1, f2);
}


template <typename II, typename T>
T std_dev (II b, II e, T v) {
	std::vector<T> x;
	x.reserve(std::distance(b, e));
	std::transform(b, e, back_inserter(x), unary_bind( ( std::bind2nd(std::minus<int>(), mean(b, e, v)) ), sqre<int>()) );
	T msdm = mean(x.begin(), x.end(), v);
	return sqrt(msdm);
}

int main () {
    using namespace std;
    cout << "unary_binder.c++" << endl;

    int a[] = {2, 3, 4};

    assert(std_dev(a, a,     0.0) == sqrt(0.0));
    assert(std_dev(a, a + 1, 0.0) == sqrt(0.0));
    assert(std_dev(a, a + 2, 0.0) == sqrt((0.5 + 0.5)       / 2));
    assert(std_dev(a, a + 3, 0.0) == sqrt((1.0 + 0.0 + 1.0) / 3));
    
    cout << "Done." << endl;
    return 0;}