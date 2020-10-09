#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

#define NUM_FILAS 4
#define BUFFER_NOME 64

typedef struct
{
    char nome[BUFFER_NOME],
         condicao;
    int idade;
} PESSOA; // Estrutura de dados de pessoas para a fila

#define STR_BUFFER 64 // buffer do realloc de string

char *readLine (FILE* entrada) { // função que lê string com tratamento
    char *retorno = NULL; // inicializa o ponteiro da frase lida
    int cont = 0; // inicializa a varável que auxiliará o tratamento de tamanho

    do {
        if (cont % STR_BUFFER == 0) { // conferência do tamanho como próximo múltiplo do buffer
            retorno = (char* ) realloc(retorno, ((cont/STR_BUFFER + 1) * STR_BUFFER) * sizeof(char)); // aumenta o tamanho da string em função do buffer caso tenha ultrapassado um novo múltiplo, diminuindo o gasto computacional com realocação
        }
        retorno[cont] = fgetc(entrada); // lê novo caracter
        cont++; // atualiza o tamanho da string
    } while (retorno[cont-1] != '\n' && retorno[cont-1] != EOF); // repete até o final da leitura de string

    if (cont >= 2 && retorno[cont - 2] == '\r') { // confere pelo caracter de formatação '\r'
        retorno[cont - 2] = '\0'; // substitui o caracter por fim de string
        retorno = (char* ) realloc(retorno, (cont-1) * sizeof(char)); // diminui o tamanho da string em 1 caracter
    }
     else {
        retorno[cont-1] = '\0'; // formata a string com o caracter de final de string
        retorno = (char* ) realloc(retorno, cont * sizeof(char)); // realoca o ponteiro da string para seu tamanho desconsiderando o buffer
    }

    return retorno;
}

int numDigitos(int val) // Retorna o número de digitos do valor passado
{
    int num = 1;
    while (val /= 10) num++;
    return num;
}

int main(void)
{
    int tamanho; scanf("%d", &tamanho); // Lê a quantidade operações

    FILA **filas = malloc(NUM_FILAS * sizeof(FILA));
    for (int i = 0; i < NUM_FILAS; ++i)
        filas[i] = criaFila(tamanho); // Cria as filas com tamanho máximo do número de pessoas possível
    
    for (int i = 0; i < tamanho + 1; ++i) { // Loop pelas operações
        char *temp = readLine(stdin); // Lê a linha inserida
        if (strlen(temp) == 0) continue; // Trata leitura
        if(!strncmp(temp, "ENTRA", 5)) { // Confere por entrada
            PESSOA *pes = malloc(sizeof(PESSOA)); // Cria novo elemento de pessoa
            int offset = 6; // Inicializa o offset de leitura
            // Lê todos os dados a partir da stream inicial e offsets atualizados
            sscanf(temp + offset, "%s", pes->nome); offset += strlen(pes->nome) + 1;
            sscanf(temp + offset, "%d", &pes->idade); offset += numDigitos(pes->idade) + 1;
            sscanf(temp + offset, "%c", &pes->condicao);
            
            // Adiciona a pessoa a fila correta
            if(pes->idade >= 60) {
                if (pes->condicao == '1') inserir(filas[0], pes);
                else inserir(filas[2], pes);
            }
            else {
                if (pes->condicao == '1') inserir(filas[1], pes);
                else inserir(filas[3], pes);
            }
        }
        else {
            // Lê o primeiro da fila em ordem de prioridade
            PESSOA *pes = NULL;
            if (!isEmpty(filas[0])) remover(filas[0], (void **) &pes);
            else if (!isEmpty(filas[1])) remover(filas[1], (void **) &pes);
            else if (!isEmpty(filas[2])) remover(filas[2], (void **) &pes);
            else if (!isEmpty(filas[3])) remover(filas[3], (void **) &pes);
            
            // Exibe a mensagem correta
            if(pes == NULL) printf("FILA VAZIA\n");
            else printf("%s %d %c\n", pes->nome, pes->idade, pes->condicao);
        }
        free(temp); // Libera a memória da linha lida
    }

    // Libera a memória referente às filas
    for (int i = 0; i < NUM_FILAS; ++i)
        destroiFila(filas[i]);
    free(filas);

    return 0;
}
