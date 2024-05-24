#include <bits/stdc++.h>
using namespace std;
 
// 100/100

vector<int> dist(50009, 1e9), line[50009], g[50009];
int cost[50009];
bool visited[50009], used[50009];
 
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int k, x;
		cin >> k >> x;
		cost[i] = x;
		for (int j = 0; j < k; j++) {
			int u;
			cin >> u;
			g[i].push_back(u);
			line[u].push_back(i);	
		}
	}
	dist[0] = 0;
	priority_queue<pair<int,int>> pq;
	pq.push({0, 0});
	while (!pq.empty()) {
		auto [d,u]=pq.top(); pq.pop();
		if (visited[u]) continue;
		visited[u] = true;
		for (auto i : line[u]) {
			if (used[i]) continue;
			used[i] = true;
			for (auto v : g[i]) {
				if (dist[u]+cost[i] < dist[v]) {
					dist[v] = dist[u]+cost[i];
					pq.push({-dist[v], v});
				}
			}
		}
 	}
 	cout << (dist[n-1] != 1e9 ? dist[n-1] : -1);
	return 0;
}

//#include <bits/stdc++.h>
//using namespace std;
//
//vector<int> dist(100009, 1e9);
//vector<pair<int,int>> g[100009];
//bool visited[100009];
//
//// 100/100 (from P'Beam)
//
//int main() {
//	ios_base::sync_with_stdio(false); cin.tie(NULL);
//	int n, m;
//	cin >> n >> m;
//	for (int i = 0; i < m; i++) {
//		int k, x;
//		cin >> k >> x;
//		for (int j = 0; j < k; j++) {
//			int u;
//			cin >> u;
//			g[u].push_back({n+i, x});
//			g[n+i].push_back({u, x});
//		}
//	}
//	dist[0] = 0;
//	priority_queue<pair<int,int>> pq;
//	pq.push({0, 0});
//	while (!pq.empty()) {
//		auto [d,u]=pq.top(); pq.pop();
//		if (visited[u]) continue;
//		visited[u] = true;
//		for (auto [v,w] : g[u]) {
//			if (dist[u]+w < dist[v]) {
//				dist[v] = dist[u]+w;
//				pq.push({-dist[v], v});
//			}
//		}
//	}
//	cout << (dist[n-1] != 1e9 ? dist[n-1]/2 : -1);
//	return 0;
//}