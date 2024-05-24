#include <stdio.h>

int main() {
	int unit, unit_use, charge;
	float pay=0, vat;
	printf("Enter water unit : ");
	scanf("%d", &unit);
	printf("Enter Service charge : ");
	scanf("%d", &charge);
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
		else {
			unit_use = unit-100;
			unit -= unit_use;
			pay += 15*unit_use;
		}
	}
	pay += charge;
	printf("Water bill before VAT is %.2f Baht\n", pay);
	vat = 0.07*pay;
	printf("VAT is 7.00%% is %.2f Baht\n", vat);
	pay += vat;
	printf("Total water bill is %.2f Baht", pay);
}
