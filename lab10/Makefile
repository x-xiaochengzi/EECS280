CXX ?= g++
CXXFLAGS = --std=c++17 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
# Compile the main executable
main.exe: main.cpp lab10.cpp
	$(CXX) $(CXXFLAGS) main.cpp lab10.cpp -o main.exe
# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
# Disable built-in rules
.SUFFIXES:
