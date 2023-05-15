#include <stdio.h>

int leap(int y) {
	if ((y%400==0)||((y%4==0)&&(y%100!=0))) return 1;
	else return 0;
}

int date(int m, int y) {
	int d[12]={31,28,31,30,31,30,31,31,30,31,30,31};
	if (m == 2) {
		if (leap(y)) return d[m-1]+1;	
		else return d[m-1];
	}
	else return d[m-1];
}

int main() {
	int m, y;
	scanf("%d", &m);
	scanf("%d", &y);
	y -= 543;
	printf("%d", date(m, y));
}
