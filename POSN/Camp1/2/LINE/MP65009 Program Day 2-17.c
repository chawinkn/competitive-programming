#include <stdio.h>

int main() {
	int unit, unit_use, pay=0;
	printf("Enter water unit : ");
	scanf("%d", &unit);
	while (unit > 0) {
		if (unit <= 20) {
			unit_use = unit;
			unit -= unit_use;
			pay += 5*unit_use;
		}
		else if (unit > 20 && unit <= 40) {
			unit_use = unit-20;
			unit -= unit_use;
			pay += 7*unit_use;
		}
		else if (unit > 40 && unit <= 100) {
			unit_use = unit-40;
			unit -= unit_use;
			pay += 10*unit_use;
		}
		else if (unit > 100) {
			unit_use = unit-100;
			unit -= unit_use;
			pay += 15*unit_use;
		}
	}
	printf("Pay water is %d Baht", pay);
}
