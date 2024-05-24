#include <stdio.h>
int main() {
	FILE *fl; 
	int i; 
	fl=fopen("E:\\005.txt","w") ;
	for (i=0;i<10;i++) {
		fprintf (fl,"%d\t",i);
		printf ("%d\t",i);
	}
	fclose(fl);
}

