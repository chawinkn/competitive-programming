#include <stdio.h>
#include <string.h>

int main() {
	char s[101], b;
	int h, w, n;
	printf("Input String      ==> ");
	scanf("%s", s);
	printf("Height String     ==> ");
	scanf("%d", &h);
	printf("Width String      ==> ");
	scanf("%d", &w);
	printf("Border Character  ==> ");
	scanf(" %c", &b);
	printf("Border Width      ==> ");
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n+strlen(s)*w; j++) {
			printf("%c", b);
		}
		printf("\n");
	}
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			printf("%c", b);
		}
		for (int j = 0; j < w; j++) {
			printf("%s", s);
		}
		for (int j = 0; j < n; j++) {
			printf("%c", b);
		}
		printf("\n");
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < 2*n+strlen(s)*w; j++) {
			printf("%c", b);
		}
		printf("\n");
	}
}
