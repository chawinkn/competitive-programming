#include <bits/stdc++.h>
using namespace std;

// Stack + Shortest path

int h[2000009];
vector<int> g[2000009], dist(2000009, 1e9);
queue<int> Q;
stack<int> st;

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	int s=0;
	for (int i = 1; i <= n; i++) {
		cin >> h[i];
		if (h[i] == 1) s = i;
	}
	for (int i = 1; i <= n; i++) {
		while (!st.empty() && h[i] < h[st.top()]) {
			g[i].push_back(st.top());
			st.pop();
		}
		st.push(i);
		// int j=i-1;
		// while (j >= 1) {
		// 	if (h[j] < h[i]) {
		// 		g[j].push_back(i);
		// 		break;
		// 	}
		// 	j--;
		// }
		// j = i+1;
		// while (j <= n) {
		// 	if (h[j] < h[i]) {
		// 		g[j].push_back(i);
		// 		break;
		// 	}
		// 	j++;
		// }
	}
	for (int i = n; i >= 1; i--) {
		while (!st.empty() && h[i] < h[st.top()]) {
			g[i].push_back(st.top());
			st.pop();
		}
		st.push(i);
	}
	dist[s] = 0;
	Q.push(s);
	while (!Q.empty()) {
		auto u=Q.front(); Q.pop();
		for (auto v : g[u]) {
			if (dist[u]+1 < dist[v]) {
				dist[v] = dist[u]+1;
				Q.push(v);
			}
		}
	}
	while (q--) {
		int k;
		cin >> k;
		cout << dist[k] << "\n";
	}
	return 0;
}