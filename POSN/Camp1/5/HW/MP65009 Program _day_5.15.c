#include <stdio.h>

int main() {
	int arr[20], cnt=0;
	for (int i = 0; i < 20; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &arr[i]);
		if (arr[i] > 0) cnt++;
	}
	printf("Positive number count = %d", cnt);
}
