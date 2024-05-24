#include <stdio.h>

int main() {
	int x, y, z;
	float d;
	scanf("%d", &x);
	scanf("%d", &y);
	scanf("%d", &z);
	if (x+y < x+z && x+y < y+z) {
		d = x+y;
		printf("%.0f Meters\n%.4f Second", d, d/16);
	}
	else if (x+z < x+y && x+z < y+z) {
		d = x+z;
		printf("%.0f Meters\n%.4f Second", d, d/16);
	}
	else if (y+z < x+y && y+z < x+z) {
		d = y+z;
		printf("%.0f Meters\n%.4f Second", d, d/16);
	}
}
