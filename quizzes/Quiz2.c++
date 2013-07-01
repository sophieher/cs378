/*
CS378: Quiz #2 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. What is the name of the predefined macro that indicates the version of
   C++ that is being used?
   [Sec. 2.1.2, Pg. 9]
   (4 pts)

__cplusplus
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (5 pts)

m1 f1 f2 m2 m4
m1 f1 m3 m4
*/

#include <iostream> // cout, endl

using namespace std;

void f (bool b) {
    cout << "f1 ";
    if (b)
        throw exception();
    cout << "f2 ";}

int main () {
    try {
        cout << "m1 ";
        f(false);
        cout << "m2 ";}
    catch (exception& e) {
        cout << "m3 ";}
    cout << "m4 " << endl;

    try {
        cout << "m1 ";
        f(true);
        cout << "m2 ";}
    catch (exception& e) {
        cout << "m3 ";}
    cout << "m4" << endl;

    return 0;}
