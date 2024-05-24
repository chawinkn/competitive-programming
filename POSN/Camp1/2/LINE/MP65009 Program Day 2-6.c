#include <stdio.h>

int main() {
	int p, prime[25], c=0;
	for (int i = 2; i <= 100; i++) {
		p = 1;
		for (int j = 2; j*j <= i; j++) {
			if (i%j == 0) {
				p = 0;
				break;	
			}
		}
		if (p == 1) {
			prime[c] = i;
			c++;	
		}
	}
	c = 0;
	while (c < 25) {
		if (c%7 == 6) {
			printf("%d\n", prime[c]);
		}
		else {
			printf("%d\t", prime[c]);
		}
		c++;
	}
}
