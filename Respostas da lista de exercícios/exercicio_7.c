#include <stdio.h>

int main() {
	
	double r, h, PI = 3.14159;
	printf("Digite o valor da base e em seguida a altura do cilindro: ");
	scanf("%lf %lf", &r, &h);
	
	double areaCilindro = 2 * PI * r * (h + r);
	double volumeCilindro = PI * (r * r) * h;
	
	printf("A area do cilindro: %.2f\nO volume do cilindro: %.2f", areaCilindro, volumeCilindro);
	
	
	
	return 0;
}
