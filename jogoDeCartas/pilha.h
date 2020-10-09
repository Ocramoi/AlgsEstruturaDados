#ifndef _PILHA
#define _PILHA

#include <stdlib.h>
#include <assert.h>

typedef struct {
    int topo;
    int *cartas;
} pilha; // tipo estrutura da pilha

// declaração das funções de pilha (implementação em pilha.c)

pilha* criaPilha();
void destroiPilha(pilha*);
int checaVazia(pilha*);
int push(pilha*, int);
int pop(pilha*, int*);
int top(pilha*, int*);
int numElem(pilha*);

#endif