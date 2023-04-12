#include <stdio.h>

int main() {
	
	int A, B, C;
	
	scanf("%d %d %d", &A, &B, &C);
	
	if ((A < B + C) && (B < A + C) && (C < A + B)) {
		printf("E um triangulo\n");
		
		if (A == B && A == C && C == B) {
			printf("E um triangulo Equilatero");
		} else if (A == B || A == C || B == C) {
			printf("E um triangulo Isoscele");
		} else {
			printf("E um triangulo Escaleno");
		}
	}
	
	
	
	
}
