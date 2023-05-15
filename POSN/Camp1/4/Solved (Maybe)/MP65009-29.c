#include <stdio.h>

int main() {
	int a, b, p, cnt=0;
	printf("find the prime number from : a-->b : ");
	scanf("%d %d", &a, &b);
	for (int i = a+1; i < b; i++) {
		p = 1;
		for (int j = 2; j < i; j++) {
			if (i%j == 0) {
				p = 0;
				break;	
			}
		}
		if (p) {
			printf("%3d ", i);
			cnt++;
		}
	}
	printf("\nMi jumnuan = %d", cnt);
}
