#include <stdio.h>

int main() {
	int arr[4][4], sum=0;
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			printf("Enter element %d %d : ", i, j);
			scanf("%d", &arr[i][j]);
			if (i == j || i+j == 3) sum += arr[i][j];
		}
	}
	printf("Sum of element in two diagonal = %d", sum);
}
