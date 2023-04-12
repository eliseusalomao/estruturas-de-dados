#include <stdio.h>
#include <stdlib.h>

int main() {
	
	int a, b, c;
	float X1, X2;
	
	scanf("%d %d %d", &a, &b, &c);
	
	int D = (b * b) - (4 * a * c);
	
	
	
	if (D < 0) {
		printf("Nao ha solucao real");
	} else if (D == 0) {
		printf("Ha duas solucoes possiveis");
		X1 = X2 = (-b) / (2 * a);
		printf("%lf", X1);
	} else {
		printf("Ha duas solucoes reais e diferentes\n");
		X1 = (-b + sqrt(D))/ 2 * a;
		X2 = (-b - sqrt(D)) / 2 * a;
		printf("%d\nRaiz 1: %2.lf\nRaiz 2: %2.lf", D, X1, X2);
	}
	
	
	
	
	
	
}
