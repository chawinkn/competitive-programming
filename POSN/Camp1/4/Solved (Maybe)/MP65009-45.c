#include <stdio.h>

int main() {
	int n, p, cf=0, cp=0;
	scanf("%d", &n);
	if (n >= 1) {
		int factor[n], prime[n];
		for (int i = 1; i <= n; i++) {
			if (n%i == 0) {
				p = 1;
				for (int j = 2; j < i; j++) {
					if (i%j == 0) {
						p = 0;
						break;
					}
				}
				if (p && i != 1) {
					prime[cp] = i;
					cp++;
				}
				factor[cf] = i;
				cf++;
			}
		}
		for (int i = 0; i < cf; i++) {
			printf("%d ", factor[i]);
		}
		printf("\nPrime : ");
		for (int i = 0; i < cp; i++) {
			printf("%d ", prime[i]);
		}
	}
	else {
		printf("Error");
	}
}
