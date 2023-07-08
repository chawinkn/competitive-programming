// I think it's correct but I got 50/100 Bruh

#include <bits/stdc++.h>
using namespace std;

#define f first
#define s second

int dx[8]={-1,-1,0,1,1,1,0,-1}, dy[8]={0,-1,-1,-1,0,1,1,1};
char arr[27][27];
map<char, vector<pair<int,int>>> mp;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);
  int m, n, k;
  cin >> m >> n;
  for (int i = 0; i < m; i++) {
    for (int j = 0; j < n; j++) {
      cin >> arr[i][j];
      if (isupper(arr[i][j])) arr[i][j] = tolower(arr[i][j]);
      if (mp.find(arr[i][j]) == mp.end()) {
        vector<pair<int,int>> temp;
        temp.push_back({i, j});
        mp[arr[i][j]] = temp;
      }
      else mp[arr[i][j]].push_back({i, j});
    }
  }
  // for (auto i : mp) {
  //   cout << i.f << "  ";
  //   for (auto j : i.s) {
  //     cout << "(" << j.f << ", " << j.s << ") ";
  //   }
  //   cout << "\n";
  // }
  cin >> k;
  while (k--) {
    string word;
    cin >> word;
    int len=word.length();
    for (int i = 0; i < len; i++) {
      if (isupper(word[i])) word[i] = tolower(word[i]);
    }
    bool founded=false;
    for (auto i : mp[word[0]]) {
      queue<pair<int, pair<int,int>>> q;
      vector<vector<bool>> visited(27, vector<bool>(27, false));

      q.push({0, {i.f, i.s}});
      while (!q.empty()) {
        int idx=q.front().f, y=q.front().s.f, x=q.front().s.s;
        q.pop();
        if (idx >= len) continue;
        if (arr[y][x] != word[idx]) continue;
        if (idx == len-1) {
          cout << i.f << " " << i.s << "\n";
          founded = true;
          break;
        }
        visited[y][x] = true;

        for (int j = 0; j < 8; j++) {
          int yy=y+dy[j], xx=x+dx[j];
          if (yy < 0 || yy >= m || xx < 0 || xx >= n) continue;
          if (visited[yy][xx]) continue;
          q.push({idx+1, {yy, xx}});
        }
      }
      if (founded) break;
    }
  }
  return 0;
}