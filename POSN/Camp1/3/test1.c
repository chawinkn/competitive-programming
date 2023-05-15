#include <stdio.h>

int main() {
	int m, n;
	float r, d;
	printf("Enter money for change : ");
	scanf("%f", &r);
	m = r;
	d = r-m;
	
//	Long
	if (m >= 1000) {
		n = m/1000; 
		m -= n*1000;
		printf("%4d Baht = %d\n", 1000, n);
	}
	if (m >= 500) {
		n = m/500; 
		m -= n*500;
		printf("%4d Baht = %d\n", 500, n);
	}
	if (m >= 100) {
		n = m/100; 
		m -= n*100;
		printf("%4d Baht = %d\n", 100, n);
	}
	if (m >= 50) {
		n = m/50; 
		m -= n*50;
		printf("%4d Baht = %d\n", 50, n);
	}
	if (m >= 20) {
		n = m/20; 
		m -= n*20;
		printf("%4d Baht = %d\n", 20, n);
	}
	if (m >= 10) {
		n = m/10; 
		m -= n*10;
		printf("%4d Baht = %d\n", 10, n);
	}
	if (m >= 5) {
		n = m/5; 
		m -= n*5;
		printf("%4d Baht = %d\n", 5, n);
	}
	if (m >= 2) {
		n = m/2; 
		m -= n*2;
		printf("%4d Baht = %d\n", 2, n);
	}
	if (m >= 1) {
		n = m; 
		m -= n;
		printf("%4d Baht = %d\n", 1, n);
	}
	if (d >= 0.50) {
		n = d/0.5; 
		d -= n*0.5;
		printf("%4d Satang = %d\n", 50, n);
	}
	if (d >= 0.25) {
		n = d/0.25; 
		d -= n*0.25;
		printf("%4d Satang = %d\n", 25, n);
	}
	
//	Short
//	float t[] = {1000, 500, 100, 50, 20, 10, 5, 2, 1, 0.50, 0.25};
//	for (int i = 0; i < 11; i++) {
//		if (i <= 8) {
//			if (m >= t[i]) {
//				n = m/t[i];
//				m -= n*t[i];
//				printf("%4.0f Baht = %d\n", t[i], n);
//			}
//		}
//		else {
//			if (d >= t[i]) {
//				n = d/t[i];
//				d -= n*t[i];
//				printf("%4.0f Satang = %d\n", t[i]*100, n);
//			}
//		}
//	}
	
	if (d != 0) {
		printf("%4d Satang = %.0f (Can't change)\n", 1, d/0.01);
	}
}
