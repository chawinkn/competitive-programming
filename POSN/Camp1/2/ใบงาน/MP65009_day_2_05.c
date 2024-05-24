#include <stdio.h>

int main() {
	int n, b, h;
	float area;
	printf("1 : Area of triangle\n");
	printf("2 : Area of square\n");
	printf("Enter : ");
	scanf("%d", &n);
	switch (n) {
		case 1:
			printf("Enter base : ");
			scanf("%d", &b);
			printf("Enter height : ");
			scanf("%d", &h);
			area = 0.5*b*h;
			printf("Area of triangle = %.2f", area);
			break;	
		case 2:
			printf("Enter base : ");
			scanf("%d", &b);
			printf("Enter height : ");
			scanf("%d", &h);
			area = b*h;
			printf("Area of square = %.2f", area);
			break;
		default:
			printf("Error");
			break;
	}
}
