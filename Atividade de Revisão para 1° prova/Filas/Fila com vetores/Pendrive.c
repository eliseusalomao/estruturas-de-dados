/***********************************************************
* Nome: fila com vetores                                   *
* Autor: Eliseu Salomão                                    *
* Professor: Mayrton Dias                                  *
* Disciplina: Estrutura de Dados                           *
* Descrição: implementação de fila com vetores, com as     *
*            operações de:  criar fila,                    *                   
*                           enqueue,                       *
*                           dequeue e                      *
*                           excluir fila                   *         
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 30

typedef struct computador Computador;
typedef struct pendrive Pendrive;

struct computador {
  int inicio;
  int fim;
  Pendrive *elementos;
};

struct pendrive {
	char *nome;
	float tamanho;
	char *data;
};

/* Nome: criarFila
 * Parametro: nenhum          
 * Retorno: retorna um endereço reservado por malloc
 * Descricao: função implementada para criar a fila
 */
Computador* criarFila() {
  Computador *memoria = (Computador*)malloc(sizeof(Computador));

  if (memoria == NULL) {
    printf("O espaço para os arquivos é insuficiente.\n");
    return 0;
  }

  memoria->inicio = 0;
  memoria->fim = 0;
  memoria->elementos = (Pendrive*)malloc(TAM*sizeof(Pendrive));

  if (memoria->elementos == NULL) {
    printf("O espaço para os arquivos é insuficiente.\n");
    free(memoria);
    return NULL;
  }

  return memoria;
}

/* Nome: enqueue
 * Parametro: a própria fila, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos na fila
 */
int enqueue(Computador* pendrive, char *nome, float tamanho, char *data) {

  if (pendrive == NULL) {
    printf("O pendrive não foi inserido corretamente.\n");
    return -1;
  }

  pendrive->elementos[pendrive->fim].nome = malloc(sizeof(nome) + 1);
  pendrive->elementos[pendrive->fim].data = malloc(sizeof(data) + 1);

  if ((pendrive->fim + 1) % TAM != pendrive->inicio) {
    strcpy(pendrive->elementos[pendrive->fim].nome, nome);
    pendrive->elementos[pendrive->fim].tamanho = tamanho;
    strcpy(pendrive->elementos[pendrive->fim].data, data);
    printf("O elemento %s foi inserido com sucesso.\n", pendrive->elementos[pendrive->fim].nome);
    pendrive->fim = (pendrive->fim + 1) % TAM;
  }
  else {
    printf("Espaço esgotado.\n");
    return -1;
  }

  return 0;
}

/* Nome: dequeue
 * Parametro: a própria fila
 * Retorno: retorna um inteiro contendo o valor que será removido.
 * Descricao: função implementada para remover elementos da fila
 */
int dequeue(Computador* pendrive) {
  int aux = 0;

  if (pendrive == NULL) {
    printf("O pendrive não foi inserido corretamente.\n");
    return -1;
  }

  if (pendrive->fim == 0) {
    printf("O pendrive esta vazio.\n");
    return -1;
  }

  if (((pendrive->inicio + 1) % TAM) == pendrive->fim) {
    printf("Removendo o arquivo %s da fila\n", pendrive->elementos[pendrive->inicio].nome);
    pendrive->inicio = 0;
    pendrive->fim = 0;
    return 0;
  }

  if (((pendrive->inicio + 1) % TAM) <= pendrive->fim) {
    printf("Removendo o arquivo %s da fila\n", pendrive->elementos[pendrive->inicio].nome);
    strcpy(pendrive->elementos[pendrive->inicio].nome, pendrive->elementos[pendrive-> inicio + 1].nome);
    pendrive->elementos[pendrive->inicio].tamanho = pendrive->elementos[pendrive-> inicio + 1].tamanho;
    strcpy(pendrive->elementos[pendrive->inicio].data, pendrive->elementos[pendrive-> inicio + 1].data);
    pendrive->inicio = (pendrive->inicio + 1) % TAM;
    return 0;
  }

  return -1;
}

/* Nome: excluirFila
 * Parametro: a própria fila.       
 * Retorno: retorna nulo.
 * Descricao: função implementada para excluir toda a fila.
 */
Computador* excluirFila(Computador *pendrive) {
  free(pendrive->elementos);
  free(pendrive);

  printf("\nFila excluida com sucesso.\nFinalizando programa...\n");
  printf("\n\n\t\tGOODBYE...\n\n");

  return NULL;
}

int main() {
	Computador *pendrive;
	pendrive = criarFila();

	int opcaoEscolhida;

  do {

    printf("Escolha a operacao a ser realizada:\n 1. enqueue\n 2. dequeue\n 3. excluir fila\n");
    printf("Insira aqui: ");
    scanf("%d", &opcaoEscolhida);

    switch (opcaoEscolhida) {
      case 1:
        char nome[30], data[30];
        float tamanho;

        printf("Nome do arquivo que deseja inserir: ");
        scanf("%s", nome);
        printf("Tamanho do arquivo: ");
        scanf("%f", &tamanho);
        printf("Data de criação do arquivo: ");
        scanf("%s", data);	

        enqueue(pendrive, nome, tamanho, data);
        break;
      case 2:
        dequeue(pendrive);
        break;
      case 3:
        excluirFila(pendrive);
        break;
      default: 
        printf("Opcao inválida.\n");
    }

  } while (opcaoEscolhida > 0 && opcaoEscolhida != 3);
}
