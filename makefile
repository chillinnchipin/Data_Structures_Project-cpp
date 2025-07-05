CC := gcc
CXX := g++
CFLAGS :=
CXXFLAGS := 
CPPFLAGS := 

all: cpp_node test

cpp_node: cpp_node.o
	$(CXX) $(CXXFLAGS) -o cpp_node cpp_node.o

cpp_node.o: src/cppNode.cpp
	$(CXX) $(CPPFLAGS) -c src/cppNode.cpp -o cpp_node.o

test: CMakeLists.txt
	cmake -S . -B build/
	cmake --build build/

clean:
	rm -rf build/
	rm *.o
