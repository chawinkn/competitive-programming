#include <stdio.h>

int main() {
	int n;
	printf("Enter number for loop : ");
	scanf("%d", &n);
	int num, min;
	for (int i = 0; i < n; i++) {
		printf("Number #%d : ", i+1);
		scanf("%d", &num);
		if (i == 0) min = num;
		if (num < min) min = num;
	}
	printf("Minimum is %d", min);
}
