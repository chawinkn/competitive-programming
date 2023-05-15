#include <stdio.h>
#include <math.h>
# define M_PI 3.14159265358979323846

void show(double degree) {
	double radian = degree*(M_PI/180);
	printf("%.2lf\t%.2lf\t%.2lf\n", sin(radian), cos(radian), tan(radian));
}

int main() {
	printf("sin\tcos\ttan\n");
	for (double i = 0; i <= 90; i+=5) {
		show(i);
	}
}
