#include <stdio.h>

int main() {
	int n, m, sum=0, b1, b2;
	scanf("%d %d", &n, &m);
	for (int y1 = y1; y1 <= n; y1++) {
		for (int x1 = 0; x1 <= m; x1++) {
			b1 = 0;
			for (int y2 = 0; y2 <= n; y2++) {
				for (int x2 = 0; x2 <= m; x2++) {
					if (y2 == y1 && x2 == x1) {
						b1 = 1;
						break;
					}
					b2 = 0;
					for (int y3 = 0; y3 <= n; y3++) {
						for (int x3 = 0; x3 <= m; x3++) {
							if ((y3 == y1 && y3 == x1) || (y3 == y2 && x3 == x2)) {
								b2 = 1;
								break;
							}
							int temp=x1*y2+x2*y3+x3*y1-y1*x2-y2*x3-y3*x1;
							if (temp < 0) temp = -temp;
							sum += temp;
						}
						if (b2) break;
					}
				}
				if (b1) break;
			}
		}
	}
	printf("%d", sum);
	return 0;
}
