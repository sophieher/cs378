// -------------------
// IStreamIterator.c++
// -------------------

#include <algorithm> // copy,
#include <cassert>   // assert
#include <iostream>  // cout, endl, istream
#include <iterator>  // input_iterator_tag, istream_iterator, iterator
#include <sstream>   // istringstream
#include <string>    // string
#include <utility>   // !=, <=, >, >=

//using namespace std::rel_ops;   // doesn't compile
  using std::rel_ops::operator!=;

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

template <typename T>
class my_istream_iterator : public std::iterator<std::input_iterator_tag, T, std::ptrdiff_t , T*, T&> {
    public:
/*
        typedef std::input_iterator_tag iterator_category;
        typedef T                       value_type;
        typedef std::ptrdiff_t          difference_type;
        typedef T*                      pointer;
        typedef T&                      reference;
*/
        friend bool operator == (const my_istream_iterator& lhs, const my_istream_iterator& rhs) {
            return (lhs._is == rhs._is);}

    private:
        std::istream* _is;
        T             _v;

    public:
        my_istream_iterator () :
                _is (0),
                _v  ()
            {}

        my_istream_iterator (std::istream& is) :
                _is (&is),
                _v  () {
            ++*this;}

        // Default copy, destructor, and copy assignment.
        // my_istream_iterator (const my_istream_iterator&);
        // ~my_istream_iterator ();
        // my_istream_iterator& operator = (const my_istream_iterator&);

        const T& operator * () const {
            return _v;}

        my_istream_iterator& operator ++ () {
            if (_is && !(*_is >> _v))
                _is = 0;
            return *this;}

        my_istream_iterator operator ++ (int) {
            my_istream_iterator x = *this;
            ++*this;
            return x;}};

int main () {
    using namespace std;
    cout << "IStreamIterator.c++." << endl;

    {
    const string        s("abCbA");
          istringstream in(s);
          string        t("xxxxx");
    copy(my_istream_iterator<char>(in), my_istream_iterator<char>(), t.begin());
    assert(t == s);
    }

    {
    const string        s("abCbA");
          istringstream in(s);
          string        t("xxxxx");
    copy(istream_iterator<char>(in), istream_iterator<char>(), t.begin());
    assert(t == s);
    }

    {
    int f (int);
    int g (int x);
    int h (int (x));     // legal!
//  int q ((int x));     // can NOT parenthesize
    }

    {
    int f (int (*p) ());
    int g (int p ());
    int h (int ());      // legal!
    }

    {
    istringstream in("abCbA");
//  string s(my_istream_iterator<char>(in),   my_istream_iterator<char>());
//  string s(my_istream_iterator<char> in,    my_istream_iterator<char> (*) ());
    string s((my_istream_iterator<char>(in)), my_istream_iterator<char>());
    assert(s == "abCbA");
    }

    {
    istringstream in("abCbA");
//  string s(istream_iterator<char>(in),   istream_iterator<char>());
//  string s(istream_iterator<char> in,    istream_iterator<char> (*) ());
    string s((istream_iterator<char>(in)), istream_iterator<char>());
    assert(s == "abCbA");
    }

    {
    istringstream in("abCbA");
    my_istream_iterator<char> b(in);
    my_istream_iterator<char> e;
    string s(b, e);
    assert(s == "abCbA");
    }

    {
    istringstream in("abCbA");
    istream_iterator<char> b(in);
    istream_iterator<char> e;
    string s(b, e);
    assert(s == "abCbA");
    }

    cout << "Done." << endl;
    return 0;}
