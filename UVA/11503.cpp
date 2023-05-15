#include <bits/stdc++.h>
using namespace std;

int parent[100003], cnt[100003];

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

int merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) {
        if (cnt[u] > cnt[v]) {
            parent[v] = u;
            cnt[u] += cnt[v];
            return cnt[u];
        }
        else {
            parent[u] = v;
            cnt[v] += cnt[u];
            return cnt[v];
        }
    }
    return cnt[u];
}

int main() {
    int n, f, k;
    string a, b;
    cin >> n;
    while (n--) {
        cin >> f;
        map<string,int> m;
        k = 1;
        for (int i = 1; i <= 100000; i++) {
            parent[i] = i;
            cnt[i] = 1;
        }
        while (f--) {
            cin >> a >> b;
            if (m.find(a) == m.end()) {
                m[a] = k;
                k++;
            }
            if (m.find(b) == m.end()) {
                m[b] = k;
                k++;
            }
            cout << merge(m[a], m[b]) << "\n";
        }
    }
    return 0;
}