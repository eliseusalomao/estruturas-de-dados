#include <stdio.h>

int main() {
	
	double centimetros;
	
	printf("Insira o valor em centimetros e converta-o para polegadas: ");
	scanf("%lf", &centimetros);
	
	double polegadas = centimetros / 2.54;
	
	printf("Em polegadas: %lf", polegadas);
	
	return 0;
}
