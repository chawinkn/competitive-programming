#include <bits/stdc++.h>
using namespace std;

string text, pattern, temp;
vector<string> arr, ans;
long long int base=67, d, h, sum;

bool cmp_great(string a, string b) {
    return a.length() > b.length();
}

bool cmp_less(string a, string b) {
    return a.length() < b.length();
}

int main() {
    int N, n, m;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> temp;
        arr.push_back(temp);
    }
    sort(arr.begin(), arr.end(), cmp_great);

    text = arr[0];
    n = text.length();
    for (auto i : arr) {
        pattern = i;
        m = pattern.length();
        d = 1;
        h = 0;
        sum = 0;
        for (int j = m-1; j >= 0; j--) {
            h += d*(pattern[j]-'a');
            sum += d*(text[j]-'a');
            d *= base;
        }
        d /= base;
        int found = 0;
        if (h == sum) {
            ans.push_back(pattern);
            continue;
        }
        for (int j = 1; j <= n-m; j++) {
            sum -= d*(text[j-1]-'a');
            sum *= base;
            sum += text[j+m-1]-'a';
            if (h == sum) {
                ans.push_back(pattern);
                found = 1;
                break;
            }
        }
        if (!found) {
            cout << "NO";
            return 0;
        }
    }
    sort(ans.begin(), ans.end(), cmp_less);
    cout << "YES\n";
    for (auto i : ans) cout << i << "\n";
    return 0;
}