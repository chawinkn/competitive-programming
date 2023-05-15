#include <stdio.h>

int main() {
	int arr[20], sum=0;
	for (int i = 0; i < 20; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &arr[i]);
		if (i%2 == 0) sum += arr[i];
	}
	printf("Sum of odd index = %d", sum);
}
