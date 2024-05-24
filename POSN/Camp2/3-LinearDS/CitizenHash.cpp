#include <bits/stdc++.h>
using namespace std;

long long int h[100];

int main() {
    int n, k, founded;
    long long int id;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> id;
        k = id%100;
        if (h[k] == 0) h[k] = id;
        else {
            founded = 0;
            for (int j = k+1; j < 100; j++) {
                if (h[j] == 0) {
                    h[j] = id;
                    founded = 1;
                    break;
                }
            }
            if (!founded) {
                for (int j = 0; j < k; j++) {
                    if (h[j] == 0) {
                        h[j] = id;
                        break;
                    }
                }
            }
        }
    }
    for (int i = 0; i < 100; i++) {
        if (h[i] != 0) {
            printf("%02d,%lld\n", i, h[i]);
        }
    }
    return 0;
}
