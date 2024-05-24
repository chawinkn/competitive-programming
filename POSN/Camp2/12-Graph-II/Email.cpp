#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int main() {
    int N, n, m, s, t, u, v, w;
    cin >> N;
    for (int c = 1; c <= N; c++) {
        cin >> n >> m >> s >> t;
        vector<pair<int,int>> g[n+1];
        vector<int> dist(n+1, INT_MAX);
        int visited[n+1]={0};
        while (m--) {
            cin >> u >> v >> w;
            g[u].push_back({v, w});
            g[v].push_back({u, w});
        }
        priority_queue<pair<int,int>> pq;
        dist[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            int u=pq.top().s;
            pq.pop();
            if (visited[u]) continue;
            visited[u] = 1;
            for (auto i : g[u]) {
                int v=i.f, w=i.s;
                if (dist[u]+w < dist[v]) {
                    dist[v] = dist[u]+w;
                    pq.push({-dist[v], v});
                }
            }
        }
        cout << "Case #" << c << ": ";
        if (dist[t] != INT_MAX) cout << dist[t];
        else cout << "unreachable";
        cout << "\n";
    }
    return 0;
}