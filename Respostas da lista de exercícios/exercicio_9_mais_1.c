#include <stdio.h>
int bills(int withdraw);

int main() {
	
	int withdraw;
	printf("Quanto deseja sacar? ");
	scanf("%d", &withdraw);
	bills(withdraw);
	
}

int bills(int withdraw) {
	
	int ATMBills = 123;
	
	printf("Valor disponivel para saque: %d\n", ATMBills);
	
	int hundred = withdraw/ 100;
	int rH = withdraw % 100;

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
	
	ATMBills -= withdraw;
	
	printf("Voce recebera %d notas de 100\n%d notas de 50\n%d notas de 20\n%d notas de 10\n%d notas de 5\n%d notas de 2\n", hundred, fifty, twenty, ten, five, two);
	printf("Valor atualizado disponivel para saque: %d", ATMBills);
}
