#include <stdio.h>

int main() {
	int i, idade, maioridade = 0;
	
	printf("Insira sua idade: ");
	for (i = 1; i <= 4; i++) {
		scanf("%d", &idade);
		
		if (idade >= 18) {
			++maioridade;
		}
	}
	
	printf("O numero de pessoas maiores de idade eh: %d", maioridade);
	
	return 0;
}
