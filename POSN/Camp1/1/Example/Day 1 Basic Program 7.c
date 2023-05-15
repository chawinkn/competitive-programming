#include <stdio.h>

int main() {
	int x1, x2, x3;
	float sum, mean;
	printf("Enter x1, x2, x3 : ");
	scanf("%d, %d, %d", &x1, &x2, &x3);
	sum = x1+x2+x3;
	mean = sum/3;
	printf("Sum = %.2f\n", sum);
	printf("Mean = %f", mean);
}
