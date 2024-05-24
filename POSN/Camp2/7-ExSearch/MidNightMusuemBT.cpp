#include <iostream>
using namespace std;

#define f first
#define s second

int n, W, w=0, v=0, cnt=0;
double sum=0;
pair<int,int> arr[21];

void solve(int i) {
    if (i == n) {
        if (w <= W) {
            sum += v;
            cnt++;
        }
        return;
    }
    solve(i+1); // Not Pick
    w += arr[i].f;
    v += arr[i].s;
    solve(i+1); // Pick
    w -= arr[i].f;
    v -= arr[i].s;
}

int main() {
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> arr[i].f >> arr[i].s; // weight value
    solve(0);
    printf("%.2lf", sum/cnt);
    return 0;
}