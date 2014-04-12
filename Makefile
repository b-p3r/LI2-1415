SHELL := /bin/bash

#.PHONY: test 

# escrever comando make test para compilar este target ( ou simplesmente make)
test: tproc.o cadeias.o
	gcc -o tproc tproc.o cadeias.o
	#gcc -o tproc tproc.c cadeias.c
 
tproc.o: tproc.c cadeias.h
	gcc -c tproc.c

cadeias.o: cadeias.c cadeias.h
	gcc -c cadeias.c

# escrever make clean para limpar pasta do código fonte 
clean:
	rm -r ./*.o
	rm -r tproc
