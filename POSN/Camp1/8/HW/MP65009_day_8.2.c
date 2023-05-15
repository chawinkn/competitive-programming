#include <stdio.h>
#include <math.h>

int pytagorus(int a, int b) {
	int c;
	c = sqrt(a*a+b*b);
	return c;
}

int main() {
	int a, b;
	scanf("%d", &a);
	scanf("%d", &b);
	printf("%d", a+b+pytagorus(a, b));
}
