SHELL := /bin/bash

CC = gcc CFLAGS = -ansi -Wall -Wextra -pedantic -O2 #PROGS =repDados\
#	tamTipos\
#all: $(PROGS)
#
#repDados: mostra_octetos.c repDados.c
#
#$(CC) $(CFLAGS) mostra_octetos.c repDados.c -o repDados
#
#tamTipos: tamTipos.c
#
#$(CC) $(CFLAGS) tamTipos.c -o tamTipos
#
#clean:
#	rm -f $(PROGS) *.o *~core
#.PHONY: test 

# escrever comando make test para compilar este target ( ou simplesmente make)




compress: identificacao analise.pdf ./code ./doc tar jcf PLg039-et1.tar.bz2
	identificacao analise.pdf code doc


relatorio.pdf:  report/rel.tex pdflatex report/rel.tex pdflatex report/rel.tex
	pdflatex report/rel.tex 
	mv rel.pdf relatorio.pdf 
	rm -fr rel.* 
	rm -fr
	report/chapters/*.aux
	#rm -r report

tarefa2: tarefa2.c $(CC) $(CFLAGS) -o tarefa2 tarefa2.c

cadeias: tproc.o cadeias.o $(CC) $(CFLAGS) -o tproc tproc.o cadeias.o #$(CC)
	$(CFLAGS) -o tproc tproc.c cadeias.c
 
tproc.o: tproc.c cadeias.h $(CC) $(CFLAGS) -c tproc.c

cadeias.o: cadeias.c cadeias.h $(CC) $(CFLAGS) -c cadeias.c

# escrever make clean para limpar pasta do código fonte 
clean: rm -r ./*.o rm -f tproc rm -f tarefa2



#tpc2: 
#
#	$(CC) -Wall -O2 -S soma.c
#
#tpc3: 
#
#	$(CC) -Wall -O2 -c soma.c
#
#
#
#
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

	
