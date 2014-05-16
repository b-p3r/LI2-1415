SHELL := /bin/bash

CC = gcc 

CFLAGS = -ansi -Wall -Wextra -pedantic -O2 #PROGS =repDados\

all: doc compress clean



all2: tarefa3 tarefa2 tarefa1

clean: 
	@echo "A limpar diretoria...."
	rm -rf *.o
	rm -rf code/*.o
	#rm -f tarefa1 
	#rm -f tarefa2
	#rm -f tarefa3
	rm -f tarefa4
	rm -rf ./doc


############################# - Documentação - #########################################
doc: 
	@echo "A gerar nova documentação......"
	doxygen Doxyfile

#analise.pdf:  report/rel.tex 
#       pdflatex report/rel.tex pdflatex report/rel.tex pdflatex
#       #       report/rel.tex mv rel.pdf analise.pdf rm -fr rel.* rm -fr
#       report/chapters/*.aux #rm -r report


compress: identificacao  ./code ./doc
	@echo "Preparar ficheiro Bzip para entrega...."
	#tar jcf PLg039-et1.tar.bz2 identificacao analise.pdf code doc
	#tar jcf PLg039-et1.tar.bz2 identificacao code doc
	tar jcf PLg039-et2.tar.bz2 identificacao code doc


############################### - Tarefa 5 - ###########################################

#tarefa5: ./code/cadeias.o ./code/proc_dict.o ./code/tarefa3.o
#	@echo "A compilar tarefa3...."
#	$(CC) $(CFLAGS) -o tarefa3 code/cadeias.o code/proc_dict.o code/tarefa3.o
#	rm -f ./*.o
#
#
#
################################ - Tarefa 4 - ###########################################
#
#
#tarefa4: ./code/cadeias.o ./code/proc_dict.o ./code/tarefa3.o
#	@echo "A compilar tarefa3...."
#	$(CC) $(CFLAGS) -o tarefa3 code/cadeias.o code/proc_dict.o code/tarefa3.o
#	rm -f ./*.o




############################### - Tarefa 3 - ###########################################

tarefa3: ./code/cadeias.o ./code/proc_dict.o ./code/tarefa3.o
	@echo "A compilar tarefa3...."
	$(CC) $(CFLAGS) -o tarefa3 code/cadeias.o code/proc_dict.o code/tarefa3.o
	rm -f ./*.o

tarefa3.o: ./code/cadeias.h ./code/proc_dict.h ./code/tarefa3.c	
	$(CC) $(CFLAGS) -c code/tarefa3.c


proc_dict.o: ./code/proc_dict.c ./code/proc_dict.h
	$(CC) $(CFLAGS) -c ./code/proc_dict.c


############################### - Tarefa 2 - ###########################################
tarefa2: ./code/tarefa2.c 
	@echo "A compilar tarefa2...."
	$(CC) $(CFLAGS) -o tarefa2 ./code/tarefa2.c
	rm -f ./*.o

############################### - Tarefa 1 - ###########################################

cadeias: ./code/tproc.o ./code/cadeias.o 
	$(CC) $(CFLAGS) -o tproc ./code/tproc.o ./code/cadeias.o 
 

tarefa1: tarefa1.o cadeias.o t1proc.o 
	@echo "A compilar tarefa1...."
	$(CC) $(CFLAGS) -o tarefa1 cadeias.o t1proc.o tarefa1.o
	rm -f ./*.o
	
tarefa1.o: ./code/cadeias.h ./code/t1proc.h ./code/tarefa1.c
	$(CC) $(CFLAGS) -c ./code/tarefa1.c

t1proc.o: ./code/t1proc.c ./code/t1proc.h
	$(CC) $(CFLAGS) -c ./code/t1proc.c

cadeias.o: ./code/cadeias.c ./code/cadeias.h 
	$(CC) $(CFLAGS) -c ./code/cadeias.c


