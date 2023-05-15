#include <stdio.h>

int main() {
	float r, c, PI=3.1415926;
	printf("Enter radius (r) : ");
	scanf("%f", &r);
	c = 2*PI*r;
	printf("Circumference = %.2f\n", c);
	printf("Circumference = %f", c);
}
