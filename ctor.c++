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

struct B : public A {
public:
    B() {
        cout  << "B() ";
    }
    B(const B& b) {
        cout  << "B(B) ";
    }
    B(int) {
        cout  << "B(int) ";
    }
    B& operator = (const B&) {
        cout  << "=(B) ";
        return *this;
    }
    ~B            ()         {cout  << "~B() ";}
};

int main() {
    cout  << "block 1" << endl;
    {
        vector<A> cont;
        cont.push_back(   1   );
        cout << endl;
    }
     cout  << endl << "block 2" << endl;   
    {
        vector<A> cont;
        A x;
        cont.push_back(x);
        cout << endl;
    }
    cout << endl << "block 3" << endl;
    {
        A y = 5;
        vector<A> x(10, y);
        cout << endl;
        x.resize(5);
        cout << endl;
    }
    cout  << endl << "block 4" << endl;
    {
        vector<A> x;
        x.push_back(B(1));
        cout << endl;
    }
    cout  << endl << "block 5" << endl;
    {
        A x;
        B y;
        vector<A> cont;
        cont.push_back(y);
        cont.push_back(2);
        cont.push_back(3);
        cout << endl;
    }
    cout  << endl << "block 6" << endl;
    {
        B(5);
    }

    cout << endl;
    return 0;
}
