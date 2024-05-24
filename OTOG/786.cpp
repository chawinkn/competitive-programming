#include <bits/stdc++.h>
using namespace std;

const int MX_N = 1e6+9;
int arr[MX_N];

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m, a;
    cin >> n >> m;
    int mx=0;
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        mx = max(mx, arr[i]);
    }
    while (m--) {
        cin >> a;
        int ans=a/mx;
        if (a%mx != 0) ans++;
        cout << ans << "\n";
    }
    return 0;
}
