#include <stdio.h>

int main() {
	int n, m=1;
	scanf("%d", &n);
	int cnt[10]={0};
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == 0 || i == n-1) {
				printf("%d", m);
				cnt[m]++;
				m = (m+1)%10;
			}
			else {
				if (j == n-i-1) {
					printf("%d", m);
					cnt[m]++;
					m = (m+1)%10;
					break;
				}
				else {
					printf(" ");
				}
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 10; i++) {
		printf("%d=%d ", i, cnt[i]);
	}
}
