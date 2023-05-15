#include <stdio.h>

int main() {
	int a, b;
	printf("Enter multiplication from : ");
	scanf("%d", &a);
	printf("Enter multiplication to : ");
	scanf("%d", &b);
	for (int i = 1; i <= 12; i++) {
		for (int j = a; j <= b; j++) {
			printf("%2dx%2d=%3d\t", j, i, j*i);
		}
		printf("\n");
	}
}
