#include <bits/stdc++.h>
using namespace std;

#define ll long long

int g[1000009], a[1000009], in[1000009];
bool visited[1000009];
vector<int> temp, cycle;
queue<int> q;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, s;
	ll m;
	cin >> n >> m >> s;
	for (int i = 1; i <= n; i++) cin >> a[i];
	int u=s;
	while (!visited[u]) {
		visited[u] = true;
		int v=u+a[u];
		g[u] = v;
		in[v]++;
		u = v;
	}
	q.push(s);
	while (!q.empty()) {
		int u=q.front(); q.pop();
		temp.push_back(u);
		int v=g[u];
		in[v]--;
		if (!in[v]) q.push(v);
	}
	// for (auto i : temp) cout << i << " ";
	memset(visited, false, sizeof(visited));
	u = g[temp[temp.size()-1]];
	while (!visited[u]) {
		visited[u] = true;
		int v=g[u];
		cycle.push_back(u);
		u = v;
	}
	// cout << "\n";
	// for (auto i : cycle) cout << i << " ";
	if (m <= (ll)temp.size()) cout << temp[m-1];
	else cout << cycle[(m-(ll)temp.size())%((ll)cycle.size())];
	return 0;
}