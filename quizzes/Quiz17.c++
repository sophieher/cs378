/*
CS378: Quiz #17 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
1. What is the output of the following function?
   (5 pts)

true false
*/

void test_map_1 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type             x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    pair<iterator, bool> q = x.insert(value_type(2, 4));
    cout << (q.first == x.begin()) << " ";
    cout << (x[2]    == 4)         << endl;}

/* -----------------------------------------------------------------------
2. What is the output of the following function?
   (4 pts)

true false
*/

void test_map_2 () {
    typedef map<int, int>        map_type;
    typedef map_type::value_type value_type;
    typedef map_type::iterator   iterator;

    map_type             x;
    pair<iterator, bool> p = x.insert(value_type(2, 3));
    cout << (x[4]     == 0) << " ";
    cout << (x.size() == 1) << endl;}
