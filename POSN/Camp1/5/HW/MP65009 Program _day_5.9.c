#include <stdio.h>

int main() {
	int arr[10];
	for (int i = 0; i < 10; i++) {
		printf("Input %d : ", i);
		scanf("%d", &arr[i]);
	}
	printf("Element \tValue \t\tHistogram\n");
	for (int i = 0; i < 10; i++) {
		printf("%4d\t\t%4d\t\t   ", i, arr[i]);
		for (int j = 0; j < arr[i]; j++) {
			printf("*");
		}
		printf("\n");
	}
}
