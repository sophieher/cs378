
// -------- 
// StdDev.h 
// -------- 



// -------- 
// includes 
// -------- 

#include <algorithm> //distance, transform
#include <cassert>   // assert
#include <cmath> 	 // sqrt
#include <functional>
#include <iostream>
#include <numeric>    // accumulate

 
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