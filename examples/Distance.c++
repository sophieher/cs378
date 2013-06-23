// ------------
// Distance.c++
// ------------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <iterator> // distance, input_iterator_tag, iterator_traits, random_access_iterator_tag
#include <list>     // list
#include <vector>   // vector

/*
namespace std {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

} // std
*/

template <typename II>
typename std::iterator_traits<II>::difference_type my_distance (II b, II e, std::input_iterator_tag) {
    typename std::iterator_traits<II>::difference_type d = 0;
    while (b != e) {
        ++d;
        ++b;}
    return d;}

template <typename RI>
typename std::iterator_traits<RI>::difference_type my_distance (RI b, RI e, std::random_access_iterator_tag) {
    return e - b;}

template <typename I>
typename std::iterator_traits<I>::difference_type my_distance (I b, I e) {
    return my_distance(b, e, typename std::iterator_traits<I>::iterator_category());}

int main () {
    using namespace std;
    cout << "Distance.c++" << endl;

    {
    const int   s = 3;
    vector<int> x(s);
    assert(my_distance(x.begin(), x.end()) == s);
    }

    {
    const int s = 3;
    list<int> x(s);
    assert(my_distance(x.begin(), x.end()) == s);
    }

    {
    const int   s = 3;
    vector<int> x(s);
    assert(distance(x.begin(), x.end()) == s);
    }

    {
    const int s = 3;
    list<int> x(s);
    assert(distance(x.begin(), x.end()) == s);
    }

    cout << "Done." << endl;
    return 0;}
