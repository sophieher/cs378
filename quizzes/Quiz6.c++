/*
CS378: Quiz #6 (10 pts)
*/

/* -----------------------------------------------------------------------
1. What operations are being invoked in the following line:
   (3 pts)

string::string()
string::operator==()
*/

#include <cassert>
#include <iostream>
#include <string>

int main () {
    using namespace std;
    string s = "abc";
    assert(s == "abc");       // this line
    cout << "Done." << endl;}

/* -----------------------------------------------------------------------
2. Under what TWO circumstances does passing by reference instead of
   passing by address result in a compile time error instead of a runtime
   error?
   (6 pts)

not dereferencing an address could be a runtime error
dereferencing a reference would be a compile time error

passing in a zero when passing by address could be a runtime error
passing in a zero when passing by reference would be a compile time error
*/
