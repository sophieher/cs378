/*
CS378: Quiz #7 (10 pts)
*/

/* -----------------------------------------------------------------------
1. What are the TWO major conclusions of the article?
   [Why Undergraduates Should Learn the Principles of Programming
    Languages]
   (2 pts)

programming languages embody many central concepts of cs
studying programming languages provides insights to all aspects of cs

courses should present those concepts in a broader context than a single
language
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (7 pts)

f(T&)
f(const T*)
f(const T&)
*/

#include <iostream> // cout, endl
#include <string>   // string

using namespace std;

template <typename T>
string f (T& v) {
    return "f(T&)";}

template <typename T>
string f (const T& r) {
    return "f(const T&)";}

template <typename T>
string f (const T* p) {
    return "f(const T*)";}

int main () {
    int i = 2;
    cout << f(i)        << endl;
    cout << f<int>(&i)  << endl;
    cout << f<int*>(&i) << endl;
    return 0;}
