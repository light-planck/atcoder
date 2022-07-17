#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()
using ll = long long;

int main() {
  cin.tie(nullptr);
  ios::sync_with_stdio(false);

  string s;
  cin >> s;
  int n = s.size();
  int max_k = log2(n) + 10;

  vector<vector<int>> db(max_k, vector<int>(n));
  rep(i, n) {
    if (s[i] == 'R') {
      db[0][i] = i + 1;
    }
    else {
      db[0][i] = i - 1;
    }
  }
  rep(i, max_k - 1) {
    rep(j, n) {
      db[i + 1][j] = db[i][db[i][j]];
    }
  }

  vector<int> cnt(n);
  rep(i, n) ++cnt[db[max_k - 1][i]];

  for (auto x : cnt) {
    cout << x << " ";
  }
  cout << "\n";
  return 0;
}