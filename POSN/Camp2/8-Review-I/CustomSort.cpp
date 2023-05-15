#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

string order, str, ans="";

int main() {
    cin >> order >> str;
    for (int i = 0; i < order.length(); i++) {
        for (int j = 0; j < str.length(); j++) {
            if (order[i] == str[j]) {
                ans += order[i];
                str[j] = 123;
            }
        }
    }
    sort(str.begin(), str.end());
    int i = 0;
    while (ans.length() < str.length()) {
        ans += str[i];
        i++;
    }
    cout << ans;
    return 0;
}
