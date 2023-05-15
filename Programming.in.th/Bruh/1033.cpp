#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int n, k, b[101][101], cnt[5], w=0, m=0;
char t[1001][5], c;
pair<int,int> p[5];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cin >> n >> k;
	p[1] = {1, n}; b[1][n] = 1;
	p[2] = {n, n}; b[n][n] = 2;
	p[3] = {n, 1}; b[n][1] = 3;
	p[4] = {1, 1}; b[1][1] = 4;
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= k; j++) {
			cin >> c;
			t[j][i] = c;
		}
	}
	for (int i = 1; i <= k; i++) {
		int valid = 0;
		for (int j = 1; j <= 4; j++) {
			if (t[i][j] == 'N' && p[j].f-1 >= 1) {
				p[j].f--;
				valid = 1;
			}
			else if (t[i][j] == 'E' && p[j].s+1 <= n) {
				p[j].s++;
				valid = 1;
			}
			else if (t[i][j] == 'W' && p[j].s-1 >= 1) {
				p[j].s--;
				valid = 1;
			}
			else if (t[i][j] == 'S' && p[j].f+1 <= n) {
				p[j].f++;
				valid = 1;
			}
			
			if (valid) b[p[j].f][p[j].s] = j;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
//			cout << b[i][j] << " ";
			cnt[b[i][j]]++;
			if (b[i][j] == 0) {
				cout << "No";
				return 0;
			} 
		}
//		cout << "\n";
	}
	for (int i = 1; i <= 4; i++) m = max(m, cnt[i]);
	for (int i = 1; i <= 4; i++) if (cnt[i] == m) w++;
	cout << w << " " << m << "\n";
	for (int i = 1; i <= 4; i++) if (cnt[i] == m) cout << i << "\n";
	return 0;
}
