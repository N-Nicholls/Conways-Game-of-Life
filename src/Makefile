all: main.cpp grid.cpp
	g++ main.cpp -o main grid.o
grid.o: grid.cpp grid.h
	g++ -c grid.cpp -o grid.o
clean:
	rm -f *.o all