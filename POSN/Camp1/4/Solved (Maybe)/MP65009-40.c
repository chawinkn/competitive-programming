#include <stdio.h>

int main() {
	int d, m, y;
	int cnt=0, day[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	printf("Enter date : ");
	scanf("%d", &d);
	printf("Enter number of month : ");
	scanf("%d", &m);
	printf("Enter year : ");
	scanf("%d", &y);
	if (y%4 == 0) {
		if (y%100 == 0 && y%400 == 0) {
			if (y%400 == 0) day[1] = 29;
		}
		else day[1] = 29;
	}
	printf("%d\n", day[1]);
	for (int i = 1; i <= m; i++) {
		if (i != m) cnt += day[i-1];
		else cnt += d;
	}
	printf("Number of day : %d", cnt);
}
