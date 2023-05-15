#include <stdio.h>

int main() {
	int arr[20], sum=0, cnt=0;
	float mean;
	for (int i = 0; i < 20; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &arr[i]);
		if (arr[i] > 0) {
			sum += arr[i];
			cnt++;
		}
	}
	mean = sum/cnt;
	printf("Mean of positive number = %.2f", mean);
}
