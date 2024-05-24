#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second
#define ll long long

pair<ll,ll> arr[100009]; // t w

bool cmp(pair<ll,ll> a, pair<ll,ll> b) {
    return a.s*b.f >= b.s*a.f;
}

int main() {
    int n;
    ll T=0, ans=0;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> arr[i].f >> arr[i].s;
    sort(arr, arr+n, cmp);
    for (int i = 0; i < n; i++) {
        T += arr[i].f;
        ans += arr[i].s*T;
    }
    cout << ans;
    return 0;
}