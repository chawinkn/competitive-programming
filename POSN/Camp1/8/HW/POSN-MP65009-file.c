#include <stdio.h>
#include <stdlib.h>

int main(){
	FILE *f1, *f2;
	int i, n=0, x=100000;
	int a[x], cnt[1000]={0}, max=-1, num;
	time_t t; // Initializes random
	srand((unsigned) time(&t));
	for(i=0;i<x;i++) {
		a[i]=rand()%1000;	
	}
	// code is all yours
	printf("Before sorting in d:\\before.txt\n");
	f1 = fopen("d:\\before.txt", "w");
	for (i = 0; i < x; i++) {
		cnt[a[i]]++;
		if (cnt[a[i]] > max) {
			max = cnt[a[i]];
			num = a[i];	
		}
//		printf("%d ", a[i]);
		fprintf(f1, "%d ", a[i]);
	}
	fclose(f1);
	// Sort
	for (i = 0; i < 1000; i++) {
		for (int j = 0; j < cnt[i]; j++) {
			a[n] = i;
			n++;
		}
	}
	printf("\nAfter Sorting in d:\\after.txt\n");
	f2 = fopen("d:\\after.txt", "w");
	for (i = 0; i < x; i++) {
//		printf("%d ", a[i]);
		fprintf(f2, "%d ", a[i]);
	}
	fclose(f2);
	printf("\nMost duplicate number = %d\n", num);
	printf("Count = %d\n", max);
	return 0 ;
}
