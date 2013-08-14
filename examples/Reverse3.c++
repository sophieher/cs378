// ------------
// Reverse3.c++
// ------------

#include <algorithm> // reverse, swap
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // bidirectional_iterator_tag iterator_traits random_access_iterator_tag
#include <list>      // list, ==
#include <vector>    // vector, ==

/*
namespace std {

struct input_iterator_tag {};
struct output_iterator_tag {};
struct forward_iterator_tag : input_iterator_tag {};
struct bidirectional_iterator_tag : forward_iterator_tag {};
struct random_access_iterator_tag : bidirectional_iterator_tag {};

} // std
*/

template <typename BI>
void my_reverse (BI b, BI e, std::bidirectional_iterator_tag) {
    while ((b != e) && (b != --e)) {
        std::swap(*b, *e);
        ++b;}}

template <typename RI>
void my_reverse (RI b, RI e, std::random_access_iterator_tag) {
    --e;
    while (b < e) {
        std::swap(*b, *e);
        ++b;
        --e;}}

template <typename I>
void my_reverse (I b, I e) {
    my_reverse(b, e, typename std::iterator_traits<I>::iterator_category());}

int main () {
    using namespace std;
    cout << "Reverse3.c++" << endl;

    {
    char a[] = "abcde";
    vector<char> x(a, a + 5);
    char b[] = "edcba";
    vector<char> y(b, b + 5);
    my_reverse(x.begin(), x.end());
    assert(x == y);
    }

    {
    char a[] = "abcde";
    list<char> x(a, a + 5);
    char b[] = "edcba";
    list<char> y(b, b + 5);
    my_reverse(x.begin(), x.end());
    assert(x == y);
    }

    {
    char a[] = "abcde";
    vector<char> x(a, a + 5);
    char b[] = "edcba";
    vector<char> y(b, b + 5);
    reverse(x.begin(), x.end());
    assert(x == y);
    }

    {
    char a[] = "abcde";
    list<char> x(a, a + 5);
    char b[] = "edcba";
    list<char> y(b, b + 5);
    reverse(x.begin(), x.end());
    assert(x == y);
    }

    cout << "Done." << endl;
    return 0;}
