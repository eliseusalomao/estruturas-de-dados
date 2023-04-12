#include <stdio.h>

int main() {
	
	int x, y;
	
	printf("Digite dois valores para saber sua soma, produto e quociente: ");
	scanf("%d %d", &x, &y);
	
	int soma = x +y;
	int multiplicacao = x * y;
	int divisao = x / y;
	
	printf("Soma: %d\nMultiplicacao: %d\nDivisao: %d", soma, multiplicacao, divisao);
	
	
	return 0;
}
