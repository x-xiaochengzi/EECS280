.PHONY: lab02 lab03 lab04 lab05 lab06 lab07 lab08 lab09 lab10

labs ?= lab02 lab03 lab04 lab05 lab06 lab07 lab08 lab09 lab10

$(labs): 
	wget eecs280staff.github.io/lab/$@/starter-files.tar.gz
	tar -zxvf starter-files.tar.gz 
	mv starter-files $@ 
	rm starter-files.tar.gz
	touch ./$@/Makefile
	@echo "CXX ?= g++" > ./$@/Makefile
	@echo "CXXFLAGS = --std=c++17 -Wall -Werror -pedantic -g -fsanitize=address -fsanitize=undefined -D_GLIBCXX_DEBUG" >> ./$@/Makefile
	@echo "# Compile the main executable" >> ./$@/Makefile
	@echo ""
	@echo "# Remove automatically generated files" >> ./$@/Makefile
	@echo "clean :" >> ./$@/Makefile
	@echo "	rm -rvf *.exe *~ *.out *.dSYM *.stackdump" >> ./$@/Makefile
	@echo "# Disable built-in rules" >> ./$@/Makefile
	@echo ".SUFFIXES:" >> ./$@/Makefile
