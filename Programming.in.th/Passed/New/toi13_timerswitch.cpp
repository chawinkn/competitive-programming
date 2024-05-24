#include <bits/stdc++.h>
using namespace std;

#define ll long long
string s;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n >> s;
    ll h=0, b=1, base=98765431;
    for (int i = n-1; i >= 0; i--) {
        h += s[i]*b;
        if (i != 0) b *= base;
    }
    ll nh=h;
    for (int i = 0; i < n; i++) {
        nh -= b*s[i];
        nh *= base;
        nh += s[i];
        if (nh == h) {
            cout << i+1;
            break;
        }
    }
    return 0;
}