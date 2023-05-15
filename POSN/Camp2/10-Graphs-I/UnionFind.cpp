#include <bits/stdc++.h>
using namespace std;

int parent[53];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[u] = v;
}

int main() {
    int n, k, s=0, u=0;
    char t;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) parent[i] = i;
    while (k--) {
        int i, j;
        cin >> t >> i >> j;
        if (t == 'c') merge(i, j);
        else {
            if (find(i) == find(j)) s++;
            else u++;
        }
    }
    cout << s << " " << u;
    return 0;
}