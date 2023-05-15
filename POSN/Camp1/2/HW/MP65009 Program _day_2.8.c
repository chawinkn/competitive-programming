#include <stdio.h>

int main() {
	int area;
	float price;
	printf("Please input area : ");
	scanf("%d", &area);
	if (area > 400) {
		price = area*5;
	}
	else if (area > 200 && area <= 400) {
		price = area*7.5;
	}
	else if (area >= 80 && area <= 200) {
		price = area*10;
	}
	else if (area < 80) {
		price = area*12.5;
	}
	printf("Total service costs : %.0f baht", price);
}
