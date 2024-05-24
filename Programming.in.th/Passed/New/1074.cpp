#include <bits/stdc++.h>
using namespace std;

int n, m, ai, aj;
char arr[109][109];

// ลอกมา ::skull::

void find1() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] == '.') continue;
			int sz=1;
			while (arr[i+sz][j] == 'x' && arr[i][j+sz] == 'x') sz++;
			ai = i;
			aj = j;
			cout << i << " " << j << " " << sz << "\n";
			for (int y = i; y < i+sz; y++) {
				for (int x = j; x < j+sz; x++) arr[y][x] = '.';
			}
			return;
		}                           			
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) cin >> arr[i][j];
	}
	find1();
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			if (arr[i][j] == '.') continue;
			int sz=1;
			while (arr[i-sz][j] == 'x' || arr[i][j-sz] == 'x') sz++;
			cout << max(1, i-sz+1) << " " << max(1, j-sz+1) << " " << sz << "\n";
			return 0;
		}                           			
	}
	cout << ai << " " << aj << " 1";
	return 0;                    
}
