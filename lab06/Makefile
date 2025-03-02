CXX ?= g++
CXXFLAGS = --std=c++17 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG
# Compile the main executable
lab06.exe : IntVector.cpp lab06.cpp
	$(CXX) $(CXXFLAGS) IntVector.cpp lab06.cpp -o lab06.exe
# Remove automatically generated files
clean :
	rm -rvf *.exe *~ *.out *.dSYM *.stackdump
# Disable built-in rules
.SUFFIXES:
