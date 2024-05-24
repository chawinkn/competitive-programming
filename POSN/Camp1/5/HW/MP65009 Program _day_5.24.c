#include <stdio.h>

int main() {
	int b[5], r=1, d=0;
	for (int i = 0; i < 5; i++) scanf("%d", &b[i]);
	for (int i = 4; i >= 0; i--) {
		d += b[i]*r;
		r *= 2;
	}
	printf("Hexadecimal = %X", d);
}
