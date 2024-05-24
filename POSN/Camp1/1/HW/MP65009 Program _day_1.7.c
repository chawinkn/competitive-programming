#include <stdio.h>

int main() {
	int n;
	scanf("%d", &n);
	printf("B1000 = %d\n", n/1000);
	n -= 1000*(n/1000);
	printf("B500 = %d\n", n/500);
	n -= 500*(n/500);
	printf("B100 = %d", n/100);
}
