RUNNER=gcc
ARQ_ZIP=Entrega.zip

all: pilha.o
	$(RUNNER) main.c pilha.o -o main

run:
	./main

pilha.o: pilha.c

debug: pilha.o
	$(RUNNER) main.c pilha.o -g -o debug

clear:
	rm *.o main debug $(ARQ_ZIP)

zip:
	zip $(ARQ_ZIP) main.c Makefile pilha.c pilha.h