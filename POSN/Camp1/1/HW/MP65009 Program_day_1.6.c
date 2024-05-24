#include <stdio.h>

int main() {
	float h, bmi;
	int w;
	scanf("%f", &h);
	scanf("%d", &w);
	bmi = w/(h*h);
	printf("%.1f", bmi);
}
