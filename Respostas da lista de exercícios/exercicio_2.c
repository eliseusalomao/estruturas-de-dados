#include <stdio.h>

int main() {
	
	int a;
	
	printf("Insira um numero e saiba seu sucesso e antecessor: \n");
	scanf("%d", &a);
	
	int antecessor = a;
	int sucessor = antecessor+1;
	
	printf("O numero escolhido foi: %d\nSeu antecessor: %d\nSeu sucessor: %d", a, --antecessor, sucessor);
	
	
	
	return 0;
}
