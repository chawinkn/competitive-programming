#include <stdio.h>

int main() {
	int num, p, c=0;
	printf("Enter number : ");
	scanf("%d", &num);
	for (int i = 1; i <= num; i++) {
		p = 1;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) p = 0;
		}
		if (p && i != 1) {
			printf("%d\n", i);
			c++;
		}
	}
	printf("1-%d have %d prime numbers", num, c);
}
