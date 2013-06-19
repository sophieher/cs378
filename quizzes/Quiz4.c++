/*
CS378: Quiz #4 (10 pts)
*/

/* -----------------------------------------------------------------------
1. Which of the following practices demonstrates effective pair
   programming?
   [All I Really Needed to Know about Pair Programming I Learned in
    Kindergarten]
   (1 pt)

a. Each partner writing separate parts.
b. Each partner writing both parts and then submitting the best.
c. Each partner writing both parts and then submitting the best
   combination.
d. Sharing a monitor and keyboard while coding.
e. One partner writing the interface and tests, the other the
   implementation.

d.
*/

/* -----------------------------------------------------------------------
2. What is the output of the following program?
   (8 pts)

3 true
3 false
*/

#include <iostream> // cout, endl

int main () {
    using namespace std;
    cout << boolalpha;   // bool outputs as true or false

    {
    int   i  = 2;
    int*  p  = &i;
    int** pp = &p;
    int** qq = pp;
    ++**qq;
    cout << i          << " ";
    ++qq;
    cout << (pp == &p) << endl;
    }

    {
    int    i  = 2;
    int*   p  = &i;
    int**  pp = &p;
    int**& qq = pp;
    ++**qq;
    cout << i          << " ";
    ++qq;
    cout << (pp == &p) << endl;
    }

    return 0;}
