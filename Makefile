# Define the C++ compiler to use
CXX = g++

# Define the compiler flags
CXXFLAGS = -Wall -std=c++11

# The target `main` depends on object files `main.o` and `graph.o`
main: main.o graph.o
    # Link the object files into an executable named `main`
	$(CXX) $(CXXFLAGS) -o main main.o graph.o

# The target `main.o` depends on `main.cpp` and `graph.hpp`
main.o: main.cpp graph.hpp
    # Compile `main.cpp` into an object file `main.o`
	$(CXX) $(CXXFLAGS) -c main.cpp

# The target `graph.o` depends on `graph.cpp` and `graph.hpp`
graph.o: graph.cpp graph.hpp
    # Compile `graph.cpp` into an object file `graph.o`
	$(CXX) $(CXXFLAGS) -c graph.cpp

# The target `clean` does not depend on any files
clean:
    # Remove the generated files
	-del .\main.o .\graph.o