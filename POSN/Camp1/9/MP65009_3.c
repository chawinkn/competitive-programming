#include<stdio.h>
#include<string.h>

int main(){
	FILE *fp = fopen("E:\\003.txt", "a");
	char newname[] = "Kitti 25 177.5";
	int point = 0;
	putc('\n', fp);
	do {
		putc(newname[point], fp);
		point++;
	}
	while(point<strlen(newname));
	fclose(fp);
}
