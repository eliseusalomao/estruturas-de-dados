#include <stdio.h>

int main() {
	
	int K, N, resultado = 0;
	
	scanf("%d", &K);
	scanf("%d", &N);
	
	int i;
	for (i = 1; i < N; i++) {
		resultado += K * N;
	}
	
	printf("%d", resultado);
	
	
	
	
	
	
	
	
}
