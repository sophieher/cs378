/*
CS378: Quiz #23 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
 1. What does the following declare?
    (3 pts)

a function, named x, that takes an int, named v, and returns an int
*/

int x (int (v));

/* -----------------------------------------------------------------------
 2. What does the following declare?
    (3 pts)

a function, named y, that takes an unnamed function and returns an int
the unnamed function takes no arguments and returns an int
*/

int y (int ());

/* -----------------------------------------------------------------------
 3. What do the following declare?
    (3 pts)

a vector<char>, named v, size 3, initialized with 'x's

a string, named z, constructed with the beginning and end of the vector

a function, named t, that takes two arguments
the first argument is an istream_iterator<char>, named cin
the second argument is an unnamed function
the unnamed function takes no arguments and returns an
istream_iterator<char>
*/

#include <iostream> // cin
#include <iterator> // istream_iterator
#include <string>   // string
#include <vector>   // vector

using namespace std;

int main () {
    vector<char> v(3, 'x');
    string z(v.begin(),                   v.end());
    string t(istream_iterator<char>(cin), istream_iterator<char>());
    return 0;}
/*
CS378: Quiz #20 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

true true abcx
true
true true abcxx
*/

#include <iostream> // boolalpha, cout, endl
#include <iterator> // back_insert_iterator
#include <string>   // string

using namespace std;

int main () {
    cout << boolalpha; // bool outputs as true or false

    string                       s = "abc";
    back_insert_iterator<string> p(s);

    cout << (&*p         == &p) << " ";
    cout << (&(*p = 'x') == &p) << " ";
    cout << s                   << endl;

    cout << (&++p == &p)        << endl;

    cout << (&*p         == &p) << " ";
    cout << (&(*p = 'x') == &p) << " ";
    cout << s                   << endl;

    return 0;}
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
/*
CS378: Quiz #18 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. What are the complexities of the following statements;
   (9 pts)

O(1)
O(n)

O(n)
O(n)

O(1)
O(n)

O(n)
O(n)
*/

T* a = new T[s];      // T a built-in     type
T* a = new T[s];      // T a user-defined type

vector<T> x(s);       // T a built-in     type
vector<T> x(s);       // T a user-defined type

T a[s];               // T a built-in     type
T a[s];               // T a user-defined type

array_object<T, s> x; // T a built-in     type
array_object<T, s> x; // T a user-defined type
/*
CS378: Quiz #17 (10 pts) <Ben>
*/

#include <iostream> // boolalpha, cout, endl
#include <map>      // map
#include <utility>  // pair

using namespace std;

/* -----------------------------------------------------------------------
1. What is the output of the following function?
   (5 pts)

true false
*/

void test_map_1 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type             x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    pair<iterator, bool> q = x.insert(value_type(2, 4));
    cout << (q.first == x.begin()) << " ";
    cout << (x[2]    == 4)         << endl;}

/* -----------------------------------------------------------------------
2. What is the output of the following function?
   (4 pts)

true false
*/

void test_map_2 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type             x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    cout << (x[4]     == 0) << " ";
    cout << (x.size() == 1) << endl;}

/* -----------------------------------------------------------------------
*/

int main () {
    cout << boolalpha;
    test_map_1();
    test_map_2();
    cout << "Done." << endl;
    return 0;}
/*
CS378: Quiz #16 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
 1. How many times does the function g() get instantiated in the
    following?
    And for each time, specify the value of BF.
    (9 pts)

int (*) (int, int)
plus_2<int>
multiplies_2<int>
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename BF, typename T>
T g (BF f, const T& x, const T& y, const T& z) {
    return f(f(x, y), z);}

template <typename T>
T plus_1 (T x, T y) {
    return x + y;}

template <typename T>
T multiplies_1 (T x, T y) {
    return x * y;}

template <typename T>
struct plus_2 {
    T operator () (const T& x, const T& y) const {
        return x + y;}};

template <typename T>
struct multiplies_2 {
    T operator () (const T& x, const T& y) const {
        return x * y;}};

int main () {
    assert(g(plus_1<int>,       2, 3, 4) ==  9);
    assert(g(multiplies_1<int>, 2, 3, 4) == 24);

    assert(g(plus_2<int>(),       2, 3, 4) ==  9);
    assert(g(multiplies_2<int>(), 2, 3, 4) == 24);

    cout << "Done." << endl;
    return 0;}
/*
CS378: Quiz #15 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

1 1
2 1
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

struct A {
    int i;

    struct B {
        A*  q;
        int j;

        B (A* p) {q = p; j = 0;}
        void g () {++q->i; ++j;}};

    A () {i = 0;}
    B f () {return B(this);}};

int main () {
    A x;

    A::B y = x.f();
    y.g();
    cout << x.i << " ";
    cout << y.j << endl;

    y = x.f();
    y.g();
    cout << x.i << " ";
    cout << y.j << endl;

    return 0;}
/*
CS378: Quiz #14 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. Define the function pre_increment() to emulate the prefix increment
   operator.
   (3 pts)
*/

int& pre_increment (int& n) {
    return n += 1;}

/* -----------------------------------------------------------------------
2. Define the function post_increment() to emulate the postfix increment
   operator.
   (3 pts)
*/

int post_increment (int& n) {
    int m = n;
    n += 1;
    return m;}

/* -----------------------------------------------------------------------
3. Which of following is the LARGEST set of containers that can back
   priority_queue?
   (3 pts)

a. deque, list, vector
b. deque, list
c. deque, vector
d. list, vector

c.
*/
/*
CS378: Quiz #14 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. Define the function pre_increment() to emulate the prefix increment
   operator.
   (3 pts)
*/

int& pre_increment (int& n) {
    return n += 1;}

/* -----------------------------------------------------------------------
2. Define the function post_increment() to emulate the postfix increment
   operator.
   (3 pts)
*/

int post_increment (int& n) {
    int m = n;
    n += 1;
    return m;}

/* -----------------------------------------------------------------------
3. Which of following is the LARGEST set of containers that can back
   priority_queue?
   (3 pts)

a. deque, list, vector
b. deque, list
c. deque, vector
d. list, vector

c.
*/
/*
CS378: Quiz #15 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

1 1
2 1
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

struct A {
    int i;

    struct B {
        A*  q;
        int j;

        B (A* p) {q = p; j = 0;}
        void g () {++q->i; ++j;}};

    A () {i = 0;}
    B f () {return B(this);}};

int main () {
    A x;

    A::B y = x.f();
    y.g();
    cout << x.i << " ";
    cout << y.j << endl;

    y = x.f();
    y.g();
    cout << x.i << " ";
    cout << y.j << endl;

    return 0;}
/*
CS378: Quiz #16 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
 1. How many times does the function g() get instantiated in the
    following?
    And for each time, specify the value of BF.
    (9 pts)

int (*) (int, int)
plus_2<int>
multiplies_2<int>
*/

#include <cassert>  // assert
#include <iostream> // cout, endl

using namespace std;

template <typename BF, typename T>
T g (BF f, const T& x, const T& y, const T& z) {
    return f(f(x, y), z);}

template <typename T>
T plus_1 (T x, T y) {
    return x + y;}

template <typename T>
T multiplies_1 (T x, T y) {
    return x * y;}

template <typename T>
struct plus_2 {
    T operator () (const T& x, const T& y) const {
        return x + y;}};

template <typename T>
struct multiplies_2 {
    T operator () (const T& x, const T& y) const {
        return x * y;}};

int main () {
    assert(g(plus_1<int>,       2, 3, 4) ==  9);
    assert(g(multiplies_1<int>, 2, 3, 4) == 24);

    assert(g(plus_2<int>(),       2, 3, 4) ==  9);
    assert(g(multiplies_2<int>(), 2, 3, 4) == 24);

    cout << "Done." << endl;
    return 0;}
/*
CS378: Quiz #17 (10 pts) <Ben>
*/

#include <iostream> // boolalpha, cout, endl
#include <map>      // map
#include <utility>  // pair

using namespace std;

/* -----------------------------------------------------------------------
1. What is the output of the following function?
   (5 pts)

true false
*/

void test_map_1 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type             x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    pair<iterator, bool> q = x.insert(value_type(2, 4));
    cout << (q.first == x.begin()) << " ";
    cout << (x[2]    == 4)         << endl;}

/* -----------------------------------------------------------------------
2. What is the output of the following function?
   (4 pts)

true false
*/

void test_map_2 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type             x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    cout << (x[4]     == 0) << " ";
    cout << (x.size() == 1) << endl;}

/* -----------------------------------------------------------------------
*/

int main () {
    cout << boolalpha;
    test_map_1();
    test_map_2();
    cout << "Done." << endl;
    return 0;}
/*
CS378: Quiz #18 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. What are the complexities of the following statements;
   (9 pts)

O(1)
O(n)

O(n)
O(n)

O(1)
O(n)

O(n)
O(n)
*/

T* a = new T[s];      // T a built-in     type
T* a = new T[s];      // T a user-defined type

vector<T> x(s);       // T a built-in     type
vector<T> x(s);       // T a user-defined type

T a[s];               // T a built-in     type
T a[s];               // T a user-defined type

array_object<T, s> x; // T a built-in     type
array_object<T, s> x; // T a user-defined type
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
/*
CS378: Quiz #20 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)

true true abcx
true
true true abcxx
*/

#include <iostream> // boolalpha, cout, endl
#include <iterator> // back_insert_iterator
#include <string>   // string

using namespace std;

int main () {
    cout << boolalpha; // bool outputs as true or false

    string                       s = "abc";
    back_insert_iterator<string> p(s);

    cout << (&*p         == &p) << " ";
    cout << (&(*p = 'x') == &p) << " ";
    cout << s                   << endl;

    cout << (&++p == &p)        << endl;

    cout << (&*p         == &p) << " ";
    cout << (&(*p = 'x') == &p) << " ";
    cout << s                   << endl;

    return 0;}
/*
CS378: Quiz #23 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
 1. What does the following declare?
    (3 pts)

a function, named x, that takes an int, named v, and returns an int
*/

int x (int (v));

/* -----------------------------------------------------------------------
 2. What does the following declare?
    (3 pts)

a function, named y, that takes an unnamed function and returns an int
the unnamed function takes no arguments and returns an int
*/

int y (int ());

/* -----------------------------------------------------------------------
 3. What do the following declare?
    (3 pts)

a vector<char>, named v, size 3, initialized with 'x's

a string, named z, constructed with the beginning and end of the vector

a function, named t, that takes two arguments
the first argument is an istream_iterator<char>, named cin
the second argument is an unnamed function
the unnamed function takes no arguments and returns an
istream_iterator<char>
*/

#include <iostream> // cin
#include <iterator> // istream_iterator
#include <string>   // string
#include <vector>   // vector

using namespace std;

int main () {
    vector<char> v(3, 'x');
    string z(v.begin(),                   v.end());
    string t(istream_iterator<char>(cin), istream_iterator<char>());
    return 0;}
