#include <stdio.h>

int main() {
	
	int H = 0, limite;
	scanf("%d", &limite);
	
	int i;
	for (i = 1; i <= limite; ++i) {
		H+=i;
	}

	
	printf("%d", H);
	
	
	
	return 0;
}
