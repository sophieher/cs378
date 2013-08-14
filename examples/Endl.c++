// --------
// Endl.c++
// --------

#include <cassert>  // assert
#include <iostream> // cout, endl, flush, ostream
#include <sstream>  // ostringstream
#include <string>   // ==

/*
namespace std {

class ostream {
    public:
        typedef ostream& (*FP)(ostream&);

        ostream& operator << (FP f) {
            return f(*this);}

        // ...
        };

} // std
*/

std::ostream& my_endl (std::ostream& out) {
    return out << "\n" << std::flush;}

int main () {
    using namespace std;
    cout << "Endl.c++" << endl;

    {
    ostringstream out;
    endl(out);
    out << endl;
    assert(out.str() == "\n\n");
    }

    {
    ostringstream out;
    my_endl(out);
    out << my_endl;
    assert(out.str() == "\n\n");
    }

    cout << "Done." << endl;
    return 0;}
