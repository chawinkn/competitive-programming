#include <stdio.h>

int main() {
	int r;
	float PI=3.14159, area;
	char c='Y';
	while (c != 'N' && c != 'n') {
		printf("Enter radius : ");
		scanf("%d", &r);
		area = PI*r*r;
		printf("Circle area = %.2f\n\n", area);
		printf("Continue (Y/N) ? : ");
		scanf(" %c", &c);
	}
}
