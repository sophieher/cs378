// -------------------
// OStreamIterator.c++
// -------------------

#include <algorithm> // copy
#include <cassert>   // assert
#include <iostream>  // cout, endl, ostream
#include <iterator>  // iterator, ostream_iterator, output_iterator_tag
#include <sstream>   // ostringstream
#include <string>    // string, ==

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

template <typename T, typename C = char>
class my_ostream_iterator : public std::iterator<std::output_iterator_tag, void, void, void, void> {
    public:
/*
        typedef std::output_iterator_tag iterator_category;
        typedef void                     value_type;
        typedef void                     difference_type;
        typedef void                     pointer;
        typedef void                     reference;
*/

    private:
        std::ostream& _os;
        const C*      _d;

    public:
        my_ostream_iterator (std::ostream& os, const C* d = 0) :
                _os (os),
                _d  (d)
            {}

        // Default copy, destructor, and copy assignment.
        // my_ostream_iterator (const my_ostream_iterator&);
        // ~my_ostream_iterator ();
        // my_ostream_iterator& operator = (const my_ostream_iterator&);

        my_ostream_iterator& operator = (const T& v) {
            _os << v;
            if (_d)
                _os << _d;
            return *this;}

        my_ostream_iterator& operator * () {
            return *this;}

        my_ostream_iterator& operator ++ () {
            return *this;}

        my_ostream_iterator operator ++ (int) {
            return *this;}};

int main () {
    using namespace std;
    cout << "OStreamIterator.c++." << endl;

    const string s = "abCbA";

    {
    ostringstream out;
    copy(s.begin(), s.end(), my_ostream_iterator<char>(out));
    assert(out.str() == s);
    }

    {
    ostringstream out;
    copy(s.begin(), s.end(), ostream_iterator<char>(out));
    assert(out.str() == s);
    }

    cout << "Done." << endl;
    return 0;}
