/*
CS378: Quiz #20 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following program?
   (9 pts)
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
