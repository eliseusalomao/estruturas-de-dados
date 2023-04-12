#include <stdio.h>

int main() {
	
	int x, y;
	
	printf("Digite dois números: ");
	scanf("%d %d", &x, &y);
	
	double divisao = x / y;
	double resto = x % y;
	
	printf("O resultado da divisao foi: %lf\nO resto foi: %lf", divisao, resto);
	
	
	return 0;
}
