#include <bits/stdc++.h>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int now=0, cost=0;
    now = cost = a[0]+a[1];
    for (int i = 2; i < n; i++) {
        now += a[i];
        cost += a[i];
    }
    cout << cost;
    return 0;
}