#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define TAM 10

typedef struct {
    char nomeArquivo[30];
    float tamanhoArquivo;
    char particao;
} Pendrive;

typedef struct {
    int id;
    Pendrive *elementos;
} Lista;

Lista* criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));
    if(nova == NULL) {
        printf("Nao tem espaco\n");
        return NULL;
    }

    nova->id = 0;
    nova->elementos = (Pendrive*)malloc(TAM*sizeof(Pendrive));
    if(nova->elementos == NULL) {
        printf("Nao ha elementos\n");
        free(nova);
        return NULL;
    }
    return nova;
}

Lista* excluirLista(Lista *lista) {
    free(lista->elementos);
    free(lista);
    return NULL;
}

void imprimirElementos(Lista *lista) {
    int i;
    if(lista == NULL) {
        printf("A lista nao foi criada\n");
        return ;
    }

    if(lista->id == 0) {
        printf("A lista esta vazia\n");
        return ;
    }

    printf("Nome\t\tTamanho\t\tParticao\n");
    for(i = 0; i < lista->id; ++i) {
        printf("%d. %s\t",(i+1) , lista->elementos[i].nomeArquivo);
        printf("%.2f\t\t", lista->elementos[i].tamanhoArquivo);
        printf("%c:\t", lista->elementos[i].particao);
        printf("\n");
    }
    printf("\n");
}

int inserirElemento(Lista *lista, char *nome, float tamanho, char particao) {
    if(lista == NULL) {
        printf("A lista nao foi criada");
        return 0;
    }

    if(lista->id<TAM) {
        strcpy(lista->elementos[lista->id].nomeArquivo, nome);
        lista->elementos[lista->id].tamanhoArquivo = tamanho;
        lista->elementos[lista->id].particao = particao;
        ++(lista->id);
    } else {
        printf("Espaco esgotado\n");
        return 0;
    }
    return 1;
}

int inserirElementoInicio(Lista *lista, char *nome, float tamanho, char particao) {
    int i;
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    if (lista->id < TAM) {
        for (i = lista->id; i > 0; --i) {
            strcpy(lista->elementos[i].nomeArquivo, lista->elementos[i-1].nomeArquivo);
            lista->elementos[i].tamanhoArquivo = lista->elementos[i-1].tamanhoArquivo;
            lista->elementos[i].particao = lista->elementos[i-1].particao;
        }
        strcpy(lista->elementos[0].nomeArquivo, nome);
        lista->elementos[0].tamanhoArquivo = tamanho;
        lista->elementos[0].particao = particao;
        ++(lista->id);
    } else {
        printf("Espaco esgotado");
        return 0;
    }
}

int inserirElementoID(Lista *lista, char *nome, float tamanho, char particao, int posicao) {
    int i;
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    if (lista->id < TAM) {
        if (posicao < lista->id) {
            for (i = lista->id; i > posicao; --i) {
                strcpy(lista->elementos[i].nomeArquivo, lista->elementos[i-1].nomeArquivo);
                lista->elementos[i].tamanhoArquivo = lista->elementos[i-1].tamanhoArquivo;
                lista->elementos[i].particao = lista->elementos[i-1].particao;
            }
            strcpy(lista->elementos[posicao].nomeArquivo, nome);
            lista->elementos[posicao].tamanhoArquivo = tamanho;
            lista->elementos[posicao].particao = particao;
            ++(lista->id);
        } else {
            printf("Posicao fora do intervalo definido\n");
        }
    } else {
            printf("Nao ha mais espaço\n");
            return 0;
    }
    return 1;
}

int removerElemento(Lista *lista, int id) {
    int i;

    if(lista == NULL) {
        printf("A lista nao foi criada");
        return 0;
    }

    if(id < lista->id) {
        for(i = id; i < lista->id-1; ++i) {
            strcpy(lista->elementos[i].nomeArquivo, lista->elementos[i+1].nomeArquivo);
            lista->elementos[i].tamanhoArquivo = lista->elementos[i+1].tamanhoArquivo;
            lista->elementos[i].particao = lista->elementos[i+1].particao;
        }
        --(lista->id);
        return 1;
    }
    return 0;
}

int removerElementoNome(Lista *lista, char *nome) {
    int i, j;

    if (lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    for (i = 0; i < lista->id; ++i) {
        if (strcmp(lista->elementos[i].nomeArquivo, nome) == 0) {
            for (j = i; j < lista->id; ++j) {
                strcpy(lista->elementos[j].nomeArquivo, lista->elementos[j+1].nomeArquivo);
                lista->elementos[j].tamanhoArquivo = lista->elementos[j+1].tamanhoArquivo;
                lista->elementos[j].particao = lista->elementos[j+1].particao;
            }
            --(lista->id);
            return 1;
        }
    }
}

int buscarElemento(Lista *lista, char *nome) {
    int i, j;

    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return -1;
    }

    for (i = 0; i < lista->id; ++i) {
        if (strcmp(lista->elementos[i].nomeArquivo, nome) == 0) {
            return i;
        }
    }
    return -1;
}

int atualizarElemento(Lista *lista, char *busca, char *nome, float tamanho, char particao) {
    int i;

    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    for (i = 0; i < lista->id; ++i) {
        if (strcmp(lista->elementos[i].nomeArquivo, busca) == 0) {
            strcpy(lista->elementos[i].nomeArquivo, nome);
            lista->elementos[i].tamanhoArquivo = tamanho;
            lista->elementos[i].particao = particao;
            return 1;
        }
    }
}

int main() {

    Lista *pendrive;
    pendrive = criarLista();

    int opcaoEscolhida;

    printf("Escolha a operacao a ser realizada:\n1. Ver arquivos\n2. Inserir Arquivos\n3. Buscar Arquivos\n4. Excluir arquivo\n5. Atualizar elemento\n");
    printf("Insira aqui: ");
    scanf("%d", &opcaoEscolhida);

    while (opcaoEscolhida >= 1) {

        if (opcaoEscolhida == 1) {
            imprimirElementos(pendrive);
        }

        if (opcaoEscolhida == 2) {
            int opcaoInserir;

            printf("Deseja inserir no inicio do espaço de armazenamento ou no final?\n");
            printf("1. Inicio\n2. Final\n3. Por ID\n");
            printf("Insira aqui: ");
            scanf("%d", &opcaoInserir);

            if (opcaoInserir == 1) {
                inserirElemento(pendrive, "exercicio1.c", 232.3, 'H');
                inserirElemento(pendrive, "exercicio2.c", 232.3, 'H');
                inserirElemento(pendrive, "exercicio3.c", 232.3, 'H');
                inserirElemento(pendrive, "exercicio4.c", 232.3, 'H');
                imprimirElementos(pendrive);
            }

            if (opcaoInserir == 2) {
                inserirElementoInicio(pendrive, "exercicio6.c", 231.3, 'E');
                imprimirElementos(pendrive);
            }

            if (opcaoInserir == 3) {
                inserirElementoID(pendrive, "README", 321.3, 'L', 0);
                imprimirElementos(pendrive);
            }
        }

        if (opcaoEscolhida == 3) {
            int resultadoBusca = buscarElemento(pendrive, "eliseu.c");
            if (resultadoBusca != -1) {
                printf("O arquivo foi encontrado no pendrive\n");
                imprimirElementos(pendrive);
            } else {
                printf("O arquivo nao foi encontrado na lista\n");
            }
        }

        if (opcaoEscolhida == 4) {
            int tipoRemocao;
            printf("Desja remover por indice ou nome? ");
            scanf("%d", &tipoRemocao);

            if (tipoRemocao == 1) {
                removerElemento(pendrive, 0);
                printf("Elemento removido por indice");
            }

            if (tipoRemocao == 2) {
                removerElementoNome(pendrive, "eliseu.c");
                printf("Elemento removido por nome");
            }
        }

        if (opcaoEscolhida == 5) {
            atualizarElemento(pendrive, "exercicio1.c", "eliseu.exe", 123.3, 'E');
        }

    printf("\n");

    printf("Escolha a operacao a ser realizada:\n1. Ver arquivos\n2. Inserir Arquivos\n3. Buscar Arquivos\n4. Excluir arquivo\n5. Atualizar elemento\n");
    printf("Insira aqui: ");
    scanf("%d", &opcaoEscolhida);
    printf("\n");
    }
}
    
