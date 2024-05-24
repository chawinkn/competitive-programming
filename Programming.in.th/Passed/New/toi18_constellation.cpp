#include <bits/stdc++.h>
using namespace std;

const int M=1e6+3;

int C[609][609], qsl[1509][1509], qsr[1509][1509];
char s[1509][1509];

int main(){
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	int r, c, k;
	cin >> r >> c >> k;
	for (int i = 0; i <= 600; i++) {
		for (int j = 0; j <= i; j++) {
			if (j == 0 || j == i) C[i][j] = 1;
			else C[i][j] = (C[i-1][j-1]+C[i-1][j])%M;
		}
	}
	for (int i = 601; i <= r+600; i++){
		for (int j = 601; j <= c+600; j++){
			cin >> s[i][j];
			if(s[i][j] == '#') qsl[i][j]++, qsr[i][j]++;
		}
	}
	for (int i = 1; i <= 1501; i++) {
		for (int j = 1; j <= 1501; j++) qsl[i][j] += qsl[i-1][j-1], qsr[i][j] += qsr[i-1][j+1];
	}
	int ans = 0;
	for (int sz = 1; sz <= r+c; sz++){
		for (int i = 601; i <= r+600; i++){
			for (int j = 601; j <= c+600; j++){
				int cnt=0;
				cnt+=qsl[i+sz-1][j-1]-qsl[i][j-sz];
				cnt+=qsl[i-1][j+sz-1]-qsl[i-sz][j];
				cnt+=qsr[i+sz][j]-qsr[i-1][j+1+sz];
				cnt+=qsr[i][j-sz]-qsr[i-1-sz][j+1];
				if(cnt >= k) ans += C[cnt][k], ans %= M;
			}
		}
	}
	cout << ans;
}