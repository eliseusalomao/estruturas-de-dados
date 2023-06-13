/***********************************************************
* Nome: pilha com apontadores                              *
* Autor: Eliseu Salomão                                    *
* Professor: Mayrton Dias                                  *
* Disciplina: Estrutura de Dados                           *
* Descrição: implementação de lista com vetor, com as      *
*            operações de:  criar pilha,                   *   
*                           push,                          *
*                           pop,                           *
*                           ehVazia,                       *
*                           verTopo,                       *
*                           excluir pilha.                 *
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct computador Computador;
typedef struct pendrive Pendrive;

struct computador {
  Pendrive *topo;
};

struct pendrive {
  char *nome;
  float tamanho;
  char *data;
  Pendrive *prox;
};

/* Nome: criarPilha
 * Parametro: nenhum          
 * Retorno: retorna um endereço reservado por malloc
 * Descricao: função implementada para criar a pilha
 */
Computador* criarPilha() {
  Computador *memoria = (Computador*)malloc(sizeof(Computador));

  if (memoria == NULL) {
    return NULL;
  }

  memoria->topo = NULL;

  return memoria;
}

/* Nome: push
 * Parametro: a própria pilha e nome, tamanho e data.          
 * Retorno: retorna um inteiro que indica se a operação foi bem sucedida.
 * Descricao: função implementada para inserir um elemento na pilha.
 */
int push(Computador *pendrive, char *nome, float tamanho, char *data) {
  Pendrive *p, *memoria = (Pendrive*)malloc(sizeof(Pendrive));

  if (memoria == NULL) {
    return 0;
  }

  memoria->nome = malloc(strlen(nome) + 1);
  memoria->data = malloc(strlen(data) + 1);

  strcpy(memoria->nome, nome);
  memoria->tamanho = tamanho;
  strcpy(memoria->data, data);
  memoria->prox = pendrive->topo;
  pendrive->topo = memoria;

  return 1;
}

/* Nome: push
 * Parametro: a própria pilha.          
 * Retorno: retorna um ponteiro para o elemento que se pretende remover.
 * Descricao: função implementada para remover um elemento da pilha.
 */
Pendrive* pop(Computador *pendrive) {
  Pendrive *aux;
  
  if (pendrive == NULL) {
    return 0;
  }

  aux = pendrive->topo;
  pendrive->topo = pendrive->topo->prox;
  return aux;
}

/* Nome: verTopo
 * Parametro: a própria pilha.          
 * Retorno: o retorno é vazio.
 * Descricao: função implementada para visualizar o elemento no topo da pilha.
 */
void verTopo(Computador *pendrive) {
  if (pendrive == NULL) {
      return ;
  }

  printf("%s - %.2f - %s\n", 
        pendrive->topo->nome, 
        pendrive->topo->tamanho, 
        pendrive->topo->data);

  return ;
}

/* Nome: ehVazia
 * Parametro: a própria pilha.        
 * Retorno: retorna um inteiro que indica se a operação foi bem sucedida.
 * Descricao: função implementada para verificar se a pilha é vazia.
 */
int ehVazia(Computador *pendrive) {
  if (pendrive == NULL) {
      return 1;
  }
  
  if (pendrive->topo == NULL) {
    return 1;
  }

  return 0;
}

/* Nome: excluirPilha
 * Parametro: a própria pilha.       
 * Retorno: retorna nulo.
 * Descricao: função implementada para excluir toda a pilha.
 */
Computador* excluirPilha(Computador *pendrive) {
  Pendrive *aux;

  while (pendrive->topo != NULL) {
    aux = pendrive->topo;
    pendrive->topo = pendrive->topo->prox;
    free(aux);
  }

  free(pendrive);

  return NULL;
}

int main() {
  Computador *pendrive;
  pendrive = criarPilha();

  int opcaoEscolhida;

  printf("Escolha a operação  a ser realizada:\n1. Inserir arquivos\n2. Remover arquivos\n3. Verificar se o pendrive está vazio\n4. Ver o primeiro elemento (o que se encontra no topo da pilha)\n5. Remover pendrive (excluir pilha)\nInsira aqui: ");

  scanf("%d", &opcaoEscolhida);

  while (opcaoEscolhida >= 1) {
    printf("\n");

    switch (opcaoEscolhida) {
      case 1:
        char nomeArquivoInserir1[30], dataArquivoInserir1[30];
        float tamanhoInserir1;

        printf("Nome do arquivo: ");
        scanf("%s", nomeArquivoInserir1);
        printf("Tamanho do arquivo: ");
        scanf("%f", &tamanhoInserir1);
        fflush(stdin);
        printf("Data de criação: ");
        scanf("%s", dataArquivoInserir1);

        push(pendrive, nomeArquivoInserir1, tamanhoInserir1, dataArquivoInserir1);
        break;
      case 2:
        pop(pendrive);
        break;
      case 3:
        int tamanho = ehVazia(pendrive);
        if (tamanho != 1) {
          printf("O pendrive não esta vazio.\n");
        } else {
          printf("O pendrive está vazio.\n");
        }
        break;
      case 4:
        verTopo(pendrive);
        break;
      case 5:
        excluirPilha(pendrive);
        break;
    }

    printf("\n");

    printf("Escolha a operação  a ser realizada:\n1. Inserir arquivos\n2. Remover arquivos\n3. Verificar se o pendrive está vazio\n4. Ver o primeiro elemento (o que se encontra no topo da pilha)\n5. Remover pendrive (excluir pilha)\nInsira aqui: ");
    scanf("%d", &opcaoEscolhida);
  }
}