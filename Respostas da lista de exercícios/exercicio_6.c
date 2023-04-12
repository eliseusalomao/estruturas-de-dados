#include <stdio.h>

int main() {
	
	int r;
	double PI = 3.14159;
	printf("Digite um numero: ");
	scanf("%d", &r);
	
	double area = PI * (r * r);
	
	printf("A area do circulo: %.2f", area);
	
	return 0;
}
