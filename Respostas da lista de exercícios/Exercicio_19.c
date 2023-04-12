#include <stdio.h>;

int main() {
	
	int num1, num2, num3;
	scanf("%d %d %d", &num1, &num2, &num3);
	
	if (num1 > num2 && num1 > num3) {
		printf("O maior eh num1: %d", num1);
	} else if (num2 > num3) {
		printf("O maior eh num2: %d", num2);
	} else {
		printf("O maior eh num3: %d", num3);
	}
	
	
	
	return 0;
}
