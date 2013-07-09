// --------
// Sets.c++
// --------

#include <cassert>    // assert
#include <functional> // less
#include <iostream>   // cout, endl
#include <set>        // set
#include <string>     // string
#include <utility>    // pair

template <typename C>
void sets (
        const typename C::key_type& k1,
        const typename C::key_type& k2,
        const typename C::key_type& k3) {

    typedef typename C::iterator iterator;

    {
    C x;
    assert(x.empty());
    assert(x.size() == 0);
    }

    {
    C x;
    x.insert(k1);
    x.insert(k2);
    x.insert(k3);
    C y(x);
    assert(x == y);
    y.erase(k2);
    assert(x.size()   == 3);
    assert(x.find(k2) == ++x.begin());
    assert(y.size()   == 2);
    assert(y.find(k2) == y.end());
    }

    {
    C x;
    x.insert(k1);
    x.insert(k2);
    x.insert(k3);
    C y;
    y.insert(k3);
    y.insert(k1);
    y = x;
    assert(x == y);
    y.erase(k2);
    assert(x.size()   == 3);
    assert(x.find(k2) == ++x.begin());
    assert(y.size()   == 2);
    assert(y.find(k2) == y.end());
    }

    {
    C x;
    x.insert(k1);
    x.insert(k2);
    x.insert(k3);
    C y;
    y.insert(k3);
    y.insert(k1);
    x.swap(y);
    assert(x.size()   == 2);
    assert(x.find(k2) == x.end());
    assert(y.size()   == 3);
    assert(y.find(k2) == ++y.begin());
    }

    {
    C x;
    x.insert(k1);
    x.insert(k2);
    x.insert(k3);
    assert(*x.find(k2) == k2);
//  *x.find(k2) = k3;                           // doesn't compile
    }

    {
    C x;
    std::pair<iterator, bool> p = x.insert(k1);
    assert(p.first  == x.begin());
    assert(p.second == true);
    std::pair<iterator, bool> q = x.insert(k1);
    assert(q.first  == x.begin());
    assert(q.second == false);
    }

    {
    C x;
    x.insert(k1);
    x.insert(k2);
    x.insert(k3);
    C y;
    y.insert(k1);
    y.insert(k2);
    y.insert(k3);
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }}

int main () {
    using namespace std;
    cout << "Set.c++" << endl;
    sets< set<string>                >("abc", "def", "jkl");
    sets< set<string, less<string> > >("abc", "def", "jkl");
    cout << "Done." << endl;
    return 0;}
