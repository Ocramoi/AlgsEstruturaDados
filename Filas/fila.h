#ifndef _FILA
#define _FILA

typedef struct {
    int inicio, 
        fim, 
        total, 
        tamanho;
	void **itens;
} FILA;

FILA *criaFila(int); // Cria a fila com o tamanho indicado e retorna seu ponteiro
int isEmpty(FILA *f); // Confere se a lista existe e retorna se está vazia
int isFull(FILA *f); // Confere se a lista existe e retorna se está cheia
int inserir(FILA *f, void *x); // Confere se a lista existe e não está cheia, então adiciona o elemento
int remover(FILA *f, void **x); // Confere se a lista existe e não está vazia, então remove o elemento correto e o retorna por referência
void destroiFila(FILA *f);// Confere se a lista existe, então remove sua memória alocada

#endif