CXX ?= g++
CXXFLAGES ?= -Wall -Werror -g -pedantic --std=c++11 -fsanitize=address -fsanitize=undefined


# Compile the lab04.exe executable
lab04.exe: main.cpp lab04.cpp
	$(CXX) $(CXXFLAGES) lab04.cpp main.cpp -o lab04.exe

# Compile the spell.exe executable
spell.exe: spellcheck.cpp
	$(CXX) $(CXXFLAGES) spellcheck.cpp -o spell.exe
# Remove automatically generated files
clean:
	rm -rvf  *.exe  *~  *.out  *.dSYM  *.stackdump
# Disable built-in rules
.SUFFIXES: