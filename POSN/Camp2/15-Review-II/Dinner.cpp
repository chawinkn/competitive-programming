#include <bits/stdc++.h>
using namespace std;

int arr[207], v[107];

int main() {
    int n, ans=0;
    cin >> n;
    for (int i = 0; i < 2*n; i++) cin >> arr[i];
    for (int i = 0; i < 2*n; i++) {
        if (!v[arr[i]]) {
            v[arr[i]] = 1;
            int cnt = 0;
            for (int j = i+1; j < 2*n; j++) {
                if (!v[arr[j]]) cnt++;
                if (arr[i] == arr[j]) {
                    ans += cnt;
                    break;
                }
            }
        }
    }
    cout << ans;
    return 0;
}
