#include <iostream>
using namespace std;

int main() {
    int n, a, b, z, found, check;
    while (cin >> n) {
        if (n == 0) break;
        found = 0;
        for (int i = 1234; i <= 99999; i++) {
            a = i;
            b = n*i;
            if (b > 99999) break;
            int v[10]={0};
            z = 5;
            while (a > 0) {
                v[a%10]++;
                a /= 10;
                z--;
            }
            v[0] += z;
            z = 5;
            while (b > 0) {
                v[b%10]++;
                b /= 10;
                z--;
            }
            v[0] += z;
            check = 1;
            for (int j = 0; j < 10; j++) {
                if (v[j] != 1) {
                    check = 0;
                    break;
                }
            }
            if (check) {
                found = 1;
                printf("%05d / %05d = %d\n", i*n, i, n);
            }
        }
        if (!found) printf("There are no solutions for %d.\n", n);
        printf("\n");
    }
    return 0;
}