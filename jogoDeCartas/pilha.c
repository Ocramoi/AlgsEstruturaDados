#include "pilha.h"

/**
 * Aloca a estrutura da pilha dinâmica e retorna seu ponteiro
 */
pilha* criaPilha()
{
    pilha *p = (pilha*) malloc(sizeof(pilha));
    assert(p != NULL);

    p->topo = -1;
    p->cartas = NULL;

    return p;
}

/**
 * Realoca o vetor de cartas, atualiza o topo e adiciona a nova carta se a pilha existe
 */
int push(pilha *p, int carta)
{
    assert(p != NULL);

    p->topo++;
    p->cartas = realloc(p->cartas, (p->topo + 1) * sizeof(int));

    p->cartas[p->topo] = carta;

    return 1;
}

/**
 * Retorna a carta no topo da pilha, se existe
 */
int top(pilha *p, int *v)
{
    assert(p != NULL && p->topo != -1);
    
    *v = p->cartas[p->topo];
    return 1;
}

/**
 * Retorna a carta no topo da pilha e a retira do monte, atualizando o vetor e o topo, caso exista a pilha
 */
int pop(pilha *p, int *v)
{
    assert(p != NULL && p->topo != -1);
    
    top(p, v);
    p->topo--;
    p->cartas = realloc(p->cartas, (p->topo + 1) * sizeof(int));
    return 1;
}

/**
 * Checa se a pilha está vazia (topo == -1) caso exista
 */
int checaVazia(pilha *p)
{
    assert(p != NULL);

    if(p->topo == -1) 
        return 1;
    return 0;
}

/**
 * Libera memória alocada referente a pilha caso exista
 */
void destroiPilha(pilha *p)
{
    assert(p != NULL);
    free(p->cartas);
    free(p);
}

/**
 * Retorna o npumero de cartas (topo + 1) caso exista a pilha
 */
int numElem(pilha *p)
{
    assert(p != NULL);
    return p->topo + 1;
}