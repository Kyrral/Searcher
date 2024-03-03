default_target: all
.PHONY : default_target

SHELL = /bin/sh

all: buildMyProg
all: buildMyLib
.PHONY : all

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
