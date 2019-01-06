main: main.o lib.o
	g++ -g -o main main.o lib.o -lm -ldl
#-Wl,-framework,ApplicationServices -pthread -Wl,-rpath,/sw/lib/root -lm -ldl
main.o: main.cpp lib.h
	g++ -g  -c -pthread main.cpp
#	g++ -g  -c -pthread -I/sw/include/root main.cpp

lib.o: lib.h lib.cpp
	g++ -g -c -pthread lib.cpp
clean:
	rm lib.o main.o main
