#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[503];
vector<int> dist(503, INT_MAX);
int visited[503];

int main() {
    int n, m, u, v, w;
    cin >> n >> m;
    while (m--) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
    }
    priority_queue<pair<int,int>> pq;
    dist[1] = 0;
    pq.push({0, 1});
    while (!pq.empty()) {
        int u=pq.top().second;
        pq.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto i : g[u]) {
            int v=i.first, w=i.second;
            if (dist[u]+w < dist[v]) {
                dist[v] = dist[u]+w;
                pq.push({-dist[v], v});
            }
        }
    }
    for (int i = 1; i <= n; i++) {
        if (dist[i] != INT_MAX) cout << dist[i];
        else cout << -1;
        cout << "\n";
    }
    return 0;
}