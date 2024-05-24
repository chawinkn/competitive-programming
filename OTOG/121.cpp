#include <bits/stdc++.h>
using namespace std;

const int MAX_N = 2e5+9;
int n, tree[2*MAX_N];

int query(int l, int r) {
    int sum = 0;
    for (l += n, r += n+1; l < r; l/=2, r/=2) {
        if (l&1) sum += tree[l++];
        if (r&1) sum += tree[--r];
    }
    return sum;
}

void update(int i, int v) {
    tree[i+=n] += v;
    for (i /= 2; i >= 1; i/=2) tree[i] = tree[2*i] + tree[2*i+1];
}

int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int m, a, b, c, d, e;
    cin >> n >> m;
    while (m--) {
        cin >> a;
        if (a == 1) {
            cin >> b >> c;
            update(c, b);
        }
        else {
            cin >> d >> e;
            cout << query(d, e) << "\n";
        } 
    }
    return 0;
}