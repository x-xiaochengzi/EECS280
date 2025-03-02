CXX ?= g++
CXXFLAGS = --std=c++17 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
# Compile the main executable
lab08.exe: ArrayIntVector.cpp lab08.cpp
	$(CXX) $(CXXFLAGS) ArrayIntVector.cpp lab08.cpp -o lab08.exe
# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
# Disable built-in rules
.SUFFIXES:
