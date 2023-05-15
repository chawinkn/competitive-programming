#include <stdio.h>

int main() {
	int a, b, c, d;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	if (a >= 0 && a <= 100 && b >= 0 && b <= 100 && c >= 0 && c <= 100 && d >= 0 && d <= 100) {
		int sum;
		float mean;
		sum = a+b+c+d;
		mean = sum/4;
		printf("Mean = %.2f", mean);
	}
	else {
		printf("Invalid input!!");
	}
}
