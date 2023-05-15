#include <iostream>
#include <vector>
#include <bitset>
using namespace std;

bitset<12> b;
vector<int> ans1, ans2;

int main() {
    int n;
    for (int i = 0; i < 30; i++) {
        cin >> b;
        n = b.count();
        if (n == 12) ans1.push_back(i);
        else if (n < 8) ans2.push_back(i);
    }
    cout << ans1.size();
    for (auto i : ans1) cout << " " << i;
    cout << "\n";
    cout << ans2.size();
    for (auto i : ans2) cout << " " << i;
    return 0;
}
