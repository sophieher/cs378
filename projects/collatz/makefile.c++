all:
	make Collatz.zip

clean:
	rm -f Collatz.log
	rm -f Collatz.zip
	rm -f RunCollatz
	rm -f RunCollatz.tmp
	rm -f TestCollatz

diff: RunCollatz RunCollatz.in RunCollatz.out
	RunCollatz < RunCollatz.in > RunCollatz.tmp
	diff RunCollatz.out RunCollatz.tmp
	rm RunCollatz.tmp

doc: Collatz.c++
	doxygen Doxyfile

turnin-list:
	turnin --list tmtorres cs378pj1

turnin-submit: Collatz.zip
	turnin --submit tmtorres cs378pj1 Collatz.zip

turnin-verify:
	turnin --verify tmtorres cs378pj1

Collatz.log:
	git log > Collatz.log

Collatz.zip: Collatz.c++ Collatz.h Collatz.log           \
             RunCollatz.c++ RunCollatz.in RunCollatz.out \
             SphereCollatz.c++                           \
             TestCollatz.c++ TestCollatz.out
	zip -r Collatz.zip html/                           \
           Collatz.c++ Collatz.h Collatz.log           \
           RunCollatz.c++ RunCollatz.in RunCollatz.out \
           SphereCollatz.c++                           \
           TestCollatz.c++ TestCollatz.out

RunCollatz: Collatz.h Collatz.c++ RunCollatz.c++
	g++ -pedantic -std=c++0x -Wall Collatz.c++ RunCollatz.c++ -o RunCollatz

RunCollatz.out: RunCollatz RunCollatz.in
	valgrind RunCollatz < RunCollatz.in &> RunCollatz.out

TestCollatz: Collatz.h Collatz.c++ TestCollatz.c++
	g++ -pedantic -std=c++0x -Wall Collatz.c++ TestCollatz.c++ -o TestCollatz -lcppunit -ldl

TestCollatz.out: TestCollatz
	valgrind TestCollatz &> TestCollatz.out
