#include <stdio.h>

int main() {
	int arr[20], max, min, sum=0;
	float mean;
	for (int i = 0; i < 20; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &arr[i]);
		if (i == 0) {
			max = arr[i];
			min = arr[i];
		}
		if (arr[i] > max) max = arr[i];
		if (arr[i] < min) min = arr[i];
		sum += arr[i];
	}
	mean = sum/20;
	printf("Mean = %.2f\n", mean);
	printf("Maximum = %d\n", max);
	printf("Minimum = %d", min);
}
