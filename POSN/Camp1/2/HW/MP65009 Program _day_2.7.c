#include <stdio.h>

int main() {
	int r, m;
	float PI=3.14;
	printf("Please input radius : ");
	scanf("%d", &r);
	printf("Calculator Menu :\n");
	printf("\t1. Find area\n");
	printf("\t2. Find circumference\n");
	printf("Choose menu : ");
	scanf("%d", &m);
	if (m == 1) {
		float a = PI*r*r;
		printf("Area = %.2f", a);
	}
	else if (m == 2) {
		float c = 2*PI*r;
		printf("Circumference = %.2f", c);
	}
	else {
		printf("Error");
	}
}
