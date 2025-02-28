CXX ?= g++
CXXFLAGS = --std=c++17 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG

# Compile the main executable
lab05.exe: lab05.cpp shapes.cpp Canvas.cpp
	$(CXX) $(CXXFLAGS) lab05.cpp shapes.cpp Canvas.cpp -o lab05.exe


# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
# Disable built-in rules
.SUFFIXES: