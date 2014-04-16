SHELL := /bin/bash

CC = gcc 

CFLAGS = -ansi -Wall -Wextra -pedantic -O2 #PROGS =repDados\

all: doc compress clean



all2: tarefa2 tarefa1

doc: 
	doxygen Doxyfile

compress: identificacao  ./code ./doc 
	#tar jcf PLg039-et1.tar.bz2 identificacao analise.pdf code doc
	tar jcf PLg039-et1.tar.bz2 identificacao code doc

#analise.pdf:  report/rel.tex 
#	pdflatex report/rel.tex 
#	pdflatex report/rel.tex
#	pdflatex report/rel.tex 
#	mv rel.pdf analise.pdf 
#	rm -fr rel.* 
#	rm -fr report/chapters/*.aux
#	#rm -r report
#
tarefa2: ./code/tarefa2.c 
	$(CC) $(CFLAGS) -o tarefa2 ./code/tarefa2.c

cadeias: ./code/tproc.o ./code/cadeias.o 
	$(CC) $(CFLAGS) -o tproc ./code/tproc.o ./code/cadeias.o 
 

tarefa1: tarefa1.o cadeias.o t1proc.o 
	$(CC) $(CFLAGS) -o tarefa1 cadeias.o t1proc.o tarefa1.o
	rm -r ./*.o
tarefa1.o: ./code/cadeias.h ./code/t1proc.h ./code/tarefa1.c
	$(CC) $(CFLAGS) -c ./code/tarefa1.c

t1proc.o: ./code/t1proc.c ./code/t1proc.h
	$(CC) $(CFLAGS) -c ./code/t1proc.c

cadeias.o: ./code/cadeias.c ./code/cadeias.h 
	$(CC) $(CFLAGS) -c ./code/cadeias.c


clean: 
	rm -rf *.o 
	rm -f tarefa1 
	rm -f tarefa2
	rm -rf ./doc
