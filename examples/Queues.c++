// ----------
// Queues.c++
// ----------

#include <cassert>  // assert
#include <iostream> // cout, endl
#include <list>     // list
#include <queue>    // queue
#include <string>   // string

#include "Queue.h"

template <typename C>
void queues (
        const typename C::value_type& v1,
        const typename C::value_type& v2,
        const typename C::value_type& v3) {

    typedef typename C::container_type container_type;

    {
    C x;
    assert(x.empty());
    assert(x.size() == 0);
    x.push(v1);
    x.push(v2);
    x.push(v3);
    assert(!x.empty());
    assert(x.size()  == 3);
    assert(x.front() == v1);
    assert(x.back()  == v3);
    x.pop();
    assert(x.size()  == 2);
    assert(x.front() == v2);
    assert(x.back()  == v3);
    }

    {
    C x;
    x.push(v1);
    x.push(v2);
    x.push(v3);
    x.front() = v2;
    assert(x.front() == v2);
    x.back()  = v2;
    assert(x.back()  == v2);
    }

    {
    C x;
    x.push(v1);
    x.push(v2);
    x.push(v3);
    C y(x);
    assert(x == y);
    y.pop();
    assert(x.size()  == 3);
    assert(x.front() == v1);
    assert(x.back()  == v3);
    assert(y.size()  == 2);
    assert(y.front() == v2);
    assert(y.back()  == v3);
    }

    {
    container_type x;
    x.push_back(v1);
    x.push_back(v2);
    x.push_back(v3);
    C y(x);
    y.pop();
    assert(x.size()  == 3);
    assert(x.front() == v1);
    assert(x.back()  == v3);
    assert(y.size()  == 2);
    assert(y.front() == v2);
    assert(y.back()  == v3);
    }

    {
    C x;
    x.push(v1);
    x.push(v2);
    x.push(v3);
    C y;
    y.push(v3);
    y.push(v1);
    y = x;
    assert(x == y);
    y.pop();
    assert(x.size()  == 3);
    assert(x.front() == v1);
    assert(x.back()  == v3);
    assert(y.size()  == 2);
    assert(y.front() == v2);
    assert(y.back()  == v3);
    }

    {
    C x;
    x.push(v1);
    x.push(v2);
    x.push(v3);
    C y;
    y.push(v1);
    y.push(v2);
    y.push(v3);
    assert(x == y);
    assert(x <= y);
    assert(x >= y);
    assert(!(x != y));
    assert(!(x <  y));
    assert(!(x >  y));
    }}

int main () {
    using namespace std;
    cout << "Queues.c++" << endl;

    queues<    queue<string>                       >("abc", "def", "ghi");
    queues<    queue<string, std::list<string>   > >("abc", "def", "ghi");
//  queues<    queue<string, std::vector<string> > >("abc", "def", "ghi"); // doesn't compile

    queues< my_queue<string>                       >("abc", "def", "ghi");
    queues< my_queue<string, std::list<string>   > >("abc", "def", "ghi");
//  queues< my_queue<string, std::vector<string> > >("abc", "def", "ghi"); // doesn't compile

    cout << "Done." << endl;
    return 0;}
