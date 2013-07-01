/*
CS378: Quiz #1 (10 pts) <Ben>
*/

/* -----------------------------------------------------------------------
1. List any piece of advice.
   [The Harvard Guide to Collegiate Happiness]
   (2 pts)

meet the faculty
take a mix of courses
study in groups
write, write, write
speak another language
manage time
participate in extracurricular activities
*/

/* -----------------------------------------------------------------------
2. List any piece of advice.
   [Advice for Computer Science College Students]
   (2 pts)

write
learn C
learn microeconomics
excel in non-CS classes
take programming-intensive classes
stop worrying about jobs going to India
get a good summer internship
*/

/* -----------------------------------------------------------------------
3. Show the cycle for 3.
   What is the cycle length?
   [Collatz]
   (2 pts)

3, 10, 5, 16, 8, 4, 2, 1
8
*/

/* -----------------------------------------------------------------------
4. Which of the following is true? Maybe more than one.
   [Collatz]
   (1 pt)

a. (n / 2),  with n even, always produces an even
b. (n / 2),  with n even, always produces an odd
c. (3n + 1), with n odd,  always produces an even
d. (3n + 1), with n odd,  always produces an odd

c.
*/

/* -----------------------------------------------------------------------
5. Given positive integers, b and e, let m = e / 2. If b < m, then
   max_cycle_length(b, e) = max_cycle_length(m, e). True or False?
   [Collatz]
   (2 pts)

True

Consider b = 10, e = 100.
Then m = 100 / 2 = 50.
max_cycle_length(10, 100) = max_cycle_length(50, 100)
All the numbers in the range [10, 49] can be mapped to numbers in the
range [50, 100] by one or more doublings, so none of the numbers in the
range [10, 49] could have a larger cycle length than the numbers in the
range [50, 100].
*/
