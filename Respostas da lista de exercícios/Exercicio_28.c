#include <stdio.h>

int main() {
	int i;
	
	int soma = 0;
	
	for(i = 1; i <= 100; i++) {
		soma += i;
	}
	
	printf("%d ", soma);
	
	return 0;
}
