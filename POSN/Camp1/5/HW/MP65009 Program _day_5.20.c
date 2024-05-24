#include <stdio.h>

int main() {
	int arr[10], factor[8]={1, 2, 4, 5, 8, 10, 20, 40}, cnt=0;
	for (int i = 0; i < 10; i++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &arr[i]);
		for (int j = 0; j < 8; j++) {
			if (arr[i] == factor[j]) {
				cnt++;
				break;
			}
		}
	}
	printf("Number that is factor of 40 count = %d", cnt);
}
