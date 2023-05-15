#include <stdio.h>
#include <conio.h>

int main() {
	char ch='A';
	while (ch <= 'Z') {
		printf("%c\n", ch);
		ch++;
	}
	getch();
	return 0;
}
