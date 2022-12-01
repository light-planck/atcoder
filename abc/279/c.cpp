#include <bits/stdc++.h>
#define rep(i, n) for (long long i = 0; i < (long long)(n); ++i)
using namespace std;
using ll = long long;


int main() {
  ll h, w;
  cin >> h >> w;

  vector<string> s(h);
  rep(i, h) cin >> s[i];

  vector<string> t(h);
  rep(i, h) cin >> t[i];

  auto convert = [&](vector<string> grid) {
    vector<string> res;
    rep(j, w) {
      string col = "";
      rep(i, h) {
        col += grid[i][j];
      }
      res.emplace_back(col);
    }
    sort(res.begin(), res.end());
    return res;
  };

  if (convert(s) == convert(t)) cout << "Yes" << '\n';
  else cout << "No" << '\n';
  return 0;
}