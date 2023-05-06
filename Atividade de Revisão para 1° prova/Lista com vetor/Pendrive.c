/***********************************************************
* Nome: lista com vetores                                  *
* Autor: Eliseu Salomão                                    *
* Professor: Mayrton Dias                                  *
* Disciplina: Estrutura de Dados                           *
* Descrição: implementação de lista com vetor, com as      *
*            operações de:  criar lista,                   *   
*                           inserir elemento,              *
*                           inserir elemento id,           *
*                           inserir elemento inicio,       *
*                           lista elementos,               *
*                           remover elemento,              *
*                           remover elemento por nome,     *
*                           atualizar,                     *
*                           buscar elemento,               *
*                           tamanho e                      *
*                           excluir lista.                 *
***********************************************************/


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// definição do tamanho para o vetor
#define TAM 10

// definição das estruturas que serão utilizadas
typedef struct {
    char nomeArquivo[30];
    float tamanhoArquivo;
    char particao;
} Pendrive;

typedef struct {
    int id;
    Pendrive *elementos;
} Lista;

/* Nome: criarLista
 * Parametro: nenhum          
 * Retorno: retorna um endereço reservado por malloc
 * Descricao: função implementada para criar a lista
 */
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

/* Nome: inserirElemento
 * Parametro: recebe a própria lista, nome, tamanho e particao como parâmetros        
 * Retorno: o tipo de retorno é um inteiro
 * Descricao: função que insere elementos na última posição do vetor
 */
int inserirElemento(Lista *lista, char *nome, float tamanho, char particao) {
    // verificando se a lista está vazia
    if(lista == NULL) {
        printf("A lista nao foi criada");
        return 0;
    }

    // inserindo elemento
    // verificando se o vetor ainda possui espaço, se ouver, o próprio id irá servir para inserir um elemento em determinada posição
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

/* Nome: inserirElementoID
 * Parametro: recebe a própria lista, nome, tamanho, particao e posicao como parâmetros       
 * Retorno: o tipo de retorno é um inteiro
 * Descricao: função que insere elementos no vetor na posição especificada pelo usuário/programador
 */
int inserirElementoID(Lista *lista, char *nome, float tamanho, char particao, int posicao) {
    int i;

    // verificando se a lista foi criada
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    // verificando se há espaço no vetor
    if (lista->id < TAM) {
        // verificando se a posição passada está dentro do intervalo do tamanho do vetor
        if (posicao < lista->id) {
            // iniciando o laço com a ultima posição do vetor e se a posição que se quer inserir o elemento for menor que a ultima posição (elemento inserido até o momento)
            // os elementos que estiverem em posições posteriores a passada para inserção do novo elemento, irão receber os elementos anteriores, abrindo espaço para a inserção
            // do novo elemento na posição desejada
            for (i = lista->id; i > posicao; --i) {
                strcpy(lista->elementos[i].nomeArquivo, lista->elementos[i-1].nomeArquivo);
                lista->elementos[i].tamanhoArquivo = lista->elementos[i-1].tamanhoArquivo;
                lista->elementos[i].particao = lista->elementos[i-1].particao;
            }
            // inserindo elemento na posição desejada, já que o espaço foi liberado
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

/* Nome: inserirElementoInicio
 * Parametro: recebe a própria lista, nome, tamanho e particao como parâmetros       
 * Retorno: o tipo de retorno é um inteiro
 * Descricao: função que insere elementos na primeira posição do vetor
 */
int inserirElementoInicio(Lista *lista, char *nome, float tamanho, char particao) {
    int i;
    // verificando se a lista foi criada
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    // verificando se possui espaço no vetor para inserir um elemento.
    if (lista->id < TAM) {
        // se houver iremos do ultimo elemento até o primeiro, passando todos os elementos de determinada posição, para posição + 1, deixando a posição 0 livre.
        for (i = lista->id; i > 0; --i) {
            strcpy(lista->elementos[i].nomeArquivo, lista->elementos[i-1].nomeArquivo);
            lista->elementos[i].tamanhoArquivo = lista->elementos[i-1].tamanhoArquivo;
            lista->elementos[i].particao = lista->elementos[i-1].particao;
        }
        // inserindo elemento no inicio (posição 0)
        strcpy(lista->elementos[0].nomeArquivo, nome);
        lista->elementos[0].tamanhoArquivo = tamanho;
        lista->elementos[0].particao = particao;
        ++(lista->id);
        // caso contrário, não há espaço
    } else {
        printf("Espaco esgotado");
        return 0;
    }
}

/* Nome: listarElementos
 * Parametro: recebe a lista como parâmetro         
 * Retorno: o tipo de retorno é vazio
 * Descricao: função responsável pelo procedimento de imprimir elementos em prompt
 */
void listarElementos(Lista *lista) {
    int i;
    // verificando se a lista foi criada
    if(lista == NULL) {
        printf("A lista nao foi criada\n");
        return ;
    }

    // verificando se o vetor possui algum elemento
    if(lista->id == 0) {
        printf("A lista esta vazia\n");
        return ;
    }

    // o for irá percorrer todos os ids. Através da variável i podemos acessar a estrutura e o que está atribuído em determinada posição no vetor
    printf("Nome\t\tTamanho\t\tParticao\n");
    for(i = 0; i < lista->id; ++i) {
        printf("%d. %s\t",(i+1) , lista->elementos[i].nomeArquivo);
        printf("%.2f\t\t", lista->elementos[i].tamanhoArquivo);
        printf("%c:\t", lista->elementos[i].particao);
        printf("\n");
    }
    printf("\n");
}

/* Nome: removerElemento
 * Parametro: recebe a própria lista e id como parâmetros      
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: função que remove elementos no vetor em uma posição especificada pelo usuário/programador
 */
int removerElemento(Lista *lista, int id) {
    int i;

    // verifica se a lista está vazia
    if(lista == NULL) {
        printf("A lista nao foi criada");
        return 0;
    }

    // se o id for menor que lista->id, o valor passado está dentro do intervalo do tamanho do vetor
    if(id < lista->id) {
        // i recebe o id, enquanto o i (id) for menor que o tamanho do vetor (-1 porque o elemento ao ser inserido está na posição 0, mas o id contabiliza como 1)
        // os valores posteriores serão passados para os elementos anteriores a eles, deixando o último espaço vazio
        for(i = id; i < lista->id-1; ++i) {
            strcpy(lista->elementos[i].nomeArquivo, lista->elementos[i+1].nomeArquivo);
            lista->elementos[i].tamanhoArquivo = lista->elementos[i+1].tamanhoArquivo;
            lista->elementos[i].particao = lista->elementos[i+1].particao;
        }
        // após deixar o último espaço vazio, decrementa-se o lista->id, deixando o espaço inacessível
        --(lista->id);
        return 1;
    }
    return 0;
}

/* Nome: removerElementoNome
 * Parametro: recebe a própria lista e nome como parâmetros      
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: função que remove elementos no vetor com base na comparação de nomes iguais (um passado pelo programador e um que existe na memória) especificada pelo usuário/programador
 */
int removerElementoNome(Lista *lista, char *nome) {
    int i, j;

    // verificando se a lista foi criada
    if (lista == NULL){
        printf("A lista nao foi criada\n");
        return 0;
    }

    // laço para percorrer todos os indices e servir para verificar se algum nome dos indices corresponde ao nome passado
    for (i = 0; i < lista->id; ++i) {
        // verificando se os nomes são compatíveis
        if (strcmp(lista->elementos[i].nomeArquivo, nome) == 0) {
            // j recebe o i, enquanto o j (i) for menor que o tamanho do vetor os valores posteriores serão passados para os elementos anteriores a eles, deixando o último espaço vazio
            for (j = i; j < lista->id; ++j) {
                strcpy(lista->elementos[j].nomeArquivo, lista->elementos[j+1].nomeArquivo);
                lista->elementos[j].tamanhoArquivo = lista->elementos[j+1].tamanhoArquivo;
                lista->elementos[j].particao = lista->elementos[j+1].particao;
            }
            // após deixar o último espaço vazio, decrementa-se o lista->id, deixando o espaço inacessível
            --(lista->id);
            return 1;
        }
    }
}

/* Nome: atualizar
 * Parametro: recebe a própria lista, busca, nome, tamanho e particao como parâmetros      
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: a função altera um elemento no vetor com os valores passados pelo usuário/programador como parâmetros
 */
int atualizar(Lista *lista, char *busca, char *nome, float tamanho, char particao) {
    int i;

    // verifica se a lista foi criada
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return 0;
    }

    // percorrendo o vetor
    for (i = 0; i < lista->id; ++i) {
        // verificando se algum indice contém um campo que corresponde ao nome do arquivo sendo procurado
        if (strcmp(lista->elementos[i].nomeArquivo, busca) == 0) {
            // fazendo a alteração dos valores dos campos pelos valores passados
            strcpy(lista->elementos[i].nomeArquivo, nome);
            lista->elementos[i].tamanhoArquivo = tamanho;
            lista->elementos[i].particao = particao;
            return 1;
        }
    }
}

/* Nome: buscarElemento
 * Parametro: recebe a própria lista e um nome como parâmetros      
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: função responsável por buscar no vetor um elemento compatível com o passado pelo usuário/programador no momento da busca
 */
int buscarElemento(Lista *lista, char *nome) {
    int i, j;

    // verificando se a lista foi criada
    if (lista == NULL) {
        printf("A lista nao foi criada\n");
        return -1;
    }

    // verificando se o nome passado corresponde ao nome de algum arquivo da lista comparando com o strcmp
    for (i = 0; i < lista->id; ++i) {
        if (strcmp(lista->elementos[i].nomeArquivo, nome) == 0) {
            return i;
        }
    }
    return -1;
}

/* Nome: tamanho
 * Parametro: a própria lista
 * Retorno: o tipo de retorno é um inteiro que irá indicar o tamanho do vetor
 * Descricao: função responsável por retornar tamanho do vetor (arquivos inseridos no pendrive)
 */
int tamanho (Lista *lista) {
    return lista->id;
}

/* Nome: excluirLista
 * Parametro: recebe a lista como parâmetro          
 * Retorno: retorna nulo, que é o que fica ao excluir toda a lista
 * Descricao: função responsável por desalocar a lista da memória
 */
Lista* excluirLista(Lista *lista) {
    free(lista->elementos);
    free(lista);
    return NULL;
}

/* Nome: main
 * Parametro: nenhum
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: função responsável por ser a porta de entrada para execução do programa em computador
 */
int main() {

    Lista *pendrive;
    pendrive = criarLista();

    int opcaoEscolhida;

    printf("Escolha a operacao a ser realizada:\n1. Ver arquivos\n2. Inserir Arquivos\n3. Buscar Arquivos\n4. Excluir arquivo\n5. Atualizar elemento\n6. Saber quantidade de arquivos\n7. Excluir Lista\n");
    printf("Insira aqui: ");
    scanf("%d", &opcaoEscolhida);

    while (opcaoEscolhida >= 1) {

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
                switch (opcaoInserir) {
                    case 1:
                        inserirElemento(pendrive, "exercicio1.c", 232.3, 'H');
                        inserirElemento(pendrive, "exercicio2.c", 232.3, 'H');
                        inserirElemento(pendrive, "exercicio3.c", 232.3, 'H');
                        inserirElemento(pendrive, "exercicio4.c", 232.3, 'H');
                        listarElementos(pendrive);
                        break;
                    case 2:
                        inserirElementoInicio(pendrive, "exercicio6.c", 231.3, 'E');
                        listarElementos(pendrive);
                        break;
                    case 3:
                        inserirElementoID(pendrive, "README", 321.3, 'L', 0);
                        listarElementos(pendrive);
                        break;
                    default:
                        printf("Nao e uma opcao valida!\n");
                }
                break;
            case 3:
                int resultadoBusca = buscarElemento(pendrive, "eliseu.c");
                if (resultadoBusca != -1) {
                    printf("O arquivo foi encontrado no pendrive\n");
                    listarElementos(pendrive);
                } else {
                    printf("O arquivo nao foi encontrado na lista\n");
                }
                break;
            case 4:
                int tipoRemocao;
                printf("Desja remover por indice ou nome? ");
                scanf("%d", &tipoRemocao);

                switch (tipoRemocao) {
                    case 1: 
                        removerElemento(pendrive, 0);
                        printf("Elemento removido por indice");
                        break;
                    case 2:
                        removerElementoNome(pendrive, "eliseu.c");
                        printf("Elemento removido por nome");
                }
                break;
            case 5: 
                atualizar(pendrive, "exercicio1.c", "eliseu.exe", 123.3, 'E');
                break;
            case 6:
                int tamanhoPendrive = tamanho(pendrive);
                printf("A quantidade de arquivos no pendrive é de: %d", tamanhoPendrive);
                break;
            case 7:
                excluirLista(pendrive);
                break;
        }

        printf("\n");

        printf("Escolha a operacao a ser realizada:\n1. Ver arquivos\n2. Inserir Arquivos\n3. Buscar Arquivos\n4. Excluir arquivo\n5. Atualizar elemento\n6. Saber quantidade de arquivos\n7. Excluir Lista\n");
        printf("Insira aqui: ");
        scanf("%d", &opcaoEscolhida);
        printf("\n");
    }
}
    
