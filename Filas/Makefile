COMPILER=gcc
EXEC=filas

all: fila.o
	$(COMPILER) main.c fila.o -o $(EXEC) -g

run:
	./$(EXEC)

debug:
	valgrind ./$(EXEC)

entrega:
	zip Entrega.zip main.c Makefile fila.h fila.c

clear:
	rm *.o $(EXEC) *.zip

fila.o:
	$(COMPILER) fila.c -c -g