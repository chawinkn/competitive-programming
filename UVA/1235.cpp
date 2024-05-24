#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int parent[10003];

int calWeight(string u, string v) {
    int w=0, a=0, b=0;
    for (int i = 0; i < u.length(); i++) {
        a = u[i]-'0';
        b = v[i]-'0';
        w += min(10-abs(a-b), abs(a-b));
    }
    return w;
}

int find(int u) {
    if (parent[u] == u) return u;
    return parent[u] = find(parent[u]);
}

void merge(int u, int v) {
    u = find(u);
    v = find(v);
    if (u != v) parent[u] = v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int N, n;
    string num;
    cin >> N;
    while (N--) {
        cin >> n;
        vector<pair<int,pair<string,string>>> g;
        vector<string> temp;
        while (n--) {
            cin >> num;
            temp.push_back(num);
        }
        int m=temp.size();
        for (int i = 0; i < m; i++) {
            for (int j = i+1; j < m; j++) {
               g.push_back({calWeight(temp[i], temp[j]), {temp[i], temp[j]}});
            }
        }
        sort(g.begin(), g.end());
        // for (auto i : g) cout << i.s.f << " -> " << i.s.s << " : " << i.f << "\n";
        for (int i = 0; i <= 10000; i++) parent[i] = i;
        int ans=0;
        for (auto i : g) {
            int w=i.f, u=0, v=0;
            string uu=i.s.f, vv=i.s.s;
            for (int i = 0; i < uu.length(); i++) {
                u *= 10; v *= 10;
                u += uu[i]-'0'; v += vv[i]-'0';
            }
            if (find(u) == find(v)) continue;
            merge(u, v);
            ans += w;
        }
        m=INT_MAX;
        for (auto i : temp) m = min(m, calWeight("0000", i));
        cout << ans+m << "\n";
    }
    return 0;
}