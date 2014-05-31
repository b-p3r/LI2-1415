SHELL := /bin/bash

CC = gcc 

CFLAGS = -ansi -Wall -Wextra -pedantic -O2 

all: doc compress clean



all2: tarefa5 tarefa4 tarefa3 tarefa2 tarefa1 clean 

clean: 
	@echo "A limpar diretoria...."
	rm -rf *.o
	rm -rf code/*.o
	rm -rf ./doc

clean_exec:
	@echo "A eliminar executáveis...."
	rm -f tarefa1 
	rm -f tarefa2
	rm -f tarefa3
	rm -f tarefa4
	rm -f tarefa5

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

tarefa5: ./code/cadeias.o ./code/proc_dict.o code/proc_sopa.o code/coord.o ./code/search_m.o ./code/trie_t.o ./code/utils.o ./code/tarefa5.o
	@echo "A compilar tarefa5...."
	$(CC) $(CFLAGS) -o tarefa5 code/cadeias.o code/proc_dict.o ./code/search_m.o  ./code/trie_t.o ./code/utils.o code/proc_sopa.o code/coord.o code/tarefa5.o
	rm -f ./*.o

tarefa5.o: ./code/cadeias.h ./code/proc_sopa.h ./code/coord.h ./code/tarefa5.c
	$(CC) $(CFLAGS) -c code/tarefa5.c

utils.o: ./code/utils.c ./code/utils.h
	$(CC) $(CFLAGS) -c ./code/utils.c

trie_t.o: ./code/trie_t.c ./code/trie_t.h
	$(CC) $(CFLAGS) -c ./code/trie_t.c

search_m.o: ./code/search_m.c ./code/search_m.h
	$(CC) $(CFLAGS) -c ./code/search_m.c

################################ - Tarefa 4 - ###########################################
#
#
#tarefa4: ./code/cadeias.o ./code/proc_dict.o ./code/tarefa3.o
#	@echo "A compilar tarefa3...."
#	$(CC) $(CFLAGS) -o tarefa3 code/cadeias.o code/proc_dict.o code/tarefa3.o
#	rm -f ./*.o


tarefa4: ./code/cadeias.o ./code/proc_sopa.o code/trie_t.o ./code/coord.o ./code/utils.o ./code/tarefa4.o
	@echo "A compilar tarefa4...."
	$(CC) $(CFLAGS) -o tarefa4 code/cadeias.o code/trie_t.o code/proc_sopa.o ./code/utils.o code/coord.o code/tarefa4.o




tarefa4.o: ./code/cadeias.h ./code/proc_sopa.h ./code/coord.o ./code/tarefa4.c	
	$(CC) $(CFLAGS) -c code/tarefa4.c

coord.o: ./code/coord.c ./code/coord.h
	$(CC) $(CFLAGS) -c ./code/coord.c

############################### - Tarefa 3 - ###########################################

tarefa3: ./code/cadeias.o ./code/trie_t.o ./code/utils.o ./code/tarefa3.o
	@echo "A compilar tarefa3...."
	$(CC) $(CFLAGS) -o tarefa3 code/cadeias.o ./code/utils.o code/trie_t.o code/tarefa3.o


tarefa3.o: ./code/cadeias.h ./code/proc_dict.h ./code/tarefa3.c	
	$(CC) $(CFLAGS) -c code/tarefa3.c


proc_sopa.o: ./code/proc_sopa.c ./code/proc_sopa.h
	$(CC) $(CFLAGS) -c ./code/proc_sopa.c





############################### - Tarefa 2 - ###########################################


tarefa2: ./code/cadeias.o ./code/proc_sopa.o code/coord.o code/tarefa2.o
	@echo "A compilar tarefa2...."
	$(CC) $(CFLAGS) -o tarefa2 code/cadeias.o code/coord.o code/proc_sopa.o code/tarefa2.o


tarefa2.o: ./code/cadeias.h ./code/proc_sopa.h ./code/tarefa2.c	
	$(CC) $(CFLAGS) -c code/tarefa2.c


proc_dict.o: ./code/proc_sopa.c ./code/proc_sopa.h
	$(CC) $(CFLAGS) -c ./code/proc_sopa.c



############################### - Tarefa 1 - ###########################################

cadeias: ./code/tproc.o ./code/cadeias.o 
	$(CC) $(CFLAGS) -o tproc ./code/tproc.o ./code/cadeias.o 
 

tarefa1: ./code/tarefa1.o ./code/cadeias.o ./code/t1proc.o 
	@echo "A compilar tarefa1...."
	$(CC) $(CFLAGS) -o tarefa1 ./code/cadeias.o ./code/t1proc.o ./code/tarefa1.o

	
tarefa1.o: ./code/cadeias.h ./code/t1proc.h ./code/tarefa1.c
	$(CC) $(CFLAGS) -c ./code/tarefa1.c

t1proc.o: ./code/t1proc.c ./code/t1proc.h
	$(CC) $(CFLAGS) -c ./code/t1proc.c

cadeias.o: ./code/cadeias.c ./code/cadeias.h 
	$(CC) $(CFLAGS) -c ./code/cadeias.c


