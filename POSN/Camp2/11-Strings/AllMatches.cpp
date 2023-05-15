#include <bits/stdc++.h>
using namespace std;

string text, pattern;

long long int base=67, d=1, h=0, sum=0;

int main() {
    int n, m;
    cin >> n >> m >> text >> pattern;
    for (int i = m-1; i >= 0; i--) {
        h += d*(pattern[i]-'a');
        sum += d*(text[i]-'a');
        d *= base;
    }
    d /= base;
    if (h == sum) {
        cout << 0 << "\n";
    }
    for (int i = 1; i <= n-m; i++) {
        sum -= d*(text[i-1]-'a');
        sum *= base;
        sum += text[i+m-1]-'a';
        if (h == sum) {
            cout << i << "\n";
        }
    }
    cout << -1;
    return 0;
}