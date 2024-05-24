#include <bits/stdc++.h>
using namespace std;

void kmp(string s, string p) {
	int n=s.length(), m=p.length();
	vector<int> lps(m); // Longest Prefix Suffix s[0..x] = s[n-x-1..n-1]
	// i : current
	// j : previous LPS
	int i=1, j=0;
	while (i < m) {
		if (p[i] == p[j]) {
			lps[i] = j+1;
			i++, j++;
		}
		else if (j == 0) i++;
		else j = lps[j-1];
	}
	// i : string
	// j : pattern
	i=0, j=0;
	while (i < n) {
		if (s[i] == p[j]) {
			i++, j++;
		}
		else if (j == 0) i++;	
		else j = lps[j-1];
		if (j == m) {
			cout << "Found at " << i-m << "!\n";
		}
	}
}

void rabinkarp(string s, string p) {
	int n=s.length(), m=p.length();
	long long base=98765431, b=1, hs=0, hp=0;
	for (int i = m-1; i >= 0; i--) {
		hs += s[i]*b;
		hp += p[i]*b;
		if (i > 0) b *= base;
	}
	for (int i = 0; i <= n-m; i++) {
		if (hs == hp) {
			if (s.substr(i, m) == p) {
				cout << "Found at " << i << "!\n";
			}
		}
		hs -= s[i]*b; 
		hs *= base; 
		hs += s[i+m];
	}
}

int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL);
	string s, p;
	cin >> s >> p;
	kmp(s, p);
	cout << "\n";
	rabinkarp(s, p);
	return 0;
}