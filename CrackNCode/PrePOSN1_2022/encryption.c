#include <stdio.h>
 
int main() {
    long long int num;
    int sum, n, d, b[5][63], ans[5];
    for (int i = 0; i < 5; i++) {
        scanf("%lld", &num);
        n = 0;
        while (num > 0) {
            b[i][n] = num%2;
            num /= 2;
            n++;
        }
        sum = 0;
        d = 1;
        for (int j = 0; j < n; j++) {
            if (b[i][j] != 0) {
                sum += d*b[i][j];
                d *= 2;
            }
            else {
                d = 1;
            }
        }
        ans[i] = sum;
    }
    for (int i = 0; i < 5; i++) {
        printf("%d\n", ans[i]);
    }
}