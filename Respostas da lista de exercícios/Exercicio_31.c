#include <stdio.h>

int main() {
	
	double fahrenheit = 140.00;
	double celsius = (fahrenheit - 32) * 5/9;
	
	for (celsius; celsius >= 50 && celsius <= 65; celsius++) {
		double convertCtoF = (celsius * 9/5) + 32;
		printf("Celsius = %.2lf, Fahrenheit = %.2lf\n", celsius, convertCtoF);
	}
	
	
	
	
	
}
