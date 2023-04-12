#include <stdio.h>

int main() {
	
	int valores, dentroDoIntervalo = 0, foraDoIntervalo = 0;
	
	int i;
	for (i = 1; i <= 10; ++i) {
		scanf("%d", &valores);
		
		if (valores >= 10 && valores <= 50) {
			++dentroDoIntervalo;
		} else {
			++foraDoIntervalo;
		}
	}
	
	printf("A quantidade de numeros dentro do intervalo eh de: %d\n", dentroDoIntervalo);
	printf("A quantidade de numeros fora do intervalo eh de: %d\n", foraDoIntervalo);
	
}
