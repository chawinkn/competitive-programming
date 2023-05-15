#include <stdio.h>

int main() {
	int a[3][2], t[2][3];
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 2; j++) {
			printf("Enter element %d %d : ", i, j);
			scanf("%d", &a[i][j]);
		}
	}
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			t[i][j] = a[j][i];
		}
	}
	printf("\n");
	for (int i = 0; i < 2; i++) {
		for (int j = 0; j < 3; j++) {
			printf("%d\t", t[i][j]);
		}
		printf("\n");
	}
}
