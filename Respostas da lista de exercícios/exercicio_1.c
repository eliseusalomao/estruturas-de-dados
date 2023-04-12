#include <stdio.h>

int main() {
	
	int a, b;
	
	printf("Insira o primeiro valor inteiro: \n");
	scanf("%d", &a);
	printf("Insira o segundo valor inteiro: \n");
	scanf("%d", &b);
	
	int multiplicacao = a * b;
	printf("O resultado foi: %d", multiplicacao);
	
	return 0;
}
