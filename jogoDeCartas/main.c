#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

/**
 * Inverte a pilha para ser devolvida ao monte de compra
 */
pilha* invertePilha(pilha *p)
{
    pilha *invertida = criaPilha(); // cria nova pilha
    int temp;
    while(numElem(p) > 0) {
        pop(p, &temp);
        push(invertida, temp); // copia todos os elementos invertido por razão do funcionamento da pilha
    }
    destroiPilha(p);
    return invertida; // destroi a pilha original e retorna a invertida
}

int main(void)
{
    pilha *compra = criaPilha(),
          *descarte = criaPilha(),
          *morto = criaPilha(); // cria montes

    // realiza a leitura do monte de compra
    int num,
        temp,
        passagens = 1;
    scanf("%d", &num);
    
    for(int i = 0; i < num; ++i) {
        scanf("%d", &temp);
        push(compra, temp);
    }

    int atual = 1;
    while (numElem(morto) < num) { // enquanto não completo o morto
        compra = invertePilha(compra);
        while(numElem(compra) > 0) { // para todas as cartas no monte de compra
            pop(compra, &temp);
            if (temp == atual) {
                push(morto, temp);
                atual++;
            }
            else
                push(descarte, temp); // passa a carta para o monte correto
        }
        if (numElem(morto) < num) { // se necessário realiza a passagem
            pilha *troca = compra;
            compra = descarte;
            descarte = troca;
            passagens++;
        }
    }
    printf("%d\n", passagens); // exibe o número de passagens 

    destroiPilha(compra); destroiPilha(descarte); destroiPilha(morto); // destroi a memória alocada

    return 0;
}