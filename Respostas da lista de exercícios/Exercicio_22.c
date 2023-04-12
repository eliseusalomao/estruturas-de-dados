#include <stdio.h>

int main() {
	
	int n1, n2, op;
	printf("Insira dois numeros inteiros ");
	scanf("%d %d", &n1, &n2);
	
	printf("Que operacao deseja realizar?\n1. Adicao\n2. Subtracao\n3. Divisao\n4. Multiplicacao\n");
	scanf("%d", &op);
	
	switch(op) {
		case 1: 
			printf("Resultado da adicao: %d", (n1 + n2));
			break;
		case 2: 
			printf("Resultado da subtracao: %d", (n1 - n2));
			break;
		case 3:
			if (n2 == 0) {
				printf("Impossivel dividir por 0");
			} else {
				printf("Resultado da divisao: %d", (n1 / n2));
			}
			break;
		case 4: 
			printf("Resultado da multiplicacao: %d", (n1 * n2));
			break;
		default:
			printf("Operacao inexistente");
	}
	
	
	
}
