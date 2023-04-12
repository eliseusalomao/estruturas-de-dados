#include <stdio.h>
#include <ctype.h>

#define VPd VP = VF + (VF * 0.3);

int main() {
	
	printf("Informe sua classe de consumidor: ");
	char classeConsumidor = scanf("%c", &classeConsumidor);
	
	printf("Informe seu consumo em Kw por hora: ");
	double consumoKw = scanf("%lf", &consumoKw);
	
	if (classeConsumidor == 'A') {
		double VF = consumoKw * 0.5;
		printf("%.2lf", VPd);
	} else if (classeConsumidor == 'B') {
		double VF = consumoKw * 0.8;
		double VPd;
		printf("%.2lf", VPd);
	}
	
	
	
	
	
	
	
	
	
	
}
