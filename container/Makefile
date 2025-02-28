CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

# Compile the main executable
main.exe: intset.cpp main.cpp
	$(CXX) $(CXXFLAGS) intset.cpp main.cpp -o main.exe


# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
# Disable built-in rules
.SUFFIXES: