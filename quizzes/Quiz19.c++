/*
CS378: Quiz #19 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
 1. Which of the following are well-defined and which are not?
    (9 pts)

    well-defined: b, c, e
not well-defined: a, d
*/

template <typename II, typename T, typename UF, typename BF>
T map_reduce_a (II b, II e, T v, UF f, BF g) {
    vector<T> x;
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_b (II b, II e, T v, UF f, BF g) {
    vector<T> x(distance(b, e));
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_c (II b, II e, T v, UF f, BF g) {
    vector<T> x(b, e);
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_d (II b, II e, T v, UF f, BF g) {
    vector<T> x;
    x.reserve(distance(b, e));
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}

template <typename II, typename T, typename UF, typename BF>
T map_reduce_d (II b, II e, T v, UF f, BF g) {
    vector<T> x;
    x.resize(distance(b, e));
    transform(b, e, x.begin(), f);
    return accumulate(x.begin(), x.end(), v, g);}
