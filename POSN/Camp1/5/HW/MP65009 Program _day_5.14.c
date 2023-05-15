#include <stdio.h>

int main() {
	int arr[5];
	for (int i = 0; i < 5; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &arr[i]);
	}
	printf("Reverse order = ");
	for (int i = 4; i >= 0; i--) {
		printf("%d ", arr[i]);
	}
}
