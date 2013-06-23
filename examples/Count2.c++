// ----------
// Count2.c++
// ----------

#include <algorithm> // count, count_if
#include <cassert>   // assert
#include <cstddef>   // ptrdiff_t
#include <cstring>   // strlen
#include <iostream>  // cout, endl
#include <iterator>  // iterator random_access_iterator_tag

/*
namespace std {

template <typename C, typename T, typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
struct iterator {
    typedef C iterator_category;
    typedef T value_type;
    typedef D difference_type;
    typedef P pointer;
    typedef R reference;};

} // std
*/

template <typename I>
struct my_iterator_traits : std::iterator<typename I::iterator_category, typename I::value_type, typename I::difference_type, typename I::pointer, typename I::reference> {
/*
    typedef typename I::iterator_category iterator_category;
    typedef typename I::value_type        value_type;
    typedef typename I::difference_type   difference_type;
    typedef typename I::pointer           pointer;
    typedef typename I::reference         reference;
*/
};

template <typename T>
struct my_iterator_traits<T*> : std::iterator<std::random_access_iterator_tag, T> {
/*
    typedef std::random_access_iterator_tag iterator_category;
    typedef T                               value_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef value_type*                     pointer;
    typedef value_type&                     reference;
*/
};

template <typename T>
struct my_iterator_traits<const T*> : std::iterator<std::random_access_iterator_tag, const T> {
/*
    typedef std::random_access_iterator_tag iterator_category;
    typedef const T                         value_type;
    typedef std::ptrdiff_t                  difference_type;
    typedef value_type*                     pointer;
    typedef value_type&                     reference;
*/
};

template <typename II, typename T>
typename my_iterator_traits<II>::difference_type my_count (II b, II e, const T& v) {
    typename my_iterator_traits<II>::difference_type c = 0;
    while (b != e) {
        if (*b == v)
            ++c;
        ++b;}
    return c;}

template <typename II, typename UP>
typename my_iterator_traits<II>::difference_type my_count_if (II b, II e, UP f) {
    typename my_iterator_traits<II>::difference_type c = 0;
    while (b != e) {
        if (f(*b))
            ++c;
        ++b;}
    return c;}

bool my_isupper (char c) {
    return (c >= 'A') && (c <= 'Z');}

int main () {
    using namespace std;
    cout << "Count2.c++" << endl;

    typedef bool (*UP) (char);

    const char a[] = "abCbA";
    const int  s   = strlen(a);
    const UP   p   = my_isupper;

    assert(my_count   (a, a + s, 'b')        == 2);
    assert(my_count   (a, a + s, 'd')        == 0);
    assert(my_count_if(a, a + s, my_isupper) == 2);
    assert(my_count_if(a, a + s, p)          == 2);

    assert(count   (a, a + s, 'b')        == 2);
    assert(count   (a, a + s, 'd')        == 0);
    assert(count_if(a, a + s, my_isupper) == 2);
    assert(count_if(a, a + s, p)          == 2);

    cout << "Done." << endl;
    return 0;}
