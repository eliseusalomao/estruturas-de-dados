#include <stdio.h>;

int main() {
	
	int num1, num2;
	scanf("%d %d", &num1, &num2);

	if (num1 == num2) {
		printf("Sao iguais");
	} else {
		if (num1 > num2) {
			printf("Os numeros sao diferentes.\n");
			printf("O maior numero eh: %d", num1);
		} else {
			printf("Os numeros sao diferentes.\n");
			printf("O maior numero eh: %d", num2);
		}
	}


	return 0;

}
