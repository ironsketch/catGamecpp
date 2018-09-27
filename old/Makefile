CXXFLAGS = -std=c++11 -w -framework SDL2 -framework SDL2_image
CXX = g++
FLAGS = -c -w
all: main.o player.o level.o timer.o extra.o catGame clean
main.o: main.cc player.h level.h timer.h extra.h
	$(CXX) $(FLAGS) main.cc

player.o: player.cc player.h level.h extra.h
	$(CXX) $(FLAGS) player.cc

level.o: level.cc level.h extra.h
	$(CXX) $(FLAGS) level.cc

timer.o: timer.cc timer.h level.h extra.h
	$(CXX) $(FLAGS) timer.cc

extra.o: extra.cc extra.h
	$(CXX) $(FLAGS) extra.cc

catGame: main.o player.o level.o timer.o extra.o
	$(CXX) main.o player.o level.o timer.o extra.o $(CXXFLAGS) -o catGame

clean:
	rm -f *.o
