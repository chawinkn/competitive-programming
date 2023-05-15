#include <bits/stdc++.h>
using namespace std;

pair<pair<int,int>,int> arr[100003];
vector<vector<int>> dist(100003, vector<int>(100003, 10e8));

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, u, v, w, k, e, z;
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        cin >> u >> v >> w;
        arr[i] = {{u, v}, w};
        dist[u][v] = w;
        dist[v][u] = w;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < n; k++) {
                dist[i][j] = min(dist[i][j], dist[i][k]+dist[k][j]);
            }
        }
    }
    cin >> k;
    while (k--) {
        cin >> e >> z;
        int w=z-arr[e].second, sum=0;
        // cout << w << "\n";
        for (int i = 0; i <= n-2; i++) {
            for (int j = i+1; j < n; j++) {
                if (j == arr[e].first.second) {
                    dist[i][j] += w;
                    if (i == arr[e].first.first) arr[e] = {{i, j}, dist[i][j]};                }
                sum += dist[i][j];
                // cout << i << "-" << j << " " << dist[i][j] << "\n";
            }
        }
        cout << sum << "\n";
    }
    return 0;
}