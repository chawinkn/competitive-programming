#include <bits/stdc++.h>
using namespace std;

int c[1000009];

int find(int u) {
    if (c[u] == u) return u;
    return c[u] = find(c[u]);
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, p, r, a, b;
    cin >> n >> p >> r;
    for (int i = 1; i <= n; i++) c[i] = i;
    while (p--) {
        cin >> a >> b;
        c[find(a)] = find(b);
    }
    while (r--) {
        cin >> a >> b;
        if (find(a) == find(b)) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}