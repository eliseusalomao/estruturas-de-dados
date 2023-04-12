#include <stdio.h>

int main() {
	
	int num[20], max = 0;
	
	int i;
	for (i = 0; i < 20; ++i) {
		scanf("%d", &num[i]);
	}
	for (i = 0; i < 20; ++i) {
		if (num[0] < num[i]) {
			num[0] = num[i];
			max = num[0];
		}
		if (num[0] > num[i]) {
			num[i] = num[0];
			max = num[i];
		}
	}
	
	printf("O maior valor eh: %d", max);
	
	
	return 0;
	
}
