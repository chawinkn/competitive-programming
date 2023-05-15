#include <stdio.h>

int main() {
    int n, m, t=1;
    scanf("%d", &n);
    scanf("%d", &m);
    for (int i = 0; i < 3; i++) {
        for (int b = 0; b < n-1; b++) {
            printf("  \t");
            t++;
        }
        for (int d = 1; d <= m; d++) {
            printf("%2d\t", d);
            if (t%7 == 0) {
                printf("\n");
            }
            t++;
        }
        n = (m+n)%7;
        if (n == 0) n = 7;
        t = 1;
        printf("\n");
    }
}
