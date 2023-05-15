#include <bits/stdc++.h>
using namespace std;

vector<int> g[200003];
priority_queue<int> dist[29];
int c[200003];
bool visited[200003];

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, m, k, u, v;
    string word;
    cin >> n >> m >> k;
    for (int i = 1; i <= n; i++) {
        char in;
        cin >> in;
        c[i] = in-'A';
    }
    while (m--) {
        cin >> u >> v;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    queue<pair<int,int>> q;
    q.push({1, 0});
    visited[1] = true;
    dist[c[1]].push(0);
    while (!q.empty()) {
        int u=q.front().first, d=q.front().second;
        q.pop();
        for (auto i : g[u]) {
            if (visited[i]) continue;
            visited[i] = true;
            dist[c[i]].push(-2*(d+1));
            q.push({i, d+1});
        }
    }
    long long int ans=0;
    cin >> word;
    for (auto i : word) {
        if (dist[i-'A'].empty()) {
            cout << -1;
            return 0;
        }
        ans += dist[i-'A'].top();
        dist[i-'A'].pop();
    }
    cout << -ans;
    return 0;
}