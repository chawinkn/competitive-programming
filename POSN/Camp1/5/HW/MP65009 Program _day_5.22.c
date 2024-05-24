#include <stdio.h>

int main() {
	int arr[5];
	for (int i = 0; i < 5; i++) {
		scanf("%d", &arr[i]);
	}
	for (int i = 0; i < 5; i++) {
		printf("%d\t", arr[i]);
		for (int j = 0; j < arr[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}
