#include <bits/stdc++.h>
using namespace std;

int cnt1[29], cnt2[29];

int main() {
	int n, q1=0, q2=0;
	string s1, s2;
	cin >> n >> s1 >> s2;
	for (auto i : s1) i == '?' ? q1++ : cnt1[i]++;
	for (auto i : s2) i == '?' ? q2++ : cnt2[i]++;
	int ans=0;
	for (char i = 'a'; i <= 'z'; i++) {
		int mn=min(cnt1[i], cnt2[i]);
		ans += mn;
		cnt1[i] -= mn, cnt2[i] -= mn;
	}
	for (char i = 'a'; i <= 'z'; i++) {
		int mn=min(q1, cnt2[i]);
		ans += mn;
		cnt2[i] -= mn, q1 -= mn;
	}
	for (char i = 'a'; i <= 'z'; i++) {
		int mn=min(q2, cnt1[i]);
		ans += mn;
		cnt1[i] -= mn, q2 -= mn;
	}
	cout << ans+min(q1, q2);
	return 0;
}