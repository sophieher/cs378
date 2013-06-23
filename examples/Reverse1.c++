// ------------
// Reverse1.c++
// ------------

#include <algorithm> // reverse, swap
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <list>      // list, ==
#include <vector>    // vector, ==

template <typename RI>
void my_reverse (RI b, RI e) {
    while (b < e) {
        --e;
        std::swap(*b, *e);
        ++b;}}

int main () {
    using namespace std;
    cout << "Reverse.c++" << endl;

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
    reverse(x.begin(), x.end());
    assert(x == y);
    }

    {
    char a[] = "abcde";
    list<char> x(a, a + 5);
    char b[] = "edcba";
    list<char> y(b, b + 5);
//  my_reverse(x.begin(), x.end()); // error: no match for 'operator<' in 'b < e'
//  assert(x == y);
    }

    cout << "Done." << endl;
    return 0;}
