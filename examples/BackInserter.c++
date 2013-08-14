// ----------------
// BackInserter.c++
// ----------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <iterator>  // back_insert_iterator, back_inserter, iterator, output_iterator_tag
#include <string>    // string

/*
namespace std {

template <typename C, typename T, typename D = std::ptrdiff_t, typename P = T*, typename R = T&>
struct iterator {
    typedef C iterator_category;
    typedef T value_type;
    typedef D difference_type;
    typedef P pointer;
    typedef R reference;};

template <typename II, typename OI>
OI copy (II b, II e, OI x) {
    while (b != e) {
        *x = *b;
        ++b;
        ++x;}
    return x;}

} // std
*/

template <typename C>
class my_back_insert_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void> {
    public:
/*
        typedef std::output_iterator_tag iterator_category;
        typedef void                     value_type;
        typedef void                     difference_type;
        typedef void                     pointer;
        typedef void                     reference;
*/
    private:
        C& _c;

    public:
        explicit my_back_insert_iterator (C& c) :
              _c (c)
            {}

        // Default copy, destructor, and copy assignment.
        // my_back_insert_iterator (const my_back_insert_iterator&);
        // ~my_back_insert_iterator ();
        // my_back_insert_iterator& operator = (const my_back_insert_iterator&);

        my_back_insert_iterator& operator = (typename C::const_reference v) {
            _c.push_back(v);
            return *this;}

        my_back_insert_iterator& operator * () {
            return *this;}

        my_back_insert_iterator& operator ++ () {
            return *this;}

        my_back_insert_iterator operator ++ (int) {
            return *this;}};

template <typename C>
my_back_insert_iterator<C> my_back_inserter (C& x) {
    return my_back_insert_iterator<C>(x);}

int main () {
    using namespace std;
    cout << "BackInserter.c++" << endl;

    {
    const string s = "bA";
          string t = "abC";
    copy(s.begin(), s.end(), my_back_inserter(t));
    assert(t == "abCbA");
    }

    {
    const string s = "bA";
          string t = "abC";
    my_back_insert_iterator<string> x(t);
    copy(s.begin(), s.end(), x);
    assert(t == "abCbA");
    }

    {
    const string s = "bA";
          string t = "abC";
    copy(s.begin(), s.end(), back_inserter(t));
    assert(t == "abCbA");
    }

    {
    const string s = "bA";
          string t = "abC";
    back_insert_iterator<string> x(t);
    copy(s.begin(), s.end(), x);
    assert(t == "abCbA");
    }

    cout << "Done." << endl;
    return 0;}
