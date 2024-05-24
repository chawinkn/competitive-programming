#include <bits/stdc++.h>
using namespace std;

vector<int> g[100003], dist(100003, INT_MAX);
int visited[100003];

int main() {
    int V, e, v, w;
    cin >> V >> e;
    while (e--) {
        cin >> v >> w;
        g[v].push_back(w);
        g[w].push_back(v);
    }
    queue<int> q;
    dist[0] = 0;
    q.push(0);
    while (!q.empty()) {
        int u=q.front();
        q.pop();
        if (visited[u]) continue;
        visited[u] = 1;
        for (auto i : g[u]) {
            if (dist[u]+1 < dist[i]) {
                dist[i] = dist[u]+1;
                q.push(i);
            }
        }
    }
    vector<pair<int,int>> ans;
    for (int i = 1; i < V; i++) ans.push_back({dist[i], i});
    sort(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i].second << " ";
        if (ans[i].first != ans[i+1].first) cout << "\n";
    }
    return 0;
}