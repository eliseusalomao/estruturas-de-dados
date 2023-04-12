#include <stdio.h>
double avg(double num1, double num2, double num3);
double sumAvg(double avg1, double avg2);

int main() {
	
	double num1, num2, num3;
	
	printf("Digite tres primeiros numeros: ");
	scanf("%lf %lf %lf", &num1, &num2, &num3);
	double avg1 = avg(num1, num2, num3);
	
	printf("Digite novamente tres numeros: ");
	scanf("%lf %lf %lf", &num1, &num2, &num3);
	double avg2 = avg(num1, num2, num3);
	
	double sum = sumAvg(avg1, avg2);
	
	printf("A soma das duas medias e: %lf", sum);
}

double avg(double num1, double num2, double num3) {
	
	double average = num1 + num2 + num3 / 3;
	
	
	
	return average;
}

double sumAvg(double avg1, double avg2) {
	
	double firstAvg = avg1;
	double secondAvg = avg2;
	
	return firstAvg + secondAvg;
}


