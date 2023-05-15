#include <stdio.h>

int main() {
	int arr[4][4], sum=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("Enter element %d %d : ", i, j);
			scanf("%d", &arr[i][j]);
			if (j > i) sum += arr[i][j];
		}
	}
	printf("Sum of element above left diagonal = %d", sum);
}
