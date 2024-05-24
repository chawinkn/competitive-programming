#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> arr[100001];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	
	int n;
	double sum=0;
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i].f >> arr[i].s;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i != j) {
				if (arr[i].f > arr[j].f && arr[i].s < arr[j].s) {
					sum += arr[i].f + arr[j].f;
				}
			}
		}
	}
	printf("%.0lf", sum);
	return 0;
}
