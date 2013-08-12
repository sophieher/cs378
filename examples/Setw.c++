// --------
// Setw.c++
// --------

#include <cassert>    // assert
#include <functional> // unary_function
#include <iomanip>    // setfill
#include <iostream>   // cout, endl, ostream
#include <sstream>    // ostringstream
#include <string>     // ==

class my_setw : public std::unary_function<std::ostream&, std::ostream&> {
/*
    public:
        typedef std::ostream& argument_type;
        typedef std::ostream& result_type;
*/
    private:
        std::streamsize _s;

    public:
        my_setw (std::streamsize s) :
                _s (s)
            {}

        std::ostream& operator () (std::ostream& out) const {
            out.width(_s);
            return out;}};

std::ostream& operator << (std::ostream& out, my_setw f) {
    return f(out);}

int main () {
    using namespace std;
    cout << "Setw.c++" << endl;

    {
    ostringstream out;
    out << setfill('x') << setw(10) << "Hello.";
    assert(out.str() == "xxxxHello.");
    }

    {
    ostringstream out;
    out << setfill('x') << my_setw(10) << "Hello.";
    assert(out.str() == "xxxxHello.");
    }

    cout << "Done." << endl;
    return 0;}
