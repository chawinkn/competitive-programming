#include <stdio.h>

int main() {
	int n;
	printf("Enter number for loop : ");
	scanf("%d", &n);
	int num, max;
	for (int i = 0; i < n; i++) {
		printf("Number #%d : ", i+1);
		scanf("%d", &num);
		if (i == 0) max = num;
		if (num > max) max = num;
	}
	printf("Maximum is %d", max);
}
