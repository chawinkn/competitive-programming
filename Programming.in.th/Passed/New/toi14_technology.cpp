#include<bits/stdc++.h>
using namespace std;

int n, k, t, cnt=0, ans=0;
vector<int> lv[10009], g[100009];
int visited[100009];

void dfs(int u) {
    if (visited[u] == 2 || cnt > t) return;
    visited[u] = 1; 
	cnt++;
    for (auto v : g[u]) {
        if (!visited[v]) dfs(v);
        else if (visited[v] == 1) cnt = 2e8;
    }
    visited[u] = 2;
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
    cin >> n >> k >> t;
    for (int i = 1; i <= n; i++) {
        int l, p, q;
		cin >> l >> p;
        lv[l].push_back(i);
        while (p--) {
			cin >> q;
            g[i].push_back(q);
        }
    }
    for (int i = 1; i <= k; i++) {
        for (auto u : lv[i]) {
            if (!visited[u]) dfs(u);
        }
        if (cnt > t) break;
        ans=i;
    }
	cout << (ans == 0 ? -1 : ans);
    return 0;
}