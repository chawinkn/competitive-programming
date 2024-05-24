#include <bits/stdc++.h>
using namespace std;

long long int fib[53];

int main() {
    int n;
    fib[1] = 1;
    for (int i = 2; i <= 50; i++) fib[i] = fib[i-1]+fib[i-2];
    while (cin >> n) {
        if (n < 0) {
            printf("End\n");
            break;
        }
        printf("F(%d) = %lld\n", n, fib[n]);
    }
    return 0;
}