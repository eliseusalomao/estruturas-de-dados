#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct computador Computador;
typedef struct pendrive Pendrive;

struct computador {
    Pendrive *prim;
};

struct pendrive {
    char *nome;
    float tamanho;
    char *data;
    Pendrive *prox;
};

Computador* criarLista() {
    Computador *memoria = (Computador*)malloc(sizeof(Computador));

    if(memoria == NULL) {
        printf("A lista não foi criada\n");
        return 0;
    }

    memoria->prim = NULL;
    return memoria;
}

int inserirElemento(Computador *pen_drive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao) {
    Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive)); 

    if (memoria == NULL) {
        printf("Sem espaço\n");
        return 0;
    }

    memoria->nome = nomeArquivo;
    memoria->tamanho = tamanhoArquivo;
    memoria->data = dataCriacao;
    memoria->prox = NULL;

    if (pen_drive->prim == NULL) {
        pen_drive->prim = memoria;
        return 1;
    }

    Pendrive *p;
    for (p = pen_drive->prim; p->prox != NULL; p = p->prox);

    p->prox = memoria;

    return 1; 
}

void imprimirElementos(Computador *pen_drive) {

    if (pen_drive == NULL) {
        printf("A lista nao foi criada\n");
        return ;
    }

    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\n");
        return ;
    }

    Pendrive *p;
    printf("Nome\t\tTamanho\t\tData\t\n");
    for (p = pen_drive->prim; p != NULL; p = p->prox) {
        printf("%s\t%.2f\t\t%s\n", p->nome, p->tamanho, p->data);
    }
    printf("\n");
}

Pendrive* buscarElemento(Computador *pen_drive, char *data) {

    if (pen_drive == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    if (pen_drive->prim == NULL) {
        printf("A lista esta vazia\n");
        return 0;
    }

    Pendrive *p;
    for(p = pen_drive->prim; p->prox != NULL; p = p->prox) {
        if(strcmp(p->data, data) == 0) {
            return p;
        }
    }

    return NULL;
}

Computador* excluirLista(Computador *pen_drive) {
    Pendrive *aux;
    
    while (pen_drive->prim != NULL) {
        aux = pen_drive->prim;
        pen_drive->prim = pen_drive->prim->prox;
        free(aux);
    }

    printf("\nLista excluida\n");
}

int main() {

    Computador *pen_drive;
    pen_drive = criarLista();

    inserirElemento(pen_drive, "eliseu.c", 23.3, "30/04/2023");
    inserirElemento(pen_drive, "eliseu.exe", 23.3, "29/04/2023");
    inserirElemento(pen_drive, "ED.c\t", 23.3, "28/04/2023");
    inserirElemento(pen_drive, "ED.exe\t", 23.3, "27/04/2023");
    imprimirElementos(pen_drive);

    Pendrive *buscar = buscarElemento(pen_drive, "28/04/2023");
    if (buscar != NULL) {
        printf("Elemento encontrado");
    }

    excluirLista(pen_drive);

}
