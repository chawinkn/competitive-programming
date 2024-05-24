#include <stdio.h>

int main() {
	int *p, arr[10], num, sum=0;
	p = arr;
	for (int i = 0; i < 10; i++, p++) {
		printf("Enter number %d : ", i+1);
		scanf("%d", &p);
		*p = num;
		sum += *p;
	}
	printf("Sum = %d", sum);
}
