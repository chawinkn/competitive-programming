#include <iostream>
#include <algorithm>
using namespace std;

#define f first
#define s second

int arr[9];
pair<pair<int,int>,int> p[21];

int main() {
    int n, m, cnt;
    while (cin >> n >> m) {
        if (n == 0 && m == 0) break;
        for (int i = 0; i < n; i++) arr[i] = i;
        for (int i = 0; i < m; i++) cin >> p[i].f.f >> p[i].f.s >> p[i].s;
        cnt = 0;
        do {
            int check = 1;
            for (int i = 0; i < m; i++) {
                int x=0, y=0;
                for (int j = 0; j < n; j++) {
                    if (arr[j] == p[i].f.f) x = j;
                    else if (arr[j] == p[i].f.s) y = j;
                }
                if (p[i].s > 0 && abs(x-y) <= p[i].s) continue;
                else if (p[i].s < 0 && abs(x-y) >= -p[i].s) continue;
                check = 0;
            }
            if (check) cnt++;
        } while (next_permutation(arr, arr+n));
        cout << cnt << "\n";
    }
    return 0;
}