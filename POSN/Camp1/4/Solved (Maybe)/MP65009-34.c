#include <stdio.h>

int main() {
	int n, m=1;
	printf("Enter The Number : ");
	scanf("%d", &n);
	while (n > 1) {
		n /= 2;
		m *= 2;
	}
	if (m == 1) {
		printf("1 = 1");
	}
	else if (m == 2) {
		printf("1+(1/2) = 3/4");
	}
	else {
		printf("1+(1/2)+...+(1/%d) = %d/%d", m, 2*m-1, 2*m);
	}
}
