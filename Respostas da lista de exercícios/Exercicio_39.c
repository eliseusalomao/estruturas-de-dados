#include <stdio.h>

int main() {
	
	int i, num1 = 1, num2 = 1;;
	for(i = 3; i <= 10; i++) {
		
		int fibonacci = num1 + num2;
		num1 = num2;
		num2 = fibonacci;
		
		printf("%d ", num2);
	}	
	
	
	
	
	
	
	
	return 0;
}
