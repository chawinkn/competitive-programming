#include <stdio.h>

int main() {
	int a[3][2], b[3][2];
	printf("Matrix A\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("Enter element %d %d : ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	printf("Matrix B\n");
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("Enter element %d %d : ", i, j);
			scanf("%d", &b[i][j]);
		}
	}
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("%d\t", a[i][j]+b[i][j]);
		}
		printf("\n");
	}
}
