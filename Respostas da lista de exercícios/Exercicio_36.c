#include <stdio.h>

int main() {
	
	double S;
	
	int i;
	for(i = 1; i <= 10; ++i) {
		S += 1 + (1/(i+1));
	}
	
	printf("%.lf", S);
}
