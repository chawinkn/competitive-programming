#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    string s;
    cin >> n;
    while (n--) {
        int arr[13];
        char o[23];
        cin >> s;
        m = s.length();
        int i=0, j, k=0;
        while (i < m) {
            if (s[i]!='+'||s[i]!='*') {
                int num=0;
                for (j = i; s[j]!='+'&&s[j]!='*'&&s[j]!='\0' ; j++) {
                    num *= 10;
                    num += s[j]-'0';
                }
                arr[k] = num; o[k] = s[j]; k++; i = j+1;
            }
        }
//        1+ 2* 3* 4+ 5
        stack<int> ss;
        long long int mn=0, mx=1;
        ss.push(arr[0]);
        for (int i = 1; i < k; i++) {
            int t=1, num=arr[i];
            if (o[i-1] == '*') {
                t = ss.top();
                ss.pop();
            }
            ss.push(t*num);
        }
        while (!ss.empty()) {
            mn += ss.top();
            ss.pop();
        }
        ss.push(arr[0]);
        for (int i = 1; i < k; i++) {
            int t=0, num=arr[i];
            if (o[i-1] == '+') {
                t = ss.top();
                ss.pop();
            }
            ss.push(t+num);
        }
        while (!ss.empty()) {
            mx *= ss.top();
            ss.pop();
        }
        cout << mn << " " << mx << "\n";
//        cout << "\n\n";
    }
}
