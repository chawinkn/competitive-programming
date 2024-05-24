#include <bits/stdc++.h>
using namespace std;

vector<int> g[100009];
int bonus[100009];
queue<int> q;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
   	int n, m, a, b, x, y;
   	cin >> n >> m;
   	for (int i = 0; i < n-1; i++) {
 		cin >> a >> b;
 		g[b].push_back(a);
	}
	while (m--) {
		cin >> x >> y;
		bonus[x] += y;
	}
	q.push(1);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		for (auto i : g[u]) {
			bonus[i] += bonus[u];
			q.push(i);
		}
	}
	for (int i = 1; i <= n; i++) cout << bonus[i] << "\n";
    return 0;
}