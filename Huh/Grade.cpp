#include <bits/stdc++.h>
using namespace std;

int main() {
	int n, credit, score, sum=0, total=0;
	string s;
	cin >> s >> n;
	for (int i = 0; i < n; i++) {
		cin >> s >> credit >> score;
		total += credit;
		if (score > 90) printf("A\n"), sum += 4*credit;
		else if (score > 80) printf("B\n"), sum += 3*credit;
		else if (score > 70) printf("C\n"), sum += 2*credit;
		else if (score > 60) printf("D\n"), sum += credit;
		else printf("F\n");
	}
	printf("%.1lf", (double)sum/(double)total);
	return 0;
}
