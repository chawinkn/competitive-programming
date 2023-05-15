#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

pair<int,int> arr[100001];
vector<pair<int,int>> ans;

int main() {
    int n, h, k, cnt;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> h >> k;
        arr[i].f = -h;
        arr[i].s = k;
    }
    sort(arr, arr+n);
    for (int i = 0; i < n; i++) {
        k = arr[i].s;
        ans.insert(ans.begin()+k, arr[i]);
    }
    for (auto i : ans) cout << -i.f << " " << i.s << "\n";
}
