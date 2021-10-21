main: main.o funcs.o caesar.o
	g++ -std=c++11 -o main main.o funcs.o caesar.o

tests: tests.o funcs.o caesar.o
	g++ -std=c++11 -o tests tests.o funcs.o caesar.o


funcs.o: funcs.cpp funcs.h
	g++ -c -std=c++11 -c funcs.cpp

caesar.o: caesar.cpp caesar.h
	g++ -c -std=c++11 -c caesar.cpp

main.o: main.cpp funcs.h

tests.o: tests.cpp doctest.h funcs.h
	g++ -std=c++11 -c tests.cpp

clean:
	rm -f *.o
