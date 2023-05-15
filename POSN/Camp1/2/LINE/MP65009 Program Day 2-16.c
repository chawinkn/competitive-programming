#include <stdio.h>

int main() {
	int d, use;
	float f=0;
	printf("Enter distance (Kilometer) : ");
	scanf("%d", &d);
	while (d > 0) {
		if (d <= 1) {
			d--;
			f += 35;
		}
		else if (d > 1 && d <= 10) {
			use = d-1;
			d -= use;
			f += use*5.5;
		}
		else if (d > 10 && d <= 20) {
			use = d-10;
			d -= use;
			f += use*6.5;
		}
		else if (d > 20 && d <= 40) {
			use = d-20;
			d -= use;
			f += use*7.5;
		}
		else if (d > 40 && d <= 60) {
			use = d-40;
			d -= use;
			f += use*8;
		}
		else if (d > 60 && d <= 80) {
			use = d-60;
			d -= use;
			f += use*9;
		}
		else if (d > 80) {
			use = d-80;
			d -= use;
			f += use*10.5;
		}
	}
	printf("Taxi fare is %.0f baht", f);
}
