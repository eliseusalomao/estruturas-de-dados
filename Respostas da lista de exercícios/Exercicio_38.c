#include <stdio.h>

int main() {
	
	
	double S;
	int x;
	scanf("%d", &x);
	
	int i;
	for (i = 1; i <= 20; i++) {
		int count = i;
		/* duvida: nessa operacao é necessario fazer (x - count) ou desse jeito
		 está correto? Quando troco por (x-count) a quantidade de repetições
		 diminui, mostrando apenas a quantidade de vezes correspondente a x e não a 20*/
		S += 1 / x - count;
		printf("%.2lf\n", S);
	}
	return 0;
}
