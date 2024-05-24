#include <bits/stdc++.h>
using namespace std;

vector<pair<int,int>> g[300001];
priority_queue<pair<int,int>> pq;
map<int,vector<int>> mp;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, k, q, s, x, t, u, v, w;
    cin >> n >> m >> k >> q;
    while (m--) {
        cin >> u >> v >> w;
        g[u].push_back({v, w});
        g[v].push_back({u, w});
    }
    for (int i = 0; i < k; i++) {
        cin >> s;
        vector<int> dist(n, INT_MAX);
        dist[s] = 0;
        pq.push({-dist[s], s});
        while (!pq.empty()) {
            u=pq.top().s; pq.pop();
            for (auto i : g[u]) {
                v=i.f, w=i.s;
                if (dist[u]+w < dist[v]) {
                    dist[v] = dist[u]+w;
                    pq.push({-dist[v], v});
                }
            }
        }
        mp[s] = dist;
    }
    while (q--) {
        cin >> s >> x >> t;
        cout << mp[x][s]+mp[x][t] << "\n";
    }
    return 0;
}