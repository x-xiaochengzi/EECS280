CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

# Compile the main executable
main.exe: lab02_main.cpp lab02.cpp
	$(CXX) $(CXXFLAGS) lab02_main.cpp lab02.cpp -o main.exe


# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
# Disable built-in rules
.SUFFIXES:
