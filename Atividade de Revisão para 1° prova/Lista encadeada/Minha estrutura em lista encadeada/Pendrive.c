/***********************************************************
* Nome: lista com vetores                                  *
* Autor: Eliseu Salomão                                    *
* Turma: 301B                                              *
* Professor: Mayrton Dias                                  *
* Disciplina: Estrutura de Dados                           *
* Descrição: implementação de lista com vetor, com as      *
*            operações de:  criar lista,                   *                   
*                           inserir elemento,              *
*                           inserir elemento início,       *    
*                           inserir elemento id            *
*                           listar elentos,                *
*                           buscar elemento,               *
*                           remover elemento,              *
*                           remover elemento por nome,     *
*                           tamanho,                       *
*                           atualizar elemento e           *     
*                           excluir lista.                 *                                                  
***********************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definindo estruturas
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
    // alocando espaço em memória para a estrutura Computador
    Computador *memoria = (Computador*)malloc(sizeof(Computador));

    // verificando se a lista foi criada
    if(memoria == NULL) {
        printf("A lista não foi criada\n");
        return 0;
    }

    printf("Pendrive inserido com sucesso\n");
    // iniciando o primeiro elemento como nulo, pois ainda não foi inserido nada
    memoria->prim = NULL;
    return memoria;
}


/* Nome: inserirElemento
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos na lista
 */
int inserirElemento(Computador *pen_drive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao) {
    // alocando espaço em memória para a estrutura Pendrive
    Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive)); 

    // verificando se a lista foi criada
    if (memoria == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    // iniciando os campos da estrutura Pendrive através do espaço alocado memoria com os valores passados como parâmetros
    memoria->nome = nomeArquivo;
    memoria->tamanho = tamanhoArquivo;
    memoria->data = dataCriacao;
    ++(memoria->id);
    memoria->prox = NULL;

    // se a lista (pen_drive) estiver vazia, a lista irá apontar para o espaço alocado para os campos de Pendrive
    // agora o primeiro elemento (prim) da lista aponta para os campos inicializados acima
    if (pen_drive->prim == NULL) {
        pen_drive->prim = memoria;
        return 1;
    }

    // p percorre toda a lista (pen_drive) até p->prox ser diferente de nulo
    Pendrive *p;
    for (p = pen_drive->prim; p->prox != NULL; p = p->prox);

    // assim, o último elemento (p->prox) aponta para o espaço alocado para Pendrive
    p->prox = memoria;

    return 1; 
}

/* Nome: inserirElementoInicio
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elemento no inicio da lista
 */
int inserirElementoInicio(Computador *pen_drive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao) {
    Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive));

    if (memoria) {
        memoria->nome = nomeArquivo;
        memoria->tamanho = tamanhoArquivo;
        memoria->data = dataCriacao;
        ++(memoria->id);
        memoria->prox = pen_drive->prim;
        pen_drive->prim = memoria;
        return 1;
    }
    return 0;
}

/* Nome: inserirElementoInicioID
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo, dataCriacao e ID de inserção       
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos no meio da lista por meio de um ID
 */
int inserirElementoID(Computador *pen_drive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao, int ant) {
    Pendrive *aux, *p, *memoria = (Pendrive*)malloc(sizeof(Pendrive));

    // se a memoria for alocada os campos do nó serão inseridos
    if (memoria != NULL) {
        memoria->nome = nomeArquivo;
        memoria->tamanho = tamanhoArquivo;
        memoria->data = dataCriacao;
        ++(memoria->id);
        // se a lista for nula está sendo inserido o primeiro nó da lista
        if (pen_drive->prim == NULL) {
            //se é o primeiro, então o próximo será nulo
            memoria->prox = NULL;
            // o inicio da lista é o novo nó (memória)
            pen_drive->prim = memoria;
        } 

        // pen_drive->prim não pode ser alterado, pois não estamos falando mais do primeiro nó
        // se for alterado, o conteudo da variável na main será alterado e o valor perdido
        // cria-se um auxiliar para guardar a referência do primeiro nó da lista
        p = pen_drive->prim;
        // vamos percorrer a lista até encontrar algum elemento correspondente; se encontrar iremos apontar
        // para um elemento à frente na lista
        /* while (aux->id != ant && aux->prox) {
            aux = aux->prox;
        } */

        for (; p->id != ant && p->prox != NULL; p = p->prox);

        // o novo no aponta para o final da lista
        memoria->prox = p->prox;
        p->prox = memoria;
        return 1;
    }
}

/* Nome: imprimirElementos
 * Parametro: a própria lista     
 * Retorno: retorna void, é um procedimento para imprimir elementos no prompt
 * Descricao: função implementada para imprimir elementos da lista
 */
void listarElementos(Computador *pen_drive) {

    // verifica se a lista foi criada
    if (pen_drive == NULL) {
        printf("A lista nao foi criada\n");
        return ;
    }

    // verifica se o primeiro elemento existe na lista
    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\n");
        return ;
    }

    // percorrendo toda a lista (pen_drive) imprimindo os valores do campos
    Pendrive *p;
    printf("Nome\t\tTamanho\t\tData\t\n");
    for (p = pen_drive->prim; p != NULL; p = p->prox) {
        printf("%s\t%.2f\t\t%s\n", p->nome, p->tamanho, p->data);
    }
    printf("\n");
}

/* Nome: buscarElemento
 * Parametro: a própria lista e data     
 * Retorno: retorna um endereço que corresponde a um elemento da lista
 * Descricao: função implementada para buscar elementos na lista
 */
Pendrive* buscarElemento(Computador *pen_drive, char *data) {
    
    // verificando se a lista (pen_drive) foi criada
    if (pen_drive == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    //  verificando se a lista não está vazia
    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\n");
        return 0;
    }

    // percorrendo a lista com p e verificando se algum campo data corresponde ao valor passando de data
    Pendrive *p;
    for(p = pen_drive->prim; p->prox != NULL; p = p->prox) {
        if(strcmp(p->data, data) == 0) {
            // retornando o elemento correspondente
            return p;
        }
    }

    return NULL;
}

/* Nome: removerElementoNome
 * Parametro: a própria lista e um nome
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para remover elementos da lista por nome do elemento
 */
int removerElementoNome(Computador *pen_drive, char *nome) {
    
    // verificando se a lista foi criada
    if (pen_drive == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    // verificando se a lista possui elemento
    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\n");
        return 0;
    }

    // verificando o primeiro elemento corresponde ao elemento passado
    Pendrive *p, *aux;
    if (strcmp(pen_drive->prim->nome, nome) == 0) {
        p = pen_drive->prim;
        pen_drive->prim = pen_drive->prim->prox;
        printf("Removendo do inicio.\n");
        listarElementos(pen_drive);
        free(p);
        return 1;
    }

    // percorrendo a lista entre e incluindo o segundo até o penúltimo elemento
    for (p = pen_drive->prim; p->prox != NULL; p = p->prox) {
        if (strcmp(p->prox->nome, nome) == 0) {
            aux = p->prox;
            p->prox = p->prox->prox;
            printf("Removendo do meio\n");
            listarElementos(pen_drive);
            free(aux);
            return 1;
        }
    }

    // verificando se o último elemento corresponde ao valor passado
    if (strcmp(p->prox->nome, nome) == 0) {
        aux = p->prox;
        p->prox = NULL;
        printf("Removendo ultimo elemento\n");
        listarElementos(pen_drive);
        free(aux);
        return 1;
    }
}

/* Nome: removerElemento
 * Parametro: a própria lista e uma data
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para remover elementos da lista por data de criação de um arquivo
 */
int removerElemento(Computador *pen_drive, char *data) {
    
    // verificando se a lista foi criada
    if (pen_drive == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    // verificando se a lista possui elemento
    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\n");
        return 0;
    }

    // verificando o primeiro elemento corresponde ao elemento passado
    Pendrive *p, *aux;
    if (strcmp(pen_drive->prim->data, data) == 0) {
        p = pen_drive->prim;
        pen_drive->prim = pen_drive->prim->prox;
        printf("Removendo do inicio.\n");
        listarElementos(pen_drive);
        free(p);
        return 1;
    }

    // percorrendo a lista entre e incluindo o segundo até o penúltimo elemento
    for (p = pen_drive->prim; p->prox != NULL; p = p->prox) {
        if (strcmp(p->prox->data, data) == 0) {
            aux = p->prox;
            p->prox = p->prox->prox;
            printf("Removendo do meio\n");
            listarElementos(pen_drive);
            free(aux);
            return 1;
        }
    }

    // verificando se o último elemento corresponde ao valor passado
    if (strcmp(p->prox->data, data) == 0) {
        aux = p->prox;
        p->prox = NULL;
        printf("Removendo ultimo elemento\n");
        listarElementos(pen_drive);
        free(aux);
        return 1;
    }
}

/* Nome: atualizarElemento
 * Parametro: a própria lista, busca e dataAlteracao     
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para atualizar elementos na lista
 */
int atualizar(Computador *pen_drive, char *busca, char *dataAlteracao) {
    
    // verificando se a lista foi criada
    if (pen_drive == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    // verificando se a lista possui elemento
    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\n");
        return 0;
    }

    // percorrendo a lista verificando se alguma estrutura com o campo de data corresponde ao valor passado por busca
    Pendrive *p;
    for (p = pen_drive->prim; p != NULL; p = p->prox) {
        if (strcmp(p->data, busca) == 0) {
            p->data = dataAlteracao;
            printf("O arquivo foi atualizado\n");
            listarElementos(pen_drive);
        }
    }

    return 0;
}

/* Nome: tamanho
 * Parametro: a própria lista  
 * Retorno: retorna um inteiro indicando o tamanho da lista
 * Descricao: função implementada para contar os elementos na lista
 */
int tamanho(Computador *pen_drive) {
    Pendrive *p;

    // verificando se a lista existe
    if (pen_drive == NULL) {
        printf("A lista nao existe\n");
        return 0;
    }

    // verificando se a lista está vazia
    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\nNumero de elementos: 0");
        return 0;
    }

    // percorrendo todos os elementos da lista até ser nulo, a cada item passado o contador é incrementado; representando o tamanho da lista.
    int count = 0;
    for (p = pen_drive->prim; p != NULL; p = p->prox) {
        count++;
    }
    // retornando o valor armazenado em count;
    return count;
}

/* Nome: excluirLista
 * Parametro: a própria lista      
 * Retorno: retorna nulo, que é o que fica ao desalocar a lista da memória
 * Descricao: função responsável por desalocar a lista da memória
 */
Computador* excluirLista(Computador *pen_drive) {
    Pendrive *aux;
    
    // enquanto a condição for false
    while (pen_drive->prim != NULL) {
        // aux irá guardar a referencia que prim aponta
        aux = pen_drive->prim;
        // prim vai apontar para o próximo elemento
        pen_drive->prim = pen_drive->prim->prox;
        // aux vai ser desalocado da memória
        free(aux);
        printf("\nLista excluida\n");
        return NULL;
    }

}

/* Nome: main
 * Parametro: nenhum
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: função responsável por ser a porta de entrada para execução do programa em computador
 */
int main() {

    Computador *pen_drive;
    pen_drive = criarLista();

    int opcaoEscolhida;

    printf("Escolha a operacao a ser realizada:\n1. Ver arquivos\n2. Inserir arquivos\n3. Buscar arquivos\n4. Excluir arquivo\n5. Atualizar elemento\n6. Saber quantidade de arquivos\n7. Excluir lista\n");
    printf("Insira aqui: ");
    scanf("%d", &opcaoEscolhida);
    fflush(stdin);
    while (opcaoEscolhida >= 1) {
        switch (opcaoEscolhida) {
            case 1:
                listarElementos(pen_drive);
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
                    char nome[30], data[30];
                    float tamanho;

                    int repetir, pararRepetir = 0;
                    printf("Quantos arquivos serão inseridos? ");
                    scanf("%d", &repetir);
                    fflush(stdin);
                    do(repetir) {
                        printf("Digite os dados que serão inseridos ");

                        scanf("%s", nome);
                        scanf("%f", &tamanho);
                        fflush(stdin);
                        scanf("%s", data);

                        inserirElementoInicio(pen_drive, nome, tamanho, data);
                        ++pararRepetir;
                    } while (repetir > pararRepetir);
                    break;
                case 2:
                    char nome[30], data[30];
                    float tamanho;

                    int repetir, pararRepetir = 0;
                    printf("Quantos arquivos serão inseridos? ");
                    scanf("%d", &repetir);
                    fflush(stdin);
                    do(repetir) {
                        printf("Digite os dados que serão inseridos ");

                        scanf("%s", nome);
                        scanf("%f", &tamanho);
                        fflush(stdin);
                        scanf("%s", data);

                        inserirElemento(pen_drive, nome, tamanho, data);
                        ++pararRepetir;
                    } while (repetir > pararRepetir);
                    break;
                case 3:
                    char nome[30], data[30];
                    float tamanho;
                    int posicao;

                    int repetir, pararRepetir = 0;
                    printf("Quantos arquivos serão inseridos? ");
                    scanf("%d", &repetir);
                    fflush(stdin);
                    do(repetir) {
                        printf("Digite os dados que serão inseridos ");

                        scanf("%s", nome);
                        scanf("%f", &tamanho);
                        fflush(stdin);
                        scanf("%s", data);
                        scanf("%d" &posicao);

                        inserirElementoID(pen_drive, nome, tamanho, data, posicao);
                        ++pararRepetir;
                    } while (repetir > pararRepetir);
                    break;
                    
                    break;
                default:
                    printf("Opcao nao valida\n");
                    break;
                }
                break;
            case 3:
                Pendrive *buscar = buscarElemento(pen_drive, "28/04/2023");
                    if (buscar != NULL) {
                        printf("Elemento encontrado\n");
                    } else {
                        printf("O elemento não foi encontrado\n");
                    }
                break;
            case 4:
                int opcaoRemover;

                printf("Deseja remover por nome ou data?");
                printf("1. Por nome\n2. Por data\n");
                printf("Insira aqui: ");
                scanf("%d", &opcaoRemover);
                switch (opcaoRemover) {
                    case 1:
                        removerElementoNome(pen_drive, "ED.exe\t");
                        break;
                    case 2:
                        removerElemento(pen_drive, "27/04/2023");
                        break;
                    default:
                        printf("Opcao invalida\n");
                        break;
                }
                break;
            case 5:
                atualizar(pen_drive, "30/04/2023", "04/05/2023");
                break;
            case 6:
                int tamanhoPendrive = tamanho(pen_drive);
                printf("A quantidade de arquivos no pendrive é de: %d", tamanhoPendrive);
                break;
            case 7:
                excluirLista(pen_drive);
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
