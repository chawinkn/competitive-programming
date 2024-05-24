#include <stdio.h>

int main() {
	int n, num=2, p, cnt=0;
	printf("Enter n : ");
	scanf("%d", &n);
	int prime[n];
	while (cnt < n) {
		p = 1;
		for (int i = 2; i < num; i++) {
			if (num%i == 0) {
				p = 0;
				break;
			}
		}
		if (p) {
			prime[cnt] = num;
			cnt++;
		}
		num++;
	}
	if (n > 0) {
		printf("First %d prime number = ", n);
		for (int i = 0; i < cnt; i++) {
			printf("%d ", prime[i]);
		}	
	}
	else {
		printf("Error");
	}
}
