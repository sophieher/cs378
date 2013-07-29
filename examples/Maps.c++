// --------
// Maps.c++
// --------

#include <cassert>    // assert
#include <functional> // less
#include <iostream>   // cout, endl
#include <map>        // map
#include <string>     // string
#include <utility>    // pair

template <typename C>
void maps (
        const typename C::key_type&    k1,
        const typename C::key_type&    k2,
        const typename C::key_type&    k3,
        const typename C::mapped_type& v1,
        const typename C::mapped_type& v2,
        const typename C::mapped_type& v3) {

    typedef typename C::key_type    key_type;
    typedef typename C::mapped_type mapped_type;
    typedef typename C::value_type  value_type;
    typedef typename C::iterator    iterator;

    {
    C x;
    assert(x.empty());
    assert(x.size() == 0);
    }

    {
    C x;
    x.insert(value_type(k1, v1));
    x.insert(value_type(k2, v2));
    x.insert(value_type(k3, v3));
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
    x.insert(value_type(k1, v1));
    x.insert(value_type(k2, v2));
    x.insert(value_type(k3, v3));
    C y;
    y.insert(value_type(k3, v3));
    y.insert(value_type(k1, v1));
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
    x.insert(value_type(k1, v1));
    x.insert(value_type(k2, v2));
    x.insert(value_type(k3, v3));
    C y;
    y.insert(value_type(k3, v3));
    y.insert(value_type(k1, v1));
    x.swap(y);
    assert(x.size()   == 2);
    assert(x.find(k2) == x.end());
    assert(y.size()   == 3);
    assert(y.find(k2) == ++y.begin());
    }

    {
    C x;
    x.insert(value_type(k1, v1));
    x.insert(value_type(k2, v2));
    x.insert(value_type(k3, v3));
    assert(x.find(k2)->first  == k2);
//  x.find(k2)->first = k3;           // doesn't compile
    assert(x.find(k2)->second == v2);
    x.find(k2)->second = v3;
    assert(x.find(k2)->second == v3);
    }

    {
    C x;
    std::pair<iterator, bool> p = x.insert(value_type(k1, v1));
    assert(x.find(k1)->second == v1);
    assert(p.first            == x.begin());
    assert(p.second           == true);
    std::pair<iterator, bool> q = x.insert(value_type(k1, v2));
    assert(x.find(k1)->second == v1);
    assert(q.first            == x.begin());
    assert(q.second           == false);
    }

    {
    C x;
    x.insert(value_type(k1, v1));
    x.insert(value_type(k2, v2));
    x.insert(value_type(k3, v3));
    assert(x[k2] == v2);
    x[k2] = v3;
    assert(x[k2] == v3);
    }

    {
    C x;
    x.insert(value_type(k1, v1));
    assert(x[k2] == mapped_type());
    x[k2] = v2;
    assert(x[k2] == v2);
    assert(x.size() == 2);
    x[k3] = v3;
    assert(x[k3] == v3);
    assert(x.size() == 3);
    }

    {
    C x;
    x.insert(value_type(k1, v1));
    x.insert(value_type(k2, v2));
    x.insert(value_type(k3, v3));
    C y;
    y.insert(value_type(k1, v1));
    y.insert(value_type(k2, v2));
    y.insert(value_type(k3, v3));
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }}

int main () {
    using namespace std;
    cout << "Maps.c++" << endl;
    maps< map<string, int>                >("abc", "def", "jkl", 2, 3, 4);
    maps< map<string, int, less<string> > >("abc", "def", "jkl", 2, 3, 4);
    cout << "Done." << endl;
    return 0;}
