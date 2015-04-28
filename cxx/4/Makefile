CFLAG=-std=c++11 -I. -Wall -O0 -Werror
main:A.o main.cc
	g++ $(CFLAG) $^ -o $@
A.o:A.cc
	g++ $(CFLAG) -c $^ -o $@
clean:
	rm -f *.o main
