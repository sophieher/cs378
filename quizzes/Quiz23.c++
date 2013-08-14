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
