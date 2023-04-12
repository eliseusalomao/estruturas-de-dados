#include <stdio.h>;

int main() {
	int num_macas;
	printf("Quantas macas deseja comprar? ");
	scanf("%d", &num_macas);
	
	if (num_macas < 12 && num_macas > 0) {
		printf("Valor total da compra: %.2lf", (num_macas * 0.30));
	} else if (num_macas >= 12) {
			printf("Valor total da compra: %.2lf", (num_macas * 0.25));
	} else {
		printf("Nao eh possivel comprar menos do que 0 macas.");
	}
	
	
	return 0;
}
