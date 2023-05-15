#include <stdio.h>

int main() {
	int n, fac=1;
	printf("Enter a positive number : ");
	scanf("%d", &n);
	for (int i = 2; i <= n; i++) {
		printf("%d ", i);
		if (i == n) printf("= ");
		else printf("x ");
		fac *= i;
	}
	printf("%d", fac);
}
