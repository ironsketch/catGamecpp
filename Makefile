all: catGame

catGame:
		g++ -std=c++11 main.o cat.o -o catGame -framework SDL2 -framework SDL2_image

main.o: main.cc cat.h
		g++ -c -std=c++11 main.o cat.h

cat.o: cat.cc cat.h
		g++ -c -std=c++11 cat.o cat.h
