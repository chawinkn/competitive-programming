#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define l 27

string station="XabcdefghijklmnopqrstuvwxyzY";

vector<pair<int,double>> g[29];
vector<pair<pair<int,int>,double>> temp;
bool visited[29];

// 90/100 Signal Error

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int n, u, v;
	double c, ans=0;
	cin >> n;
	while (n--) {
		vector<char> temp(2);
		cin >> temp[0] >> temp[1] >> c;
		sort(temp.begin(), temp.end());
		u=temp[0]-'a'+1, v=temp[1]-'a'+1;
		if (temp[0] == 'X') u = 0;
		else if (temp[0] == 'Y') u = l;	
		g[u].push_back({v, c});
		g[v].push_back({u, c});
	}
	u = 0;
	while (u != l) {
		if (visited[u]) continue;
		visited[u] = true;
		vector<double> cost;
		int uu=u, k;
		double med=0;
		for (auto i : g[uu]) {
			if (visited[i.f]) continue;
			u = i.f;
			cost.push_back(i.s);
		}
		k = cost.size();
		if (k == 0) {
			cout << "broken";
			return 0;
		}
		sort(cost.begin(), cost.end());
		if (k%2 == 0) med = (cost[k/2]+cost[k/2-1])/2;
		else med = cost[k/2];
		temp.push_back({{uu, u}, med});
		ans += med;
	}
	for (auto i : temp) printf("%c %c %.1lf\n", station[i.f.f], station[i.f.s], i.s);
	printf("%.1lf", ans);
	return 0;
}
