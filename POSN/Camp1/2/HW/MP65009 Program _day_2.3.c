#include <stdio.h>

int main() {
	int id, base, ot, all;
	float bonus;
	scanf("%d", &id);
	scanf("%d", &base);
	scanf("%d", &ot);
	all = base+ot;
	if (all >= 100000) {
		printf("Bonus = %.2f", all*0.1);
	}
	else if (all >= 70000) {
		printf("Bonus = %.2f", all*0.07);
	}
	else if (all >= 50000) {
		printf("Bonus = %.2f", all*0.05);
	}
	else if (all >= 30000) {
		printf("Bonus = %.2f", all*0.03);
	}
	else {
		printf("Bonus = %.2f", all*0.01);
	}
}
