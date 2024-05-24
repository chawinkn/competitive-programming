#include <bits/stdc++.h>
using namespace std;

int n, m, ans=INT_MAX, nx, ny, nz, x[13], y[13], z[13], shop[13][5];
int M=0, K=0, C=0;
bool visited[13];

int cal(int v1, int v2) {
	return abs(v2-v1)*abs(v2-v1);	
}

void solve(int sum) {
	if (sum > ans) return;
	if (M >= n && K >= n && C >= n) {
		ans = min(ans, sum);
		return;
	}
	int tx=nx, ty=ny, tz=nz;
	
	for (int i = 1; i <= m; i++) {
		if (visited[i]) continue;
		
		int dist=cal(nx, x[i])+cal(ny, y[i])+cal(nz, z[i]);
		visited[i] = true;
		nx = x[i]; ny = y[i]; nz = z[i];
		M += shop[i][1]; K += shop[i][2]; C += shop[i][3];
		solve(sum+dist);
		M -= shop[i][1]; K -= shop[i][2]; C -= shop[i][3];
		nx = tx; ny = ty; nz = tz;
		visited[i] = false;
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> nx >> ny >> nz >> m;
	for (int i = 1; i <= m; i++) {
		cin >> x[i] >> y[i] >> z[i];
		cin >> shop[i][1] >> shop[i][2] >> shop[i][3];
	}
	solve(0);
	cout << ans;
	return 0;
}
