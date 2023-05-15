#include <stdio.h>

int main() {
	int dec, oct, hex, d;
	printf("Dec\tOct\tHex\n");
	printf("---------------------\n");
	for (int i = 0; i <= 15; i++) {
		dec = i;
		printf("%d\t", dec);
		
		oct = 0;
		d = 1;
		while (dec > 0) {
			oct += (dec%8)*d;
			d *= 10;
			dec /= 8;
		}
		printf("%d\t", oct);
		
		dec = i;
		hex = 0;
		d = 1;
		while (dec > 0) {
			hex += (dec%16)*d;
			d *= 10;
			dec /= 16;
		}
		if (hex <= 9) {
			printf("%d\n", hex);
		}
		else {
			printf("%c\n", 'A'+hex-10);
		}
	}
}
