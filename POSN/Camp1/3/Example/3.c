#include <stdio.h>
#include <conio.h>

int main() {
	char ch='A';
	while (ch <= 'Z') {
		printf("%c = %d\n", ch, ch);
		ch++;
	}
	getch();
	return 0;
}
