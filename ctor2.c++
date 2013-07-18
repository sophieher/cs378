#include <iostream>
#include <vector>

using namespace std;

struct A {
public:
    A() {
        cout << "A() ";
    }
    A(const A& a) {
        cout  << "A(A) ";
    }
    A(int) { 
        cout  << "A(int) ";
    }
    A& operator = (const A&) {
        cout  << "=(A) ";
        return *this;
    }
    ~A            ()         {cout << "~A() ";}
};

int main() {
    {
        vector<A> cont;
        cont.push_back(   1   );
        cout << endl;
    }
  
    cout << endl;
    return 0;
}
