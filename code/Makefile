CXX = g++
CXXFLAGS = -Wall -Wextra -std=c++11

OBJ = main.o display.o experimentation.o table_generation.o algorithm.o

all: programme

programme: $(OBJ)
	$(CXX) $(CXXFLAGS) $(OBJ) -o programme

main.o: main.cpp display.h experimentation.h
	$(CXX) $(CXXFLAGS) -c main.cpp

display.o: display.cpp display.h
	$(CXX) $(CXXFLAGS) -c display.cpp

experimentation.o: experimentation.cpp experimentation.h table_generation.h algorithm.h
	$(CXX) $(CXXFLAGS) -c experimentation.cpp

table_generation.o: table_generation.cpp table_generation.h
	$(CXX) $(CXXFLAGS) -c table_generation.cpp

algorithm.o: algorithm.cpp algorithm.h
	$(CXX) $(CXXFLAGS) -c algorithm.cpp

clean:
	rm -f *.o programme