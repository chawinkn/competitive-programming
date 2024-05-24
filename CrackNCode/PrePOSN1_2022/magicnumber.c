#include <stdio.h>
#define __USE_MINGW_ANSI_STDIO 0
 
int n[1000001];
long long int prime[1000001];

// 52/100 points
 
int main() {
    long long int num = 2;
    int q, p, c=0, max=-1;
    scanf("%d", &q);
    for (int i = 0; i < q; i++) {
        scanf("%d", &n[i]);
        if (n[i] > max) max = n[i];
    }
    while (c < max) {
        p = 1;
        for (long long int i = 2; i*i <= num; i++) {
            if (num%i == 0) p = 0;
        }
        if (p) {
            prime[c] = num*num;
            c++;
        }
        num++;
    }
    for (int i = 0; i < q; i++) {
        printf("%lld\n", prime[n[i]-1]);
    }
}