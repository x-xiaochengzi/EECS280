CXX ?= g++
CXXFLAGS ?= -Wall -Werror -pedantic -g --std=c++17 -Wno-sign-compare -Wno-comment

# Compile the main executable
test1.exe: test1.cpp any_of.cpp
	$(CXX) $(CXXFLAGS)  test1.cpp any_of.cpp -o test1.exe

test2.exe: test2.cpp
	$(CXX) $(CXXFLAGS)  test2.cpp -o test2.exe

test3.exe: test3.cpp
	$(CXX) $(CXXFLAGS)  test3.cpp -o test3.exe
# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
# Disable built-in rules
.SUFFIXES: