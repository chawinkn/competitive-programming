#include <stdio.h>

int check(char choice) {
	if (choice=='Y' || choice=='y' || choice=='N' || choice=='n') {
		return 1;
	}
	return 0;
}

int main() {
	char choice;
	scanf("%c", &choice);
	if (check(choice)) {
		printf("Yes");
	}
	else {
		printf("No");
	}
}
