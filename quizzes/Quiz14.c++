/*
CS378: Quiz #14 (10 pts) <Tom>
*/

/* -----------------------------------------------------------------------
1. Define the function pre_increment() to emulate the prefix increment
   operator.
   (3 pts)
*/

int& pre_increment (int& n) {
    return n += 1;}

/* -----------------------------------------------------------------------
2. Define the function post_increment() to emulate the postfix increment
   operator.
   (3 pts)
*/

int post_increment (int& n) {
    int m = n;
    n += 1;
    return m;}

/* -----------------------------------------------------------------------
3. Which of following is the LARGEST set of containers that can back
   priority_queue?
   (3 pts)

a. deque, list, vector
b. deque, list
c. deque, vector
d. list, vector

c.
*/
