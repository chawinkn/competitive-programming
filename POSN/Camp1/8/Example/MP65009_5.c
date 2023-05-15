#include <stdio.h>

float f(float x) {
	return (x*x*x)/3-(3*x*x)/2+2*x;
}

float area(float x1, float x2) {
	float a = f(x1)-f(x2);
	if (a < 0) {
		return -a;
	}
	return a;
}

int main() {
	printf("%f", area(2.0, 1.0));
}
