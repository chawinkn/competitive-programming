#include <stdio.h>

int main() {
	int n, k, h, m=-1;
	scanf("%d %d", &n, &k);
	for (int i = 0; i < n; i++) {
		scanf("%d", &h);
		if (h <= k && h > m) {
			m = h;
		}
	}
	printf("%d", m);
}
