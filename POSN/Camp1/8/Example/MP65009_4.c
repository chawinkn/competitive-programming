#include <stdio.h>

int f(int x) {
	return x*x+1;
}

int main() {
	int x;
	scanf("%d", &x);
	printf("%d", f(x));
}
