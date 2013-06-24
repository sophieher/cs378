#include <functional>
#include <iostream>
#include <vector>

int main () {
    using namespace std;
    cout << "Test.c++" << endl;

    vector<int> x(10, 2);
    cout << x[3];

    for (int v : x) {
        cout << v << endl;}

    std::reference_wrapper<int> y = x;


    cout << "Done." << endl;
    return 0;}
