#include <stdio.h>

int main() {
	int n, set[100001]={0}, mode=0, max=-1, sum=0, cnt=0;
	scanf("%d", &n);
	int arr[n];
	// 0 <= arr[i] <= 100000
	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
		set[arr[i]]++;
		if (arr[i] > max) max = arr[i];
		if (set[arr[i]] > mode) mode = set[arr[i]];
	}
	for (int i = 0; i <= max; i++) {
		if (set[i] != 0) {
			sum += set[i];
			cnt++;	
		}
	}
	if (cnt != sum) {
		printf("Mode is ");
		for (int i = 0; i <= max; i++) {
			if (set[i] == mode) printf("%d ", i);
		}
	}
	else {
		printf("No mode");
	}
}
