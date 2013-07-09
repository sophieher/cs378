// ------------------
// PriorityQueues.c++
// ------------------

#include <cassert>    // assert
#include <deque>      // deque
#include <functional> // less
#include <iostream>   // cout, endl
#include <queue>      // priority_queue
#include <string>     // string

#include "PriorityQueue.h"

template <typename C>
void priority_queues (
        const typename C::value_type& v1,
        const typename C::value_type& v2,
        const typename C::value_type& v3) {

    typedef typename C::container_type container_type;

    {
    C x;
    assert(x.empty());
    assert(x.size() == 0);
    x.push(v2);
    x.push(v3);
    x.push(v1);
    assert(!x.empty());
    assert(x.size() == 3);
    assert(x.top()  == v3);
    x.pop();
    assert(x.size() == 2);
    assert(x.top()  == v2);
    }

    {
    C x;
    x.push(v2);
    x.push(v3);
    x.push(v1);
//  x.top() = v2;                // doesn't compile
    }

    {
    C x;
    x.push(v2);
    x.push(v3);
    x.push(v1);
    C y(x);
//  assert(x == y);              // doesn't compile
    assert(!y.empty());
    assert(y.size() == 3);
    y.pop();
    assert(x.size() == 3);
    assert(x.top()  == v3);
    assert(y.size() == 2);
    assert(y.top()  == v2);
    }

    {
    std::less<std::string> x;
    container_type         y;
    y.push_back(v2);
    y.push_back(v3);
    y.push_back(v1);
    C z(x, y);
    z.pop();
    assert(y.size() == 3);
    assert(y.back() == v1);
    assert(z.size() == 2);
    assert(z.top()  == v2);
    }

    {
    C x;
    x.push(v2);
    x.push(v3);
    x.push(v1);
    C y;
    y.push(v3);
    y.push(v1);
    y = x;
    y.pop();
    assert(x.size() == 3);
    assert(x.top()  == v3);
    assert(y.size() == 2);
    assert(y.top()  == v2);
    }}

int main () {
    using namespace std;
    cout << "PriorityQueues.c++" << endl;

    priority_queues<    priority_queue<string>                                    >("abc", "def", "ghi");
    priority_queues<    priority_queue<string, std::deque<string> >               >("abc", "def", "ghi");
    priority_queues<    priority_queue<string, std::deque<string>, less<string> > >("abc", "def", "ghi");
//  priority_queues<    priority_queue<string, std::list<string>                > >("abc", "def", "ghi"); // doesn't compile

    priority_queues< my_priority_queue<string>                                    >("abc", "def", "ghi");
    priority_queues< my_priority_queue<string, std::deque<string>               > >("abc", "def", "ghi");
    priority_queues< my_priority_queue<string, std::deque<string>, less<string> > >("abc", "def", "ghi");
//  priority_queues< my_priority_queue<string, std::list<string>                > >("abc", "def", "ghi"); // doesn't compile

    cout << "Done." << endl;
    return 0;}
