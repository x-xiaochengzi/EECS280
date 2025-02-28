.PHONY: lab02 lab03 lab04 lab05 lab06 lab07 lab08 lab09 lab10

labs ?= lab02 lab03 lab04 lab05 lab06 lab07 lab08 lab09 lab10

$(labs): 
	wget eecs280staff.github.io/lab/$@/starter-files.tar.gz
	tar -zxvf starter-files.tar.gz 
	mv starter-files $@ 
	rm starter-files.tar.gz
