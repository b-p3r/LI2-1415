SHELL := /bin/bash

CC = gcc 

CFLAGS = -ansi -Wall -Wextra -pedantic -O2 #PROGS =repDados\

all: doc compress clean

test: tarefa2 cadeias

doc: 
	doxygen Doxyfile

compress: identificacao  ./code ./doc 
	#tar jcf PLg039-et1.tar.bz2 identificacao analise.pdf code doc
	tar jcf PLg039-et1.tar.bz2 identificacao code doc

analise.pdf:  report/rel.tex 
	pdflatex report/rel.tex 
	pdflatex report/rel.tex
	pdflatex report/rel.tex 
	mv rel.pdf analise.pdf 
	rm -fr rel.* 
	rm -fr report/chapters/*.aux
	#rm -r report
#tarefa1: ./code/tproc.c

tarefa2: ./code/tarefa2.c 
	$(CC) $(CFLAGS) -o tarefa2 ./code/tarefa2.c

cadeias: ./code/tproc.o ./code/cadeias.o 
	$(CC) $(CFLAGS) -o tproc ./code/tproc.o ./code/cadeias.o 
	#$(CC) $(CFLAGS) -o tproc tproc.c cadeias.c
 
#tproc.o: ./code/tproc.c ./code/cadeias.h 
#	$(CC) $(CFLAGS) -c ./code/tproc.c


tarefa1: cadeias.o t1proc.o tarefa1.o
	$(CC) $(CFLAGS) -o tarefa1 t1proc.o cadeias.o tarefa1.o
	rm -r ./*.o

tarefa1.o: ./code/t1proc.c ./code/cadeias.h ./code/t1proc.h
	$(CC) $(CFLAGS) -c ./code/tarefa1.c

cadeias.o: ./code/cadeias.c ./code/cadeias.h 
	$(CC) $(CFLAGS) -c ./code/cadeias.c

t1proc.o: ./code/t1proc.c ./code/t1proc.h
	 $(CC) $(CFLAGS) -c ./code/t1proc.c

# escrever make clean para limpar pasta do código fonte 
clean: 
	rm -r ./*.o 
	rm -f tproc 
	rm -f tarefa2
	rm -r ./doc/html



#tpc2: 
#
#	$(CC) -Wall -O2 -S soma.c
#
#tpc3: 
#
#	$(CC) -Wall -O2 -c soma.c
#diss3:
#	objdump -d soma.o
#
#link:
#	$(CC) -Wall -O2 -o prog prog.c soma.o
#
#diss4:
#
#	objdump -d prog > prog.dump
#
#clean:
#	rm -f ./*.o
#	
#	rm -f ./*.s

	
