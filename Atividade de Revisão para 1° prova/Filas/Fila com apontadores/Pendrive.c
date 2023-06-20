/***********************************************************
* Nome: fila com apontadores                               *
* Autor: Eliseu Salomão                                    *
* Professor: Mayrton Dias                                  *
* Disciplina: Estrutura de Dados                           *
* Descrição: implementação de fila com apontadores, com as *
*            operações de:  criar fila,                    *                   
*                           enqueue,                       *
*                           dequeue e                      *
*                           excluir fila                   *         
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct computador Computador;
typedef struct pendrive Pendrive;

struct computador {
  Pendrive *inicio;
  Pendrive *fim;
};

struct pendrive {
  Pendrive *prox;
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
    printf("O pendrive não foi inserido corramente.\n");
    return NULL;
  }

  memoria->inicio = NULL;
  memoria->fim = NULL;

  return memoria;
}

/* Nome: enqueue
 * Parametro: a própria fila, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos na fila
 */
int enqueue(Computador* pendrive, char *nome, float tamanho, char *data) {
  Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive));

  if (memoria == NULL) {
    printf("O pendrive não foi inserido corretamente.\n");
    return 0;
  }

  memoria->nome = malloc(strlen(nome) + 1);
  memoria->data = malloc(strlen(data) + 1);

  strcpy(memoria->nome, nome);
  memoria->tamanho = tamanho;
  strcpy(memoria->data, data);
  memoria->prox = NULL;

  if (pendrive->inicio == NULL) {
    pendrive->inicio = memoria;
    pendrive->fim = memoria;

    printf("O arquivo %s foi inserido na fila\n", nome);
    return 1;
  }

  pendrive->fim->prox = memoria;
  pendrive->fim = memoria;

  printf("%s foi inserido na fila\n", nome);
  return 1;
}

/* Nome: dequeue
 * Parametro: a própria fila
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para remover elementos da fila
 */

int dequeue(Computador* pendrive) {
  Pendrive *p;

  if (pendrive->inicio == NULL) {
    printf("O pendrive está vazio.\n");
    return 0;
  }

  if (pendrive->inicio == pendrive->fim) {
    p = pendrive->inicio;
    pendrive->inicio = NULL;
    pendrive->fim = NULL;
    printf("Removendo o arquivo %s da fila\n", p->nome);
    free(p);
    return 1;
  }

  p = pendrive->inicio;
  pendrive->inicio = pendrive->inicio->prox;
  printf("Removendo o arquivo %s da fila\n", p->nome);
  free(p);
  return 1;
}

/* Nome: excluirFila
 * Parametro: a própria fila.       
 * Retorno: retorna nulo.
 * Descricao: função implementada para excluir toda a fila.
 */
Computador* excluirFila(Computador *pendrive) {
  Pendrive *aux;

  while(pendrive->inicio != NULL) {
    aux = pendrive->inicio;
    pendrive->inicio = pendrive->inicio->prox;
    printf("Removendo o arquivo %s da fila\n", aux->nome);
    free(aux);
  }

  printf("\nFila excluida com sucesso.\n");

  return NULL;
}

int main() {
	Computador *pendrive;
	pendrive = criarFila();

	int opcaoEscolhida;
	printf("Escolha a operacao a ser realizada:\n 1. enqueue\n 2. dequeue\n 3. excluir fila\n");
	printf("Insira aqui: ");
	scanf("%d", &opcaoEscolhida);

  while (opcaoEscolhida > 0) {
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

    printf("\n");

    fflush(stdin);

    printf("Escolha a operacao a ser realizada:\n 1. enqueue\n 2. dequeue\n 3. excluir fila\n");
    printf("Insira aqui: ");
    scanf("%d", &opcaoEscolhida);
  }
}

