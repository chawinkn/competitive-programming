#include <stdio.h>
#define __USE_MINGW_ANSI_STDIO 0
 
int main() {
    int q, n[100], c;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &n[i]);
    }
    for (int i = 0; i < q; i++) {
        c = 0;
        for (int j = n[i]/2; j < n[i]-2; j+=2) c++;
        for (int j = 0; j < c; j++) {
            for (int k = 0; k < c-j; k++) {
                printf(".");
            }
            for (int k = 0; k < n[i]/2-2*(c-j)+1; k++) {
                printf("#");
            }
            for (int k = 0; k < 2*(c-j)-1; k++) {
                printf(".");
            }
            for (int k = 0; k < n[i]/2-2*(c-j)+1; k++) {
                printf("#");
            }
            for (int k = c-j; k > 0; k--) {
                printf(".");
            }
            printf("\n");
        }
        for (int j = 0; j < (n[i]/2)+1; j++) {
            for (int k = 0; k < n[i]; k++) {
                if (k >= j && k <= n[i]-j-1) {
                    printf("#");
                }
                else {
                    printf(".");
                }
            }
            printf("\n");
        }
    }
}