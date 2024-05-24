#include <stdio.h>

int main() {
	int be, bc;
	scanf("%d", &bc);
	be = bc+543;
	printf("%d\n", be);
	printf("%d\n", bc/1000+bc/100%10+bc/10%10+bc%10);
	printf("%d", be/1000+be/100%10+be/10%10+be%10);
}
