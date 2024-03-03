# Default target executed when no arguments are given to make.
default_target: all
.PHONY : default_target

# The shell in which to execute make rules.
SHELL = /bin/sh

# Escaping for special characters.
#EQUALS = =

# The main recursive all build targets.
all: buildMyProg
all: buildMyLib
.PHONY : all

# The main recursive "clean" target.
clean: cleanMyProg
clean: cleanMyLib
.PHONY : clean

buildMyProg: buildMyLib
	c++ main.cpp -o letsSearch -L. -lsearcher -lpthread -I searchLib

cleanMyProg:
	rm letsSearch

buildMyLib:
	c++ -c searchLib/Searcher.cpp -o searcher.o
	ar -rcs libsearcher.a searcher.o

cleanMyLib:
	rm searcher.o libsearcher.a
