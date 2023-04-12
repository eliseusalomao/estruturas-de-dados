#include <stdio.h>

int main() {
	
	int i;
	double media, soma, dividendo;
	
	for (i = 13; i <= 73; ++i) {
		if (i % 2 == 0) {
			soma += i;
			++dividendo;
		}
	}
	
	media = soma / dividendo;
	
	printf("%.2lf", media);

	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
