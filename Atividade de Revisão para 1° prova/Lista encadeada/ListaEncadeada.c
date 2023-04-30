#include <stdio.h>
#include <stdlib.h>

typedef struct lista Lista;
typedef struct listaNo ListaNo;

struct lista {
    ListaNo *prim;
};

struct listaNo {
    int valor;
    ListaNo* prox;
};

Lista* criarLista() {
    Lista *nova = (Lista*)malloc(sizeof(Lista));

    if (nova == NULL) {
        printf("Sem espaço\n");
        return NULL;
    }

    nova->prim = NULL;
    return nova;
}

int inserirElemento(Lista *lista, int valor) {
    ListaNo *nova = (ListaNo*)malloc(sizeof(ListaNo));

    if (nova == NULL) {
        printf("Sem espaço\n");
        return 0;
    }

    nova->valor = valor;
    nova->prox = NULL;

    if (lista->prim == NULL) {
        lista->prim = nova;
        return 1;
    }

    ListaNo *p;
    for (p = lista->prim; p->prox != NULL; p = p->prox);

    p->prox = nova;

    return 1;
}

void imprimirElementos(Lista *lista) {

    if (lista == NULL) {
        printf("A lista nao foi criada");
        return;
    }

    if (lista->prim == NULL) {
        printf("A lista esta vazia");
        return ;
    }

    ListaNo *p;
    for (p = lista->prim; p != NULL; p = p->prox) {
        printf("%d ", p->valor);
    }
    printf("\n");
}

ListaNo* buscarElemento(Lista *lista, int valor) {
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return NULL;
    }

    if (lista->prim == NULL) {
        printf("A lista esta vazia\n");
        return NULL;
    }

    ListaNo *p;
    for (p = lista->prim; p->prox != NULL; p = p->prox) {
        if (p->valor == valor) {
            return p;
        }
    }

    return NULL;
}

int removerElemento(Lista *lista, int valor) {
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    if (lista->prim == NULL) {
        printf("A lista esta vazia\n");
        return 0;
    }

    ListaNo *p, *aux;
    if (lista->prim->valor == valor) {
        p = lista->prim;
        lista->prim = lista->prim->prox;
        free(p);
        printf("Primeiro elemento removido\n");
        printf("\n");
        return 1;
    }

    for (p = lista->prim; p->prox->prox != NULL; p = p->prox) {
        if (p->prox->valor == valor) {
            aux = p->prox;
            p->prox = p->prox->prox;
            free(aux);
            printf("Elemento do meio removido\n");
            printf("\n");
            return 1;
        }
    }

    if (p->prox->valor == valor) {
        aux = p->prox;
        p->prox = NULL;
        free(aux);
        printf("Ultimo elemento removido\n");
        printf("\n");
        return 1;
    }
}

int main() {
    Lista *lista;
    lista = criarLista();

    inserirElemento(lista, 1);
    inserirElemento(lista, 2);
    inserirElemento(lista, 3);
    inserirElemento(lista, 4);
    inserirElemento(lista, 5); 
    imprimirElementos(lista);

    ListaNo *resultadoBusca = buscarElemento(lista, 4);
    if (resultadoBusca != NULL) {
        printf("Resultado encontrado: %d", resultadoBusca->valor);
        printf("\n");
    }
   removerElemento(lista, 4); 
   
   imprimirElementos(lista);
}