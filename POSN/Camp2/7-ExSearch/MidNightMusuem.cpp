#include <iostream>
using namespace std;

#define f first
#define s second

pair<int,int> arr[21];

int main() {
    int n, w, W, v, cnt=0;
    double sum=0;
    cin >> n >> W;
    for (int i = 0; i < n; i++) cin >> arr[i].f >> arr[i].s; // weight value
    for (int i = 0; i < (1 << n); i++) {
        w = 0;
        v = 0;
        for (int j = 0; j < n; j++) {
            if (i & (1 << j)) {
                w += arr[j].f;
                v += arr[j].s;
            }
        }
        if (w <= W) {
            sum += v;
            cnt++;
        }
    }
    printf("%.2lf", sum/cnt);
    return 0;
}