#include <stdio.h>

int main() {
	int arr[10], temp;
	for (int i = 0; i < 10; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 9; i++) {
		for (int j = i+1; j < 10; j++) {
			if (arr[j] < arr[i]) {
				temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
			}
		}
	}
	printf("Ascending Order : ");
	for (int i = 0; i < 10; i++) {
		printf("%d ", arr[i]);
	}
}
