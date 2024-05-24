#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, r;
    float ans=1;
    cin >> n;
    r = n/2;
    // C(n, r)
    for (int i = n; i > n-(n/2); i--) {
        ans *= i;
        ans /= r;
        r--;
    }
    if (n%2 == 0) {
        // n = 6 -> (3, 3)
        printf("%.0f", ans);
    }
    else {
        // n = 7 -> (3, 4), (4, 3)
        printf("%.0f", ans*2);
    }
    return 0;
}
