#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct computador Computador;
typedef struct pendrive Pendrive;

struct computador {
  Pendrive *prim;
};

struct pendrive {
  int id;
  char *nome;
  float tamanho;
  char *data;
  Pendrive *prox;
};

/* Nome: criarLista
 * Parametro: nenhum          
 * Retorno: retorna um endereço reservado por malloc
 * Descricao: função implementada para criar a lista
 */
Computador* criarLista() {
  Computador *memoria = (Computador*)malloc(sizeof(Computador));

  if (memoria == NULL) {
    printf("O pendrive nao tem memória.\n");
    return 0;
  }

  printf("Pendrive inserido com sucesso.\n");
  memoria->prim = NULL;

  return memoria;
}

/* Nome: inserirElemento
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos na lista
 */
int inserirElemento(
Computador *pendrive, 
char *nomeArquivo, 
float tamanhoArquivo, 
char *dataCriacao) {
  Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive));

  if (memoria == NULL) {
    printf("O pendrive não tem memória.\n");
    return 0;
  }

  memoria->nome = malloc(strlen(nomeArquivo) + 1);
  memoria->data = malloc(strlen(dataCriacao) + 1);

  strcpy(memoria->nome, nomeArquivo);
  memoria->tamanho = tamanhoArquivo;
  strcpy(memoria->data, dataCriacao);
  memoria->id = 0;
  ++(memoria->id);
  memoria->prox = NULL;

  if (pendrive->prim == NULL) {
    pendrive->prim = memoria;
    memoria->prox = memoria;
    return 1;
  }

  Pendrive *p;
  for (
    p = pendrive->prim; 
    p->prox != pendrive->prim; 
    p = p->prox);

  p->prox = memoria;
  memoria->prox = pendrive->prim;

  return 1;
}

/* Nome: inserirElementoID
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo, dataCriacao e ID de inserção       
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos no meio da lista por meio de um ID
 */
int inserirElementoID(Computador *pendrive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao, int posicao) {
  Pendrive *p, *memoria = (Pendrive*)malloc(sizeof(Pendrive));

  if (memoria == NULL) {
    printf("O pendrive nao foi inserido.\n");
    return 0;
  }

  memoria->nome = malloc(strlen(nomeArquivo) + 1);
  memoria->data = malloc(strlen(dataCriacao) + 1);

  strcpy(memoria->nome, nomeArquivo);
  memoria->tamanho = tamanhoArquivo;
  strcpy(memoria->data, dataCriacao);
  ++(memoria->id);

  p = pendrive->prim;

  int i = 2;

  for (i; 
      (i < posicao) 
      && (p->prox != pendrive->prim); 
      ++i, 
      p = p->prox);

  if (p == NULL) {
    printf("A posicao nao existe.\n");
    return 0;
  }

  memoria->prox = p->prox;
  p->prox = memoria;

  return 1;
}

/* Nome: inserirElementoInicio
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elemento no inicio da lista
 */
int inserirElementoInicio(Computador *pendrive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao) {
  Pendrive *p, *memoria = (Pendrive*)malloc(sizeof(Pendrive));

  if (memoria == NULL) {
    printf("O pendrive nao foi inserido.\n");
    return 0;
  }

  memoria->nome = malloc(strlen(nomeArquivo) + 1);
  memoria->data = malloc(strlen(dataCriacao) + 1);

  strcpy(memoria->nome, nomeArquivo);
  memoria->tamanho = tamanhoArquivo;
  strcpy(memoria->data, dataCriacao);
  ++(memoria->id);

  if (pendrive->prim == NULL) {
    pendrive->prim = memoria;
    memoria->prox = memoria;
    return 1;
  }

  pendrive->prim->prox = memoria;
  memoria->prox = pendrive->prim;
  pendrive->prim = memoria;

  return 1;
}

/* Nome: listarElementos
 * Parametro: a própria lista     
 * Retorno: retorna void, é um procedimento para imprimir elementos no prompt
 * Descricao: função implementada para imprimir elementos da lista
 */
void listarElementos(Computador *pendrive) {
  Pendrive *p;

  if (pendrive->prim == NULL) {
    printf("O pendrive nao foi inserido.\n");
    return ;
  }

  if (pendrive->prim == NULL) {
    printf("Não há elementos.\n");
    return ;
  }

  if (pendrive->prim == pendrive->prim->prox) {
    printf("%d - %s - %s - %.2f\n", 
    pendrive->prim->id,
    pendrive->prim->nome, 
    pendrive->prim->data, 
    pendrive->prim->tamanho);
    return ;
  }

  p = pendrive->prim;
  printf("%d - %s - %s - %.2f\n",
    p->id,
    p->nome,
    p->data,
    p->tamanho);

  for (
    p = pendrive->prim->prox; 
    p != pendrive->prim; 
    p = p->prox) {
      printf("%d - %s - %s - %.2f\n",
      p->id,
      p->nome,
      p->data,
      p->tamanho);
  }

  return ;
}

/* Nome: removerElemento
 * Parametro: a própria lista e uma data
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para remover elementos da lista por data de criação de um arquivo
 */
int removerElemento(Computador *pendrive, char *data) {
  Pendrive *p, *aux;

  if (strcmp(pendrive->prim->data, data) == 0) {
    aux = pendrive->prim;

    for (p = pendrive->prim; 
        p->prox != pendrive->prim; 
        p = p->prox);

    p->prox = pendrive->prim->prox;
    pendrive->prim = pendrive->prim->prox;
    free(aux);

    return 1;
  }

  for (p = pendrive->prim; 
  p->prox != pendrive->prim; 
  p = p->prox) {
    if (strcmp(p->prox->data, data) == 0) {
      aux = p->prox;
      p->prox = p->prox->prox;
      free(aux);

      return 1;
    }
  }

  if (strcmp(p->prox->data, data) == 0) {
    aux = p->prox;
    p->prox = pendrive->prim;
    free(aux);

    return 1;
  }

  return 0;
}

/* Nome: removerElementoNome
 * Parametro: a própria lista e um nome
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para remover elementos da lista por nome do elemento
 */
int removerElementoNome(Computador *pendrive, char *nome) {
  Pendrive *p, *aux;

  if (strcmp(pendrive->prim->nome, nome) == 0) {
    aux = pendrive->prim;
    for (p = pendrive->prim; 
        p->prox != pendrive->prim; 
        p = p->prox);

    p->prox = pendrive->prim->prox;
    pendrive->prim = pendrive->prim->prox;
    free(aux);

    return 1;
  }

  for (p = pendrive->prim; 
      p->prox != pendrive->prim; 
      p = p->prox) {
        if (strcmp(p->prox->nome, nome) == 0) {
          aux = p->prox;
          p->prox = p->prox->prox;
          free(aux);

          return 1;
        }
  }

  if (strcmp(p->prox->nome, nome) == 0) {
    aux = p->prox;
    p->prox = pendrive->prim;
    free(aux);

    return 1;
  }

  return 0;
}

/* Nome: atualizar
 * Parametro: a própria lista, busca e dataAlteracao     
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para atualizar elementos na lista
 */

 int atualizar(Computador *pendrive, char *busca, char *nomeAlterado, float tamanhoAlterado, char *dataAlterada) {
  Pendrive *p;

  if (pendrive == NULL) {
    printf("O pendrive não foi inserido.\n");
    return 0;
  }

  if (pendrive->prim == NULL) {
    printf("O pendrive esta sem arquivos.\n");
    return 0;
  }

  for (p = pendrive->prim; 
      p->prox != pendrive->prim; 
      p = p->prox) {
        if (strcmp(p->data, busca)) {
          p->nome = nomeAlterado;
          p->tamanho = tamanhoAlterado;
          p->data = dataAlterada;
        }
  }

  return 1;
 }

 /* Nome: buscarElemento
 * Parametro: a própria lista e data     
 * Retorno: retorna um endereço que corresponde a um elemento da lista
 * Descricao: função implementada para buscar elementos na lista
 */
Pendrive* buscarElemento(Computador *pendrive, char *busca) {
  Pendrive *p;

  if (pendrive == NULL) {
    printf("O pendrive não foi inserido.\n");
    return 0;
  }

  if (pendrive->prim == NULL) {
    printf("O pendrive esta sem arquivos.\n");
    return 0;
  }

  
  for (p = pendrive->prim; p->prox != pendrive->prim; p = p->prox) {
    if (strcmp(p->data, busca)) {
      printf("Arquivo encontrado!\n");
      return p;
    }
  }

  return NULL;
}

/* Nome: tamanho
 * Parametro: a própria lista  
 * Retorno: retorna um inteiro indicando o tamanho da lista
 * Descricao: função implementada para contar os elementos na lista
 */
 int tamanho(Computador *pendrive) {
  Pendrive *p;

   if (pendrive == NULL) {
    printf("O pendrive não foi inserido.\n");
    return 0;
  }

  if (pendrive->prim == NULL) {
    printf("O pendrive esta sem arquivos.\n");
    return 0;
  }

  int count = 1;
  for (p = pendrive->prim; p->prox != pendrive->prim; p = p->prox) {
     ++count;
  }

  return count;
 }

 /* Nome: excluirLista (removerPendrive)
 * Parametro: a própria lista      
 * Retorno: retorna nulo, que é o que fica ao desalocar a lista da memória
 * Descricao: função responsável por desalocar a lista da memória
 */
 Computador* removerPendrive(Computador *pendrive) {
  Pendrive *aux;

  while (pendrive->prim != pendrive->prim->prox) {
    aux = pendrive->prim->prox;
    pendrive->prim->prox = pendrive->prim->prox->prox;
    free(aux);
  }

  free(pendrive->prim);
  free(pendrive);
 }

/* Nome: main
 * Parametro: nenhum
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: função responsável por ser a porta de entrada para execução do programa em computador
 */
int main() {

    Computador *pendrive;
    pendrive = criarLista();

    int opcaoEscolhida;

    printf("Escolha a operacao a ser realizada:\n1. Ver arquivos\n2. Inserir arquivos\n3. Buscar arquivos\n4. Excluir arquivo\n5. Atualizar elemento\n6. Saber quantidade de arquivos\n7. Excluir lista\n");
    printf("Insira aqui: ");
    scanf("%d", &opcaoEscolhida);
    fflush(stdin);
    while (opcaoEscolhida >= 1) {
        printf("\n");
        switch (opcaoEscolhida) {
            case 1:
                listarElementos(pendrive);
                break;
            case 2:
                int opcaoInserir;

                printf("Deseja inserir no inicio do espaço de armazenamento, no meio ou no final?\n");
                printf("1. Inicio\n2. Final\n3. Por ID\n");
                printf("Insira aqui: ");
                scanf("%d", &opcaoInserir);
                fflush(stdin);
                switch (opcaoInserir) {
                case 1: 
                    char nomeArquivoInserir1[30], dataArquivoInserir1[30];
                    float tamanhoInserir1;

                    int repetir1, pararRepetir1 = 0;
                    printf("Quantos arquivos serão inseridos? ");
                    scanf("%d", &repetir1);
                    fflush(stdin);
                    do {
                        printf("Digite os dados que serão inseridos\n");

                        printf("Nome do arquivo: ");
                        scanf("%s", nomeArquivoInserir1);
                        printf("Tamanho do arquivo: ");
                        scanf("%f", &tamanhoInserir1);
                        fflush(stdin);
                        printf("Data de criação: ");
                        scanf("%s", dataArquivoInserir1);

                        inserirElementoInicio(pendrive, nomeArquivoInserir1, tamanhoInserir1, dataArquivoInserir1);
                        ++pararRepetir1;
                    } while (repetir1 > pararRepetir1);
                    break;
                case 2:
                    char nomeArquivoInserir2[30], dataArquivoInserir2[30];
                    float tamanhoInserir2;

                    int repetir2, pararRepetir2 = 0;
                    printf("Quantos arquivos serão inseridos? ");
                    scanf("%d", &repetir2);
                    fflush(stdin);
                    do {
                        printf("Digite os dados que serão inseridos\n");

                        printf("Nome do arquivo: ");
                        scanf("%s", nomeArquivoInserir2);
                        printf("Tamanho do arquivo: ");
                        scanf("%f", &tamanhoInserir2);
                        fflush(stdin);
                        printf("Data de criação: ");
                        scanf("%s", dataArquivoInserir2);

                        inserirElemento(pendrive, nomeArquivoInserir2, tamanhoInserir2, dataArquivoInserir2);
                        ++pararRepetir2;
                    } while (repetir2 > pararRepetir2);
                    break;
                case 3:
                    char nomeArquivoInserir3[30], dataArquivoInserir3[30];
                    float tamanhoInserir3;
                    int posicao;

                    int repetir3, pararRepetir3 = 0;
                    printf("Quantos arquivos serão inseridos? ");
                    scanf("%d", &repetir3);
                    fflush(stdin);
                    do {
                        printf("Digite os dados que serão inseridos\n ");

                        printf("Nome do arquivo: ");
                        scanf("%s", nomeArquivoInserir3);
                        printf("Tamanho do arquivo: ");
                        scanf("%f", &tamanhoInserir3);
                        fflush(stdin);
                        printf("Data de criação: ");
                        scanf("%s", dataArquivoInserir3);
                        printf("Posição que deseja inserir: ");
                        scanf("%d", &posicao);

                        inserirElementoID(pendrive, nomeArquivoInserir3, tamanhoInserir3, dataArquivoInserir3, posicao);
                        ++pararRepetir3;
                    } while (repetir3 > pararRepetir3);
                    break;
                default:
                    printf("Opcao nao valida\n");
                    break;
                }
                break;
            case 3:
                char busca[30];

                printf("Digite o nome do arquivo que deseja buscar: ");
                scanf("%s", busca);

                Pendrive *ResultadoBusca = buscarElemento(pendrive, busca);
                    if (ResultadoBusca != NULL) {
                        printf("Elemento encontrado\n");
                    } else {
                        printf("O elemento não foi encontrado\n");
                    }
                break;
            case 4:
                int opcaoRemover;

                printf("Deseja remover por nome ou data?\n");
                printf("1. Por nome\n2. Por data\n");
                printf("Insira aqui: ");
                scanf("%d", &opcaoRemover);
                switch (opcaoRemover) {
                    case 1:
                        char nomeArquivoRemover[30];
                        printf("Digite o nome do arquivo: ");
                        scanf("%s", nomeArquivoRemover);
                        
                        removerElementoNome(pendrive, nomeArquivoRemover);
                        break;
                    case 2:
                        char dataArquivoRemover[30];
                        printf("CUIDADO! Todos os arquivos que forem compatíveis serão deletados!");
                        printf("Digite a data do arquivo que deseja remover: ");
                        scanf("%s", dataArquivoRemover);

                        removerElemento(pendrive, dataArquivoRemover);
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
                break;
            case 5:
                char nomeArquivoAtual[30], nomeArquivoAtualizado[30], dataArquivoAtualizada[30];
                float tamanhoArquivoAtualizado;

                printf("Digite o nome do arquivo que deseja atualizar: ");
                printf("Nome do arquivo que deseja atualizar: ");
                scanf("%s", nomeArquivoAtual);
                printf("Insira os novos dados: \n");
                printf("Novo nome: ");
                scanf("%s", nomeArquivoAtualizado);
                printf("Novo tamanho: ");
                scanf("%f", &tamanhoArquivoAtualizado);
                printf("Nova data: ");
                scanf("%s", dataArquivoAtualizada);

                atualizar(pendrive, nomeArquivoAtual, nomeArquivoAtualizado, tamanhoArquivoAtualizado, dataArquivoAtualizada);
                break;
            case 6:
                int tamanhoPendrive = tamanho(pendrive);
                printf("A quantidade de arquivos no pendrive é de: %d\n", tamanhoPendrive);
                break;
            case 7:
                removerPendrive(pendrive);
                break;
            default:
                printf("Opcao invalida\n");
                break;         
        }

        printf("\n");

        fflush(stdin);

        printf("Escolha a operacao a ser realizada:\n1. Ver arquivos\n2. Inserir arquivos\n3. Buscar arquivos\n4. Excluir arquivo\n5. Atualizar elemento\n6. Saber quantidade de arquivos\n7. Excluir lista\n");
        printf("Insira aqui: ");
        scanf("%d", &opcaoEscolhida);
    }
}