#include <stdio.h>
#include <math.h>

int main() {
	int a, b, c;
	printf("a = ");
	scanf("%d", &a);
	printf("b = ");
	scanf("%d", &b);
	printf("c = ");
	scanf("%d", &c);
	float x1 = (-b+sqrt(b*b-4*a*c))/2*a;
	float x2 = (-b-sqrt(b*b-4*a*c))/2*a;
	printf("x = %.0f\n", x1);
	printf("x = %.0f", x2);
}
