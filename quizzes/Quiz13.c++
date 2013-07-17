/*
CS378: Quiz #13 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
1. In the implementation of vector, what was the reason for adding an
   allocator template argument?
   (1 pt)

so that the user can specify their own allocator type
*/

/* -----------------------------------------------------------------------
2. In the implementation of vector, what was the reason for adding an
   allocator constructor argument?
   (2 pts)

so that the user can create an allocator object with a constructor other
than the default constructor
*/

/* -----------------------------------------------------------------------
3. Assuming that push_back() and push_front() are defined for
   std::vector<T> and std::deque<T>, what are the complexities for each?
   (4 pts)

push_back()  on vector is amortized constant
push_front() on vector is           linear

push_back()  on deque  is amortized constant
push_front() on deque  is amortized constant
*/

/* -----------------------------------------------------------------------
4. What is the complexity of std::vector<T>::swap()?
   Be precise. There are two cases.
   (2 pts)

constant if the allocators are equivalent, linear if not
*/
