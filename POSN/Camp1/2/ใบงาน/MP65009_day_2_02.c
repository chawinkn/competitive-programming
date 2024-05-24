#include <stdio.h>

int main() {
	char c;
	printf("c : Chang mai\n");
	printf("n : Nan\n");
	printf("k : Khon Kaen\n");
	printf("l : Loei\n");
	printf("p : Phangnga\n");
	printf("Enter : ");
	scanf("%c", &c);
	switch (c) {
		case 'c':
			printf("Chiang mai price 15,000 baht");
			break;
		case 'n':
			printf("Nan price 12,000 baht");
			break;
		case 'k':
			printf("Khon Kaen 10,000 baht");
			break;
		case 'l':
			printf("Loei 9,000 baht");
			break;
		case 'p':
			printf("Phangnga 25,000 baht");
			break;
		default:
			printf("Error");
			break;
	}
}
