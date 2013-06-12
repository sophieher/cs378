// ---------------
// CommandLine.c++
// ---------------

/*
% CommandLine.c++.app Nothing to be done.
*/

#include <algorithm> // equal
#include <cassert>   // assert
#include <iostream>  // cout, endl
#include <string>    // string

int main (int argc, char* argv[]) {
    using namespace std;
    cout << "CommandLine.c++" << endl;

    assert(argc == 5);

    const string a[] = {"Nothing", "to", "be", "done."};
//  assert(argv == a);
    assert(equal(argv + 1, argv + argc, a));

    cout << "Done." << endl;
    return 0;}
