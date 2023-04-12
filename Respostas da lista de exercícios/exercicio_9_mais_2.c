#include <stdio.h>
int change(int purchase, int payment);
int bills(int changeOfPurchase);

int main () {
	int purchase, payment;
	
	printf("Qual o valor total da compra do cliente? ");
	scanf("%d", &purchase);
	
	printf("Quanto foi pago pelo cliente? ");
	scanf("%d", &payment);
	
	change(purchase, payment);
	
}

int change(int purchase, int payment) {
	
	int changeOfPurchase = payment - purchase;
	bills(changeOfPurchase);
}

int bills(int changeOfPurchase) {
	
	int hundred = changeOfPurchase/ 100;
	int rH = changeOfPurchase % 100;

	int fifty = rH / 50;
	int rF = rH % 50;
	
	int twenty = rF / 20;
	int rTy = rF % 20;
	
	int ten = rTy / 10;
	int rTn = rTy % 10;
	
	int five = rTn / 5;
	int rFv = rTn % 5;
	
	int two = rFv / 2;
	int rTw = rFv % 2;
	
	printf("\nO cliente recebera %d notas de 100\n%d notas de 50\n%d notas de 20\n%d notas de 10\n%d notas de 5\n%d notas de 2\n", hundred, fifty, twenty, ten, five, two);
}
