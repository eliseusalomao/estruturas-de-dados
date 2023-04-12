#include <stdio.h>

int main() {
	
	double precoFabrica;
	
	printf("Insira o preço de fabrica: ");
	scanf("%lf", &precoFabrica);
	
	double impostos = precoFabrica * 0.45;
	double precoRevendedor = precoFabrica * 0.28;
	
	double precoTotal = precoFabrica + impostos + precoRevendedor;
	
	printf("O preco do carro e: %.3lf", precoTotal);
}
