#include <bits/stdc++.h>
using namespace std;

string text, pattern="apple";

long long int base=67, d, h, sum;

int main() {
    int n, m=5, cnt=0;
    while (getline(cin, text)) {
        n = text.length();
        d = 1;
        h = 0;
        sum = 0;
        for (int i = m-1; i >= 0; i--) {
            h += d*(pattern[i]-'a');
            sum += d*(text[i]-'a');
            d *= base;
        }
        d /= base;
        if (h == sum) cnt++;
        for (int i = 1; i <= n-m; i++) {
            sum -= d*(text[i-1]-'a');
            sum *= base;
            sum += text[i+m-1]-'a';
            if (h == sum) cnt++;
        }
    }
    cout << cnt;
    return 0;
}