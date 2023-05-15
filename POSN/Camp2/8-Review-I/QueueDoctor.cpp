#include <iostream>
#include <queue>
using namespace std;

priority_queue<pair<int,int>> pq;

int main() {
    int n, t, h, i=1;
    cin >> n;
    while (n--) {
        cin >> t;
        if (t == 1) {
            cin >> h;
            pq.push({h, -i});
            i++;
        }
        else {
            cout << -pq.top().second << "\n";
            pq.pop();
        }
    }
    return 0;
}
