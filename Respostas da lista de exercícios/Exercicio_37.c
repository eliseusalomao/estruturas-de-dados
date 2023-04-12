#include <stdio.h>

int main(){

	double S;
	int numerador = 3;
	int i;
	for (i = 1; i <= 50; ++i) {
		S += 1 + (numerador/(i+1));
		numerador = numerador + 2;
	}
	
	printf("%.2f", S);
	return 0;
}
