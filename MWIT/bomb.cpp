#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> arr[2009];
vector<pair<double,pair<int,int>>> v;
int parent[2009];

int find(int u) {
	if (u == parent[u]) return u;
	return parent[u] = find(parent[u]);
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, m;
	double ans=0;
	cin >> n >> m;
	int cnt=n; // number of components
	for (int i = 0; i < n; i++) {
		cin >> arr[i].f >> arr[i].s;
		parent[i] = i;	
	}
	for (int i = 0; i < n; i++) {
		for (int j = i+1; j < n; j++) {
			double dist=(arr[i].f-arr[j].f)*(arr[i].f-arr[j].f)+(arr[i].s-arr[j].s)*(arr[i].s-arr[j].s);
			v.push_back({dist, {i, j}});
		}
	}
	sort(v.begin(), v.end());
	for (auto i : v) {
		int a=find(i.s.f), b=find(i.s.s);
		if (cnt <= m) break;
		if (a == b) continue;
		cnt--;
		parent[a] = b;
		ans = i.f;
	}
	cout << fixed << setprecision(3) << sqrt(ans);
	return 0;
}

