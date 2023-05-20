///////////////////////////////////////////////////////////////////////////////////////
// Nome: Lista duplamente encadeada													 //
// Autor: Eliseu Salomão															 //
// Professor: Mayrton Dias															 //
// Disciplina: Estrutura de dados													 //
// Descrição: implementação de lista duplamente encadeada, com as operações de:		 //
//			  - criar lista 														 //
//			  - inserir elemento													 //
//			  - inserir elemento id													 //
//			  - inserir elemento inicio												 //
//			  - listar elementos													 //
//			  - listar elementos ordem inversa										 //
//			  - remover elemento													 //	
//			  - remover elemento por nome											 //
//			  - atualizar															 //
//			  - buscar elemento														 //
//			  - tamanho																 //
//			  - excluir lista														 //
///////////////////////////////////////////////////////////////////////////////////////

// incluindo bibliotecas
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// definindo estruturas
typedef struct computador Computador;
typedef struct pendrive Pendrive;

struct computador {
	Pendrive *prim;
	Pendrive *ult;
};

struct pendrive {
	Pendrive *prox;
	char *nome;
	float tamanho;
	char *data;
	Pendrive *ant;
};

/* Nome: criarLista
 * Parametro: nenhum          
 * Retorno: retorna um endereço reservado por malloc
 * Descricao: função implementada para criar a lista
 */
Computador* criarLista() {
	Computador *memoria = (Computador*)malloc(sizeof(Computador));

	if (memoria == NULL) {
		printf("Sem espaço\n");
		return NULL;
	}

	memoria->prim = NULL;
	memoria->ult = NULL;
	
	printf("Computador ligado; TA-RAM\nO pendrive foi inserido corretamente\n");

	return memoria;
}

/* Nome: inserirElemento
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos na lista
 */
int inserirElemento(Computador *pendrive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao) {
	Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive));

	if (memoria == NULL) {
		printf("Sem espaço\n");
		return 0;
	}

	memoria->nome = malloc(strlen(nomeArquivo) + 1);
	memoria->data = malloc(strlen(dataCriacao) + 1);
	   
	memoria->ant = NULL;
	strcpy(memoria->nome, nomeArquivo);
	memoria->tamanho = tamanhoArquivo;
	strcpy(memoria->data, dataCriacao);
     memoria->prox = NULL;

	if (pendrive->prim == NULL) {
		pendrive->prim = memoria;
	   	pendrive->ult = memoria;
		return 1;
	}
     
	memoria->ant = pendrive->ult;
	pendrive->ult->prox = memoria;
	pendrive->ult = memoria;

	return 1;
}

/* Nome: inserirElementoID
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo, dataCriacao e ID de inserção       
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elementos no meio da lista por meio de um ID
 */
int inserirElementoID(Computador *pendrive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao, int posicao) {
	Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive));

	if (memoria == NULL) {
		printf("O pendrive nao foi inserido corretamente\n");
		return 0;
	}

	memoria->nome = malloc(strlen(nomeArquivo));
	memoria->data = malloc(strlen(dataCriacao));

	memoria->ant = NULL;
	strcpy(memoria->nome, nomeArquivo);
	memoria->tamanho = tamanhoArquivo;
	strcpy(memoria->data, dataCriacao);
	memoria->prox = NULL;

	if (pendrive->prim == NULL) {
	    pendrive->prim = memoria;
	    pendrive->ult = memoria;
	    return 1;
	}

	Pendrive *p = pendrive->prim;
	int i = 2;
	for (i; (i < posicao) && (p != NULL); ++i, p = p->prox);
	
/*	memoria->ant = memoria->prox;
	memoria->prox = p->prox;
	p->prox = memoria;
	pendrive->ult = memoria;
 */
	Pendrive *aux;
	aux = p->prox;
	aux->ant = p;
   
	p->prox = memoria;
	memoria->ant = p;
	memoria->prox = aux;
	aux->ant = memoria;
	return 1;
}

/* Nome: inserirElementoInicio
 * Parametro: a própria lista, nomeArquivo, tamanhoArquivo e dataCriacao        
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para inserir elemento no inicio da lista
 */
int inserirElementoInicio(Computador *pendrive, char *nomeArquivo, float tamanhoArquivo, char *dataCriacao) {
	Pendrive *memoria = (Pendrive*)malloc(sizeof(Pendrive));

	if (memoria == NULL) {
		printf("O pendrive não foi inserido corretamente\n");
		return 0;
	}

	memoria->nome = malloc(strlen(nomeArquivo) + 1);
	memoria->data = malloc(strlen(dataCriacao) + 1);	

	memoria->ant = NULL;
	strcpy(memoria->nome, nomeArquivo);
	memoria->tamanho = tamanhoArquivo;
	strcpy(memoria->data, dataCriacao);
     memoria->prox = NULL;

	if (pendrive->prim == NULL) {
	    pendrive->prim = memoria;
	    pendrive->ult = memoria;
	    return 1;
	}
   
	memoria->ant = NULL;
	memoria->prox = pendrive->prim;
	pendrive->prim->ant = memoria;
	pendrive->prim = memoria;

	return 1;
}

/* Nome: listarElementos
 * Parametro: a própria lista     
 * Retorno: retorna void, é um procedimento para imprimir elementos no prompt
 * Descricao: função implementada para imprimir elementos da lista
 */
void listarElementos(Computador *pendrive) {
	if (pendrive == NULL) {
		printf("A lista nao foi criada\n");
		return ;
	}

	if (pendrive->prim == NULL) {
		printf("A lista esta vazia\n");
		return ;
	}

	Pendrive *p;
	printf("Nome\t\t| Tamanho \t\t| Data\n");
	printf("----------------------------------------------------\n");
	for (p = pendrive->prim; p != NULL; p = p->prox) {
		printf("%s\t| %.2f\t\t\t| %s\t\n", p->nome, p->tamanho, p->data);
	}
	printf("\n");
}

/* Nome: listarElementosOrdemInversa
 * Parametro: a própria lista     
 * Retorno: retorna void, é um procedimento para imprimir elementos no prompt
 * Descricao: função implementada para imprimir elementos da lista em ordem inversa
 */
void listarElementosOrdemInversa(Computador *pendrive) {
	if (pendrive == NULL) {
		printf("O pendrive nao foi inserido corretamente\n");
		return ;
	}

	if (pendrive->prim == NULL) {
		printf("O pendrive esta vazio\n");
		return ;
	}
	
	Pendrive *p;
	printf("Nome\t\t| Tamanho \t\t| Data\n");
	printf("----------------------------------------------------\n");
	for (p = pendrive->ult; p != NULL; p = p->ant) {
		printf("%s\t| %.2f\t\t\t| %s\t\n", p->nome, p->tamanho, p->data);
	}
	printf("\n");
}

/* Nome: removerElemento
 * Parametro: a própria lista e uma data
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para remover elementos da lista por data de criação de um arquivo
 */
int removerElemento(Computador *pendrive, char *data) {
	if (pendrive == NULL) {
		printf("A lista nao foi criada\n");
		return 0;
	}

	if (pendrive->prim == NULL) {
		printf("A lista esta vazia\n");
		return 0;
	}

	Pendrive *p;
	if (strcmp(pendrive->prim->data, data) == 0) {
		p = pendrive->prim;
		pendrive->prim->prox->ant == NULL;
		pendrive->prim = pendrive->prim->prox;
		free(p);
		return 1;
	}

	Pendrive *aux;
	for (p = pendrive->prim; p->prox != NULL; p = p->prox) {
		if (strcmp(p->prox->data, data) == 0) {
			aux = p->prox;
			p->prox = p->prox->prox;
			p->prox->ant = p;
			free(aux);
			return 1;
		}
	}

	if (strcmp(p->prox->data, data) == 0) {
		aux = p->prox;
		p->prox = NULL;
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
	if (pendrive == NULL) {
		printf("A lista nao foi criada\n");
		return 0;
	}

	if (pendrive->prim == NULL) {
		printf("A lista esta vazia\n");
		return 0;
	}

	Pendrive *p;
	if (strcmp(pendrive->prim->nome, nome) == 0) {
		p = pendrive->prim;
		pendrive->prim->prox->ant == NULL;
		pendrive->prim = pendrive->prim->prox;
		free(p);
		return 1;
	}

	Pendrive *aux;
	for (p = pendrive->prim; p->prox != NULL; p = p->prox) {
		if (strcmp(p->prox->nome, nome) == 0) {
			aux = p->prox;
			p->prox = p->prox->prox;
			p->prox->ant = p;
			free(aux);
			return 1;
		}
	}

	if (strcmp(p->prox->nome, nome) == 0) {
		aux = p->prox;
		p->prox = NULL;
		free(aux);
		return 1;
	}
}

/* Nome: atualizar
 * Parametro: a própria lista, busca, nome alterado, tamanho alterado e data alterada    
 * Retorno: retorna um inteiro indicando se a operação foi bem sucedida ou não
 * Descricao: função implementada para atualizar elementos na lista
 */
int atualizar(Computador *pendrive, char *busca, char *nomeAlterado, float tamanhoAlterado, char *dataAlterada) {
	if (pendrive == NULL) {
		printf("O pendrive nao foi inserido corretamente (criado)\n");
		return 0;
	}

	if (pendrive->prim == NULL) {
		printf("O pendrive esta vazio\n");
		return 0;
	}

	Pendrive *p;
	for (p = pendrive->prim; p != NULL; p = p->prox) {
		if (strcmp(p->nome, busca) == 0) {
			p->nome = nomeAlterado;
			p->tamanho = tamanhoAlterado;
			p->data = dataAlterada;
			printf("O arquivo foi atualizado\nListando arquivos:\n");
			listarElementos(pendrive);
		}
	}

	return 0;
}

/* Nome: buscarElemento
 * Parametro: a própria lista e busca     
 * Retorno: retorna um endereço que corresponde a um elemento da lista
 * Descricao: função implementada para buscar elementos na lista
 */
Pendrive* buscarElemento(Computador *pendrive, char *busca) {
	if (pendrive == NULL) {
		printf("O pendrive nao foi inserido corretamente (criado)\n");
		return 0;
	}

	if (pendrive->prim == NULL) {
		printf("O pendrive esta vazio\n");
		return 0;
	}

	Pendrive *p;
	for (p = pendrive->prim; p != NULL; p = p->prox) {
		if (strcmp(p->nome, busca) == 0) {
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
	if (pendrive == NULL) {
		printf("O pendrive nao foi inserido corretamente (criado)\n");
		return 0;
	}

	if (pendrive->prim == NULL) {
		printf("O pendrive esta vazio\n");
		return 0;
	}

	Pendrive *p;
	int count = 0;
	for (p = pendrive->prim; p != NULL; p = p->prox) {
		++count;
	}
	
	printf("O pendrive contem: %d arquivos\n", count);
	return count;
}

/* Nome: excluirLista
 * Parametro: a própria lista      
 * Retorno: retorna nulo, que é o que fica ao desalocar a lista da memória
 * Descricao: função responsável por desalocar a lista da memória
 */
Computador* excluirLista(Computador *pendrive) {
	Pendrive *aux;
	while(pendrive->prim != NULL) {
		aux = pendrive->prim;
		pendrive->prim = pendrive->prim->prox;
		free(aux);
		return NULL;
	}
}

/* Nome: main
 * Parametro: nenhum
 * Retorno: o tipo de retorno é um inteiro que irá diferenciar entre uma operação bem sucedida ou não
 * Descricao: função responsável por ser a porta de entrada para execução do programa em computador
 */
int main() {
	Computador *pendrive;
	pendrive = criarLista();

	int opcaoInicial;
	printf("Escolha a operacao a ser realizada:\n 1. Ver arquivos\n 2. Inserir arquivos\n 3. Buscar arquivos\n 4. Excluir arquivo\n 5. Atualizar elemento\n 6. Saber quantidade de arquivos\n 7. Excluir lista\n");
	printf("Insira aqui: ");
	scanf("%d", &opcaoInicial);

	printf("\n");

	while(opcaoInicial > 0) {
		switch (opcaoInicial) {
			case 1:
				int opcaoListar;
				
				printf("Deseja imprimir:\n 1. Em ordem de inserção\n 2. Em ordem inversa\n");
				printf("Insira aqui: ");
				scanf("%d", &opcaoListar);
				
				printf("\n");

				switch(opcaoListar) {
					case 1:
						listarElementos(pendrive);
						break;
					case 2:
						listarElementosOrdemInversa(pendrive);
						break;
					default:
						printf("Opcao invalida\n");
				}
				break;

			case 2:
				int opcaoInserir;

				printf("Deseja inserir:\n 1. No incio\n 2. No meio\n 3. No final\n");
				printf("Insira aqui: ");
				scanf("%d", &opcaoInserir);

				switch(opcaoInserir) {
					case 1:
						char nome1[30], data1[30];
						float tamanho1;

						printf("Nome do arquivo que deseja inserir: ");
						scanf("%s", nome1);
						printf("Tamanho do arquivo: ");
						scanf("%f", &tamanho1);
						printf("Data de criação do arquivo: ");
						scanf("%s", data1);	

						inserirElementoInicio(pendrive, nome1, tamanho1, data1);
						break;
					case 2:
						char nome2[30], data2[30];
						float tamanho2;
						int posicao;

						printf("Nome do arquivo que deseja inserir: ");
						scanf("%s", nome2);
						printf("Tamanho do arquivo: ");
						scanf("%f", &tamanho2);
						printf("Data de criação do arquivo: ");
						scanf("%s", data2);	
						printf("Posicao: ");
						scanf("%d", &posicao);

						inserirElementoID(pendrive, nome2, tamanho2, data2, posicao);
						break;
					case 3:
						char nome3[30], data3[30];
						float tamanho3;

						printf("Nome do arquivo que deseja inserir: ");
						scanf("%s", nome3);
						printf("Tamanho do arquivo: ");
						scanf("%f", &tamanho3);
						printf("Data de criação do arquivo: ");
						scanf("%s", data3);	

						inserirElemento(pendrive, nome3, tamanho3, data3);
						break;
					default:
						printf("Opcao invalida\n");
				}
				break;
			case 3:
				char buscar[30];

				printf("Digite o nome do arquivo que deseja buscar: ");
				scanf("%s", buscar);

				Pendrive *resultadoBusca = buscarElemento(pendrive, buscar);
				if (resultadoBusca != NULL) {
					printf("Arquivo encontrado\n");
				} else {
					printf("O arquivo nao foi encontrado\n");
				}
				break;

			case 4:
				int opcaoRemover;

				printf("Deseja remover arquivo por:\n 1. nome\n 2. data\n");
				printf("Insira aqui: ");
				scanf("%d", &opcaoRemover);
				
				switch(opcaoRemover) {
					case 1:
						char nomeRemover[30];

						printf("Digite o nome do arquivo: ");
						scanf("%s", nomeRemover);

						removerElementoNome(pendrive, nomeRemover);
						break;
					case 2:
						char dataRemover[30];

						printf("Digite a data do arquivo: ");
						scanf("%s", dataRemover);

						removerElemento(pendrive, dataRemover);
						break;
					default:
						printf("Opcao invalida\n");
				}
				break;

			case 5: 
				char nomeAtual[30], nomeAtualizado[30], dataAtualizada[30];
				float tamanhoAtualizado;

				printf("Digite o nome do arquivo que deseja alterar: ");
				scanf("%s", nomeAtual);
				if (buscarElemento(pendrive, nomeAtual) == NULL) {
					printf("O arquivo nao existe no pendrive\n");
				} else {
					printf("Insira os novos dados:\n");
					printf("Novo nome: ");
					scanf("%s", nomeAtualizado);
					printf("Novo tamanho: ");
					scanf("%f", &tamanhoAtualizado);
					printf("Data da atualização: ");
					scanf("%s", dataAtualizada);

					atualizar(pendrive, nomeAtual, nomeAtualizado, tamanhoAtualizado, dataAtualizada);
				}
				break;

			case 6:
				int tamanhoPendrive = tamanho(pendrive);
				break;

			case 7: 
				excluirLista(pendrive);
				break;

			default:
				printf("Opcao inexistente\n");
		}
	
	printf("\n");

	fflush(stdin);

	int decisaoFinal;
	printf("Deseja sair ou voltar ao menu?\n 0. Sair\n 1. Voltar ao menu\n");
	printf("Insira aqui: ");
	scanf("%d", &decisaoFinal);

	if (decisaoFinal != 0) {
		printf("\n");
		printf("Escolha a operacao a ser realizada:\n 1. Ver arquivos\n 2. Inserir arquivos\n 3. Buscar arquivos\n 4. Excluir arquivo\n 5. Atualizar elemento\n 6. Saber quantidade de arquivos\n 7. Excluir lista\n");
		printf("Insira aqui: ");
		scanf("%d", &opcaoInicial);
		
		printf("\n");
	} else {
		break;
	}
	}
}

