#include <stdio.h>

int main() {
	FILE *fp;
	char c; 
	fp = fopen("E:\\001.txt", "r");
	c = getc(fp);
	while (c != EOF) {
		printf("%c", c);
		c = getc(fp);
	}
	fclose(fp);
}
