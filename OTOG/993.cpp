#include <bits/stdc++.h>
using namespace std;

// 40/100

double x[19], y[19];
bool visited[19];
double dp[(1<<19)+9];

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%lf %lf", &x[i], &y[i]);
	double ANS=0;
	for (int start = 0; start < n; start++) {
		vector<int> v(n);
		for (int i = 0; i < n; i++) v[i] = i;
		vector<int> temp;
		int u=start, cnt=0;
		memset(visited, false, sizeof(visited));
		visited[u] = true;
		temp.push_back(u);
		double ans=0;
		while (true) {
			bool allVisited=true;
			for (int i = 0; i < n; i++) {
				if (!visited[i]) allVisited = false;
			}
			if (allVisited) break;
			int idx;
			double mx=0;
			for (int i = 0; i < n; i++) {
				if (visited[i]) continue;
				double dist=(x[u]-x[i])*(x[u]-x[i])+(y[u]-y[i])*(y[u]-y[i]);
				if (dist > mx) {
					mx = dist;
					idx = i;
				}
			}
			temp.push_back(idx);
			u = idx;
			visited[u] = true;
			if (temp.size() == 3) {
				double x1=x[temp[0]], y1=y[temp[0]];
				double x2=x[temp[1]], y2=y[temp[1]];
				double x3=x[temp[2]], y3=y[temp[2]];
				ans += abs(x1*y2+x2*y3+x3*y1-x2*y1-x3*y2-x1*y3)/2.0;
				cnt++;
				temp.clear();
				for (int i = 0; i < n; i++) {
					if (!visited[i]) {
						u = i;
						break;
					}
				}
				temp.push_back(u);
				visited[u] = true;
			}
		}
		ANS = max(ANS, ans);
	}
	printf("%.2lf", ANS);
	return 0;
}