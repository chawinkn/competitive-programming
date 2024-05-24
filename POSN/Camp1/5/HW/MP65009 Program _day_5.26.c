#include <stdio.h>

int main() {
	int arr[5][3], row[5]={0}, col[3]={0};
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 3; j++) {
			printf("Enter element %d %d : ", i, j);
			scanf("%d", &arr[i][j]);
			row[i] += arr[i][j];
			col[j] += arr[i][j];
		}
	}
	for (int i = 0; i < 5; i++) printf("Sum of element in row %d = %d\n", i, row[i]);
	printf("\n");
	for (int i = 0; i < 3; i++) printf("Sum of element in col %d = %d\n", i, col[i]);
}
