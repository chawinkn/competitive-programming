#include <stdio.h>

int main() {
	int a, b, c, d, e, even=0, odd=0;
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);
	scanf("%d", &d);
	scanf("%d", &e);
	if (a%2 == 0) even++;
	else odd++;
	if (b%2 == 0) even++;
	else odd++;
	if (c%2 == 0) even++;
	else odd++;
	if (d%2 == 0) even++;
	else odd++;
	if (e%2 == 0) even++;
	else odd++;
	printf("Even %d numbers\n", even);
	printf("Odd %d numbers", odd);
}
