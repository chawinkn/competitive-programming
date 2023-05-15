#include <bits/stdc++.h>
using namespace std;

int a[100003], b[100003];

// 9/100 points

int main() {
    ios_base::sync_with_stdio(0); cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] += a[i-1];
    }
    for (int i = 1; i <= n; i++) {
        cin >> b[i];
        b[i] += b[i-1];
    }
    priority_queue<float> pq;
    int x=0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            pq.push((float)(a[j]-a[i-1])/(float)(b[j]-b[i-1]));
        }
    }
    while (k > 1 && !pq.empty()) {
        pq.pop();
        k--;
    }
    string ans=to_string(pq.top());
    for (int i = 0; i < ans.length()-3; i++) cout << ans[i];
    return 0; 
}