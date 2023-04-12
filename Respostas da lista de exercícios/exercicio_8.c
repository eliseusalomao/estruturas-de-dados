#include <stdio.h>

int main() {
	
	double salarioFixo;
	int totalVendas;
	
	printf("Informe o seu salario fixo e, em seguida, quantas vendas fez no mes: ");
	scanf("%lf %d", &salarioFixo, &totalVendas);
	
	double comissao = totalVendas * 0.15;
	double salarioTotal = salarioFixo + comissao;
	
	printf("O seu salario fixo corresponde ha: %.2lf\nCom as vendas efetuadas seu salario ao final do mes sera de: %.2lf", salarioFixo, salarioTotal);
	
		
	
	
	return 0;
}
