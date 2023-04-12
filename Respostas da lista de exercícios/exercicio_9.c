#include <stdio.h>

int main() {
	
	int A, B;
	printf("Quanto A ira valer inicialmente? ");
	scanf("%d", &A);
	printf("Quanto B ira valer inicialmente? ");
	scanf("%d", &B);
	
	int C;
	
	C = A;
	A = B;
	B = C;
	
	printf("Agora A vale: %d\nE B vale: %d", A, B);
	
	
	return 0;
}
