#include <stdio.h>

int main() {
	int n;
	char month[12][10]={"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
	printf("Enter number 1-12 of Month : ");
	scanf("%d", &n);
	printf("Month name is %s", month[n-1]);
}
