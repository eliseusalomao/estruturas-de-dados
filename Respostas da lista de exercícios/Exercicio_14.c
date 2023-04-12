#include <stdio.h>;

int main() {
	
	int num;
	scanf("%d", &num);
	
	if (num == 0) {
		printf("O valor eh zero");
	} else if (num < 0) {
		printf("O valor eh negativo");
	} else {
		printf("O valor eh positivo");
	}
	
}
