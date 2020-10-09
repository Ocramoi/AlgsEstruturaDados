#include <stdlib.h>
#include <assert.h>
#include "fila.h"

// Cria a fila com o tamanho indicado e retorna seu ponteiro
FILA *criaFila(int tamanho) 
{
    // Alocação da fila
    FILA *retorno = malloc(sizeof(FILA));
    assert(retorno != NULL);
    // Inicialização dos parâmetros
    retorno->inicio = 0; retorno->fim = 0; retorno->total = 0; retorno->tamanho = tamanho;
    retorno->itens = malloc(tamanho * sizeof(void*));
    for (int i = 0; i < tamanho; ++i) retorno->itens[i] = NULL;
    // Retorno
    return retorno;
}

// Confere se a lista existe e retorna se está vazia
int isEmpty(FILA *f)
{
    assert(f != NULL);
    if (f->total == 0) return 1;
    return 0;
}

// Confere se a lista existe e retorna se está cheia
int isFull(FILA *f)
{
    assert(f != NULL);
    if(f->total == f->tamanho) return 1;
    return 0;
}

// Confere se a lista existe e não está cheia, então adiciona o elemento
int inserir(FILA *f, void *x)
{
    assert(f != NULL && !isFull(f));
    f->itens[f->fim] = x; // Adiciona o item
    // Atualiza os valores
    f->fim = (f->fim + 1) % f->tamanho;
	f->total++;
    return 1;
}

// Confere se a lista existe e não está vazia, então remove o elemento correto e o retorna por referência
int remover(FILA *f, void **x)
{
    assert(f != NULL && !isEmpty(f));
	*x = f->itens[f->inicio]; // Retorna o elemento no início da lista
	// Atualiza os valores
    f->inicio = (f->inicio + 1) % f->tamanho;
	f->total--;
	return 1;
}

// Confere se a lista existe, então remove sua memória alocada
void destroiFila(FILA *f)
{
    assert(f != NULL);
    for (int i = 0; i < f->tamanho; ++i) if(f->itens[i] != NULL) free(f->itens[i]);
    free(f->itens);
    free(f);
}